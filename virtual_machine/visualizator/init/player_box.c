/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_box.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 19:22:40 by francis           #+#    #+#             */
/*   Updated: 2020/07/17 23:05:48 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static void	player4(t_window *win, t_all_rec *all_rec, int x, int y)
{
	SDL_Rect	name_rec;
	SDL_Rect	process_rec;
	SDL_Rect	live_rec;

	name_rec = init_new_rect(x, y, win->w * 0.06, win->h * 0.02);
	process_rec = init_new_rect(x + 10, y + 30, win->w * 0.04, win->h * 0.015);
	live_rec = init_new_rect(x + 10, y + 60, win->w * 0.04, win->h * 0.015);
	red_writing(win, &name_rec, "Player -4 :");
	red_writing(win, &process_rec, "Processes:");
	red_writing(win, &live_rec, "Last live:");
	player4_input_writing(win, all_rec, x, y);
}

static void	player3(t_window *win, t_all_rec *all_rec, int x, int y)
{
	SDL_Rect	name_rec;
	SDL_Rect	process_rec;
	SDL_Rect	live_rec;

	name_rec = init_new_rect(x, y, win->w * 0.06, win->h * 0.02);
	process_rec = init_new_rect(x + 10, y + 30, win->w * 0.04, win->h * 0.015);
	live_rec = init_new_rect(x + 10, y + 60, win->w * 0.04, win->h * 0.015);
	green_writing(win, &name_rec, "Player -3 :");
	green_writing(win, &process_rec, "Processes:");
	green_writing(win, &live_rec, "Last live:");
	player3_input_writing(win, all_rec, x, y);
}

static void	player2(t_window *win, t_all_rec *all_rec, int x, int y)
{
	SDL_Rect	name_rec;
	SDL_Rect	process_rec;
	SDL_Rect	live_rec;

	name_rec = init_new_rect(x, y, win->w * 0.06, win->h * 0.02);
	process_rec = init_new_rect(x + 10, y + 30, win->w * 0.04, win->h * 0.015);
	live_rec = init_new_rect(x + 10, y + 60, win->w * 0.04, win->h * 0.015);
	blue_writing(win, &name_rec, "Player -2 :");
	blue_writing(win, &process_rec, "Processes:");
	blue_writing(win, &live_rec, "Last live:");
	player2_input_writing(win, all_rec, x, y);
}

static void	player1(t_window *win, t_all_rec *all_rec, int x, int y)
{
	SDL_Rect	name_rec;
	SDL_Rect	process_rec;
	SDL_Rect	live_rec;

	name_rec = init_new_rect(x, y, win->w * 0.06, win->h * 0.02);
	process_rec = init_new_rect(x + 10, y + 30, win->w * 0.04, win->h * 0.015);
	live_rec = init_new_rect(x + 10, y + 60, win->w * 0.04, win->h * 0.015);
	purple_writing(win, &name_rec, "Player -1 :");
	purple_writing(win, &process_rec, "Processes:");
	purple_writing(win, &live_rec, "Last live:");
	player1_input_writing(win, all_rec, x, y);
}

void	player_box(t_vm *vm, t_window *win, t_all_rec *all_rec, int x, int y)
{
	uint8_t	nb_of_player;

	nb_of_player = vm->nb_of_player_alive;
	if (nb_of_player >= 1)
	{
		player1(win, all_rec, x, y);
		purple_writing(win, &all_rec->name1, vm->all_players[0]->name->str);
	}
	if (nb_of_player >= 2)
	{
		player2(win, all_rec, x, y + 100);
		blue_writing(win, &all_rec->name2, vm->all_players[1]->name->str);
	}
	if (nb_of_player >= 3)
	{
		player3(win, all_rec, x, y + 200);
		green_writing(win, &all_rec->name3, vm->all_players[2]->name->str);
	}
	if (nb_of_player >= 4)
	{
		player4(win, all_rec, x, y + 300);
		red_writing(win, &all_rec->name4, vm->all_players[3]->name->str);
	}
}
