/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:38:45 by amartinod         #+#    #+#             */
/*   Updated: 2020/06/29 19:04:39 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static uint8_t			remove_dead_cursor(t_vm *vm, t_cursor *cursor)
{
	t_cursor	*tmp;
	uint8_t		alive;

	alive = 0;
//	ft_printf("nb alive %zu\n", vm->nb_of_player_alive);
	while (cursor != NULL)
	{
		if (cursor->last_live > (size_t)vm->cycle_to_die)
		{
			ft_printf("ok\n");
			tmp = cursor->next;
			free(cursor);
			cursor = tmp;
			remove_dead_cursor(vm, vm->cursor);
		}
		else
		{
			alive++;
			cursor = cursor->next;
		}
	}
//	ft_printf("nb alive out %zu\n", vm->nb_of_player_alive);
//	alive = vm->nb_of_player_alive;
	return (alive);
}

static uint8_t		check(t_vm *vm)
{
	uint8_t		alive;

	if (vm->live_counter == NBR_LIVE)
	{
		vm->live_counter = 0;
		vm->cycle_to_die -= CYCLE_DELTA;
	}
	else
		vm->check_counter++;
	if (vm->check_counter == MAX_CHECKS)
	{
		vm->check_counter = 0;
		vm->cycle_to_die -= CYCLE_DELTA;
	}
	if (vm->cycle_to_die <= 0)
		alive = 0;
	else
		alive = remove_dead_cursor(vm, vm->cursor);
	return (alive);
}

void				battle(t_vm *vm)
{
	long		cycle;

	cycle = 0;
	while (vm->nb_of_player_alive > 0)
	{
		lets_fight(vm, vm->cursor);
		cycle++;
		vm->cycle_counter++;
		if (cycle == vm->cycle_to_die)
		{
			cycle = 0;
			vm->nb_of_player_alive = check(vm);
	//		ft_dprintf(STD_ERR, "cycle_to_die %ld\n", vm->cycle_to_die);
		}
		if (vm->option & OPT_DUMP && vm->opt_dump == vm->cycle_counter)
		{
			dump_option(vm);
			break;
		}
	}
}
