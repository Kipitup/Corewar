/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   active_zones.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 16:16:21 by francis           #+#    #+#             */
/*   Updated: 2020/07/17 15:00:56 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include "vm.h"

static void	player_rec(t_vm *vm, t_window *win, t_all_rec *all_rec)
{
	(void)vm;
	red_writing(win, &all_rec->player4_process, "itoa(nb)"); 
	red_writing(win, &all_rec->player4_live, "itoa(nb)"); 
	green_writing(win, &all_rec->player3_process, "itoa(nb)"); 
	green_writing(win, &all_rec->player3_live, "itoa(nb)"); 
	blue_writing(win, &all_rec->player2_process, "itoa(nb)"); 
	blue_writing(win, &all_rec->player2_live, "itoa(nb)"); 
	purple_writing(win, &all_rec->player1_process, "itoa(nb)"); 
	purple_writing(win, &all_rec->player1_live, "itoa(nb)"); 
}

static void	info_rec(t_vm *vm, t_window *win, t_all_rec *all_rec)
{
	classic_writing(win, &all_rec->to_die, ft_itoa(vm->cycle_to_die));
}

static void	run_pause_rec(t_window *win, t_all_rec *all_rec)
{
	if (win->play == VISU_START)
		classic_writing(win, &all_rec->run_pause, "running");
	if (win->play == VISU_STOP)
		classic_writing(win, &all_rec->run_pause, "pause...");
}

void		active_zones(t_vm *vm, t_window *win, t_all_rec *all_rec)
{
	run_pause_rec(win, all_rec);
	info_rec(vm, win, all_rec);
	player_rec(vm, win, all_rec);
	active_arena(vm, win);
}
