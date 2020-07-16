/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 14:03:49 by amartinod         #+#    #+#             */
/*   Updated: 2020/06/24 16:40:25 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int8_t	rearrange_player(t_vm *vm, t_player *player,
		size_t position, size_t i)
{
	t_player	*tmp;

	if (position == NO_SPECIFIC_POSITION)
	{
		player->id = i + 1;
		vm->all_players[i] = player;
	}
	else
	{
		tmp = vm->all_players[position - 1];
		vm->all_players[position - 1] = player;
		tmp->id = i + 1;
		vm->all_players[i] = tmp;
	}
	return (SUCCESS);
}

static int8_t	assign_player(t_vm *vm, t_player *player, size_t position)
{
	size_t		i;
	int8_t		ret;

	ret = SUCCESS;
	i = (position == NO_SPECIFIC_POSITION) ? 0 : position - 1;
	if (vm->all_players[i] == NULL)
		vm->all_players[i] = player;
	else
	{
		i = 0;
		while (i < MAX_PLAYERS)
		{
			if (vm->all_players[i] == NULL)
				break;
			i++;
		}
		if (i >= MAX_PLAYERS)
			ret = ft_perror_failure(TOO_MANY_CHAMPS, __FILE__, __LINE__);
		else
			ret = rearrange_player(vm, player, position, i);
	}
	return (ret);
}

static t_player	*get_player_info(t_vector *file, t_player *player)
{
	size_t		start;

	start = sizeof(COREWAR_EXEC_MAGIC);
	player->name = vct_sub(file, start, PROG_NAME_LENGTH);
	start = start + PROG_NAME_LENGTH + EXEC_CODE_SIZE + FILE_PADDING;
	player->comment = vct_sub(file, start, COMMENT_LENGTH);
	start = start + COMMENT_LENGTH + FILE_PADDING;
	player->exec = ft_memalloc(sizeof(uint8_t) * player->size);
	if (player->name == NULL || player->comment == NULL || player->exec == NULL)
	{
		clean_player(&player);
		ft_perror(MALLOC_ERR, __FILE__, __LINE__);
	}
	else
		ft_memcpy(player->exec, file->str + start, player->size);
	return (player);
}

static t_player	*init_player(t_vector *file, size_t position)
{
	t_player		*player;
	uint32_t		magic_nb;
	uint32_t		code_size;

	player = NULL;
	magic_nb = (hexa(file, 0) << 24 | hexa(file, 1) << 16 | hexa(file, 2) << 8
				| hexa(file, 3));
	code_size = (hexa(file, 136) << 24 | hexa(file, 137) << 16
				| hexa(file, 138) << 8 | hexa(file, 139));
	if (magic_nb != COREWAR_EXEC_MAGIC)
		ft_perror(WRONG_MAGIC_NB, __FILE__, __LINE__);
	else if (code_size > CHAMP_MAX_SIZE)
		ft_perror(CODE_TOO_LONG, __FILE__, __LINE__);
	else
	{
		player = ft_memalloc(sizeof(t_player));
		if (player != NULL)
		{
			player->size = code_size;
			player->id = (position == NO_SPECIFIC_POSITION) ? 1 : position;
		}
	}
	return (player);
}

int8_t			parse_file_and_get_info(t_vm *vm, t_vector *name, size_t position)
{
	t_vector		*file;
	t_player		*player;
	int8_t			ret;

	ret = FAILURE;
	file = vct_get_file(vct_getstr(name));
	if (file != NULL)
	{
		if (file->len < MIN_LEN_FILE)
			ft_perror(FILE_TOO_SHORT, __FILE__, __LINE__);
		else
		{
			player = init_player(file, position);
			if (player != NULL)
  				player = get_player_info(file, player);
			if (player != NULL)
				ret = assign_player(vm, player, position);
		}

	}
	return (ret);
}
