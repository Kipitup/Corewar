/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:38:45 by amartinod         #+#    #+#             */
/*   Updated: 2020/07/18 18:24:57 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "visu.h"

static void			remove_cursor(t_vm *vm)
{
	t_cursor	*cursor;
	t_cursor	*tmp;
	size_t		last_live;

	if (vm->cursor == NULL)
		return ;
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
	t_cursor		*tmp;
	uint8_t			player[5];
	uint8_t			alive;

	alive = 0;
	remove_cursor(vm);
	tmp = vm->cursor;
	ft_bzero(&(player), 5);
	while (tmp != NULL)
	{
		if (player[tmp->id] == 0)
		{
			alive++;
			player[tmp->id] = tmp->id;
		}
		tmp = tmp->next;
	}
	return (alive);
}

static uint8_t		check(t_vm *vm)
{
	uint8_t		alive;

	if (vm->live_counter >= NBR_LIVE)
	{
		vm->live_counter = 0;
		vm->check_counter = 0;
		vm->cycle_to_die -= CYCLE_DELTA;
	}
	else
		vm->check_counter++;
	if (vm->check_counter >= MAX_CHECKS)
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
	t_window	win;
	long		cycle;

	cycle = 0;
	setup_window(vm, &win);
	while (vm->nb_of_player_alive > 0)
	{
		if (vm->option & OPT_DUMP && vm->opt_dump == vm->cycle_counter)
		{
			dump_option(vm);
			break ;
		}
		lets_fight(vm, vm->cursor);
		run_visu(vm, &win);
		if (vm->option & OPT_VISU && win.running == OFF)
			break ;
		cycle++;
		vm->cycle_counter++;
		if (cycle == vm->cycle_to_die)
		{
			cycle = 0;
			vm->nb_of_player_alive = check(vm);
		}
	}
	end_visu(vm, &win);
}
