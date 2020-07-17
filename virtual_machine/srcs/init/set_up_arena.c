/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_arena.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 12:09:56 by amartinod         #+#    #+#             */
/*   Updated: 2020/07/17 17:48:14 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static t_cursor		*init_cursor_and_set_id(t_player *player)
{
	t_cursor	*cursor;

	cursor = ft_memalloc(sizeof(t_cursor));
	if (cursor != NULL)
	{
		cursor->id = player->id;
		cursor->registries[1] = player->id * -1;
	}
	return (cursor);
}

static int8_t		init_cursor(t_vm *vm)
{
	t_cursor	*tmp;
	size_t		i;
	int8_t		ret;

	i = 0;
	ret = SUCCESS;
	while (i < MAX_PLAYERS && ret == SUCCESS)
	{
		if (vm->all_players[i] != NULL)
		{
			tmp = init_cursor_and_set_id(vm->all_players[i]);
			if (tmp == NULL)
				ret = ft_perror_failure(MALLOC_ERR, __FILE__, __LINE__);
			else
			{
				tmp->next = vm->cursor;
				vm->cursor = tmp;
			}
		}
		i++;
	}
	return (ret);
}

static void			set_player_and_cursor_in_arena(t_vm *vm)
{
	size_t		i;
	size_t		space;
	size_t		pc;
	t_player	*player;
	t_cursor	*tmp;

	i = 0;
	space = MEM_SIZE / vm->cursor->id;
	while (i < vm->cursor->id)
	{
		pc = space * i;
		player = vm->all_players[i];
		ft_memcpy(&(vm->arena[pc]), player->exec, player->size);
		ft_memset(&(vm->arena_owner[pc]), player->id, player->size);
		i++;
	}
	tmp = vm->cursor;
	while (tmp != NULL)
	{
		tmp->pc = space * (tmp->id - 1);
		tmp = tmp->next;
	}
}

t_vm				*set_up_arena(t_vm *vm)
{
	int8_t		ret;

	ret = init_cursor(vm);
	if (ret == FAILURE)
		clean_vm(&vm);
	else
	{
		set_player_and_cursor_in_arena(vm);
		vm->cycle_to_die = CYCLE_TO_DIE;
		vm->last_player_alive = vm->cursor->id;
		vm->nb_of_player_alive = vm->cursor->id;
	}
	return (vm);
}
