/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:38:45 by amartinod         #+#    #+#             */
/*   Updated: 2020/07/17 22:08:58 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void			remove_cursor(t_vm *vm)
{
	t_cursor	*cursor;
	t_cursor	*tmp;
	size_t		last_live;

	last_live = vm->cycle_counter - vm->cursor->last_live;
	if (vm->cursor != NULL && last_live > (size_t)vm->cycle_to_die)
	{
		tmp = vm->cursor->next;
		free(vm->cursor);
		vm->cursor = tmp;
		remove_cursor(vm);
	}
	cursor = vm->cursor;
	while (cursor != NULL && cursor->next != NULL)
	{
		last_live = vm->cycle_counter - vm->cursor->next->last_live;
		if (last_live > (size_t)vm->cycle_to_die)
		{
			tmp = cursor->next->next;
			free(cursor->next);
			cursor->next = tmp;
		}
		else
			cursor = cursor->next;
	}
}


static uint8_t		remove_dead_cursor(t_vm *vm)
{
	t_cursor	*tmp;
	uint8_t		alive;

	alive = 0;
	remove_cursor(vm);
	tmp = vm->cursor;
	while (tmp != NULL)
	{
		alive++;
		tmp = tmp->next;
	}
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
		alive = remove_dead_cursor(vm);
	return (alive);
}

void				battle(t_vm *vm)
{
	long		cycle;

	cycle = 0;
	while (vm->nb_of_player_alive > 0)
	{
		if (vm->option & OPT_DUMP && vm->opt_dump == vm->cycle_counter)
		{
			dump_option(vm);
			break;
		}
		lets_fight(vm, vm->cursor);
		cycle++;
		vm->cycle_counter++;
		if (cycle == vm->cycle_to_die)
		{
			cycle = 0;
		ft_dprintf(STD_ERR, "\n{c_red}cycle_to_die %ld{c_end}\n", vm->cycle_to_die);
			vm->nb_of_player_alive = check(vm);
		}
	}
}
