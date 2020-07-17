/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 19:22:40 by francis           #+#    #+#             */
/*   Updated: 2020/07/17 10:39:41 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	player4_input_writing(t_window *win, t_all_rec *all_rec, int x, int y)
{
	SDL_Rect	name_input;
	SDL_Rect	process_input;
	SDL_Rect	live_input;

	x = x + win->w * 0.07;
	name_input = init_new_rect(x, y, win->w * 0.05, win->h * 0.02);
	process_input = init_new_rect(x + 5, y + 30, win->w * 0.04, win->h * 0.015);
	live_input = init_new_rect(x + 5, y + 60, win->w * 0.04, win->h * 0.015);
	draw_rectangle(win, name_input, set_color(20, 20, 20, 255));
	draw_rectangle(win, process_input, set_color(20, 20, 20, 255));
	draw_rectangle(win, live_input, set_color(20, 20, 20, 255));
	all_rec->name4 = name_input;
	all_rec->player4_process = process_input;
	all_rec->player4_live = live_input;
}

void	player3_input_writing(t_window *win, t_all_rec *all_rec, int x, int y)
{
	SDL_Rect	name_input;
	SDL_Rect	process_input;
	SDL_Rect	live_input;

	x = x + win->w * 0.07;
	name_input = init_new_rect(x, y, win->w * 0.05, win->h * 0.02);
	process_input = init_new_rect(x + 5, y + 30, win->w * 0.04, win->h * 0.015);
	live_input = init_new_rect(x + 5, y + 60, win->w * 0.04, win->h * 0.015);
	draw_rectangle(win, name_input, set_color(20, 20, 20, 255));
	draw_rectangle(win, process_input, set_color(20, 20, 20, 255));
	draw_rectangle(win, live_input, set_color(20, 20, 20, 255));
	all_rec->name3 = name_input;
	all_rec->player3_process = process_input;
	all_rec->player3_live = live_input;
}

void	player2_input_writing(t_window *win, t_all_rec *all_rec, int x, int y)
{
	SDL_Rect	name_input;
	SDL_Rect	process_input;
	SDL_Rect	live_input;

	x = x + win->w * 0.07;
	name_input = init_new_rect(x, y, win->w * 0.05, win->h * 0.02);
	process_input = init_new_rect(x + 5, y + 30, win->w * 0.04, win->h * 0.015);
	live_input = init_new_rect(x + 5, y + 60, win->w * 0.04, win->h * 0.015);
	draw_rectangle(win, name_input, set_color(20, 20, 20, 255));
	draw_rectangle(win, process_input, set_color(20, 20, 20, 255));
	draw_rectangle(win, live_input, set_color(20, 20, 20, 255));
	all_rec->name2 = name_input;
	all_rec->player2_process = process_input;
	all_rec->player2_live = live_input;
}

void	player1_input_writing(t_window *win, t_all_rec *all_rec, int x, int y)
{
	SDL_Rect	name_input;
	SDL_Rect	process_input;
	SDL_Rect	live_input;
	
	x = x + win->w * 0.07;
	name_input = init_new_rect(x, y, win->w * 0.05, win->h * 0.02);
	process_input = init_new_rect(x + 5, y + 30, win->w * 0.04, win->h * 0.015);
	live_input = init_new_rect(x + 5, y + 60, win->w * 0.04, win->h * 0.015);
	draw_rectangle(win, name_input, set_color(20, 20, 20, 255));
	draw_rectangle(win, process_input, set_color(20, 20, 20, 255));
	draw_rectangle(win, live_input, set_color(20, 20, 20, 255));
	all_rec->name1 = name_input;
	all_rec->player1_process = process_input;
	all_rec->player1_live = live_input;
}
