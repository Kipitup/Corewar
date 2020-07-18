/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_box.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 19:22:40 by francis           #+#    #+#             */
/*   Updated: 2020/07/18 11:39:20 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static void	player4(t_window *win, t_all_rec *all_rec, int x, int y)
{
	SDL_Rect	name_rec;

	name_rec = init_new_rect(x, y, win->w * 0.07, win->h * 0.03);
	red_writing(win, &name_rec, "Player -4 :");
	player4_input_writing(win, all_rec, x, y);
}

static void	player3(t_window *win, t_all_rec *all_rec, int x, int y)
{
	SDL_Rect	name_rec;

	name_rec = init_new_rect(x, y, win->w * 0.07, win->h * 0.03);
	green_writing(win, &name_rec, "Player -3 :");
	player3_input_writing(win, all_rec, x, y);
}

static void	player2(t_window *win, t_all_rec *all_rec, int x, int y)
{
	SDL_Rect	name_rec;

	name_rec = init_new_rect(x, y, win->w * 0.07, win->h * 0.03);
	blue_writing(win, &name_rec, "Player -2 :");
	player2_input_writing(win, all_rec, x, y);
}

static void	player1(t_window *win, t_all_rec *all_rec, int x, int y)
{
	SDL_Rect	name_rec;

	name_rec = init_new_rect(x, y, win->w * 0.07, win->h * 0.03);
	purple_writing(win, &name_rec, "Player -1 :");
	player1_input_writing(win, all_rec, x, y);
}

void		player_box(t_vm *vm, t_window *win, t_all_rec *rec, int x, int y)
{
	if (win->nb_of_player >= 1)
	{
		player1(win, rec, x, y);
		purple_writing(win, &rec->name1, vct_getstr(vm->all_players[0]->name));
	}
	if (win->nb_of_player >= 2)
	{
		player2(win, rec, x, y + 100);
		blue_writing(win, &rec->name2, vm->all_players[1]->name->str);
	}
	if (win->nb_of_player >= 3)
	{
		player3(win, rec, x, y + 200);
		green_writing(win, &rec->name3, vm->all_players[2]->name->str);
	}
	if (win->nb_of_player >= 4)
	{
		player4(win, rec, x, y + 300);
		red_writing(win, &rec->name4, vm->all_players[3]->name->str);
	}
}
