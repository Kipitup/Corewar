/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_player_box.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 19:22:40 by francis           #+#    #+#             */
/*   Updated: 2020/06/20 20:24:36 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static void	player4(t_window *win, int x, int y)
{
	SDL_Rect	name_rec;
	SDL_Rect	processus_rec;
	SDL_Rect	last_live_rec;

	name_rec = init_new_rect(x, y, win->w * 0.06, win->h * 0.02);
	processus_rec = init_new_rect(x + 10, y + 30, win->w * 0.04, win->h * 0.015);
	last_live_rec = init_new_rect(x + 10, y + 60, win->w * 0.04, win->h * 0.015);
	draw_rectangle(win, name_rec, set_color(20, 20, 20, 255));
	draw_rectangle(win, processus_rec, set_color(20, 20, 20, 255));
	draw_rectangle(win, last_live_rec, set_color(20, 20, 20, 255));
	red_writing(win, &name_rec, "Player -4 :");
	red_writing(win, &processus_rec, "Processes:");
	red_writing(win, &last_live_rec, "Last live:");
	player4_input_writing(win, x, y);
}

static void	player3(t_window *win, int x, int y)
{
	SDL_Rect	name_rec;
	SDL_Rect	processus_rec;
	SDL_Rect	last_live_rec;

	name_rec = init_new_rect(x, y, win->w * 0.06, win->h * 0.02);
	processus_rec = init_new_rect(x + 10, y + 30, win->w * 0.04, win->h * 0.015);
	last_live_rec = init_new_rect(x + 10, y + 60, win->w * 0.04, win->h * 0.015);
	draw_rectangle(win, name_rec, set_color(20, 20, 20, 255));
	draw_rectangle(win, processus_rec, set_color(20, 20, 20, 255));
	draw_rectangle(win, last_live_rec, set_color(20, 20, 20, 255));
	green_writing(win, &name_rec, "Player -3 :");
	green_writing(win, &processus_rec, "Processes:");
	green_writing(win, &last_live_rec, "Last live:");
	player3_input_writing(win, x, y);
}

static void	player2(t_window *win, int x, int y)
{
	SDL_Rect	name_rec;
	SDL_Rect	processus_rec;
	SDL_Rect	last_live_rec;

	name_rec = init_new_rect(x, y, win->w * 0.06, win->h * 0.02);
	processus_rec = init_new_rect(x + 10, y + 30, win->w * 0.04, win->h * 0.015);
	last_live_rec = init_new_rect(x + 10, y + 60, win->w * 0.04, win->h * 0.015);
	draw_rectangle(win, name_rec, set_color(20, 20, 20, 255));
	draw_rectangle(win, processus_rec, set_color(20, 20, 20, 255));
	draw_rectangle(win, last_live_rec, set_color(20, 20, 20, 255));
	blue_writing(win, &name_rec, "Player -2 :");
	blue_writing(win, &processus_rec, "Processes:");
	blue_writing(win, &last_live_rec, "Last live:");
	player2_input_writing(win, x, y);
}

static void	player1(t_window *win, int x, int y)
{
	SDL_Rect	name_rec;
	SDL_Rect	processus_rec;
	SDL_Rect	last_live_rec;

	name_rec = init_new_rect(x, y, win->w * 0.06, win->h * 0.02);
	processus_rec = init_new_rect(x + 10, y + 30, win->w * 0.04, win->h * 0.015);
	last_live_rec = init_new_rect(x + 10, y + 60, win->w * 0.04, win->h * 0.015);
	draw_rectangle(win, name_rec, set_color(20, 20, 20, 255));
	draw_rectangle(win, processus_rec, set_color(20, 20, 20, 255));
	draw_rectangle(win, last_live_rec, set_color(20, 20, 20, 255));
	font_writing(win, &name_rec, "Player -1 :", 70);
	font_writing(win, &processus_rec, "Processes:", 70);
	font_writing(win, &last_live_rec, "Last live:", 70);
	player1_input_writing(win, x, y);
}

void	write_player_box(t_window *win, int x, int y)
{
	player1(win, x, y);
	player2(win, x, y + 100);
	player3(win, x, y + 200);
	player4(win, x, y + 300);
}
