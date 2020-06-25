/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 14:03:49 by amartinod         #+#    #+#             */
/*   Updated: 2020/06/25 13:02:17 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int8_t	assign_player(t_vm *vm, t_player *player, size_t index)
{
	int8_t		ret;

	ret = SUCCESS;
	(void)vm;
	(void)player;
	(void)index;
	return (ret);
}

static t_player	*get_player_info(t_vector *file, t_player *player)
{
	(void)file;
	return (player);
}

static t_player	*init_player(t_vector *file, size_t index)
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
			player->id = index + 1;
		}
	}
	return (player);
}

int8_t			parse_file_and_get_info(t_vm *vm, t_vector *name, size_t index)
{
	t_vector		*file;
	t_player		*player;
	int8_t			ret;

	ret = FAILURE;
	file = vct_get_file(vct_getstr(name));
	if (file != NULL)
	{
		player = init_player(file, index);
		if (player != NULL)
  			player = get_player_info(file, player);
		if (player != NULL)
			ret = assign_player(vm, player, index);
	}
	return (ret);
}
