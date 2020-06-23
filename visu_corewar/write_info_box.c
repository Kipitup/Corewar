/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_info_box.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 20:12:40 by francis           #+#    #+#             */
/*   Updated: 2020/06/21 22:22:11 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static void	info_input_writing(t_window *win, int x, int y)
{
	SDL_Rect	to_die_input;
	SDL_Rect	delta_input;
	SDL_Rect	nb_live_input;
	SDL_Rect	check_input;

	x = x + win->w * 0.10;
	to_die_input = init_new_rect(x, y, win->w * 0.04, win->h * 0.02);
	delta_input = init_new_rect(x, y + 50, win->w * 0.04, win->h * 0.02);
	nb_live_input = init_new_rect(x, y + 100, win->w * 0.04, win->h * 0.02);
	check_input = init_new_rect(x, y + 150, win->w * 0.04, win->h * 0.02);
	draw_rectangle(win, to_die_input, set_color(20, 20, 20, 255));
	draw_rectangle(win, delta_input, set_color(20, 20, 20, 255));
	draw_rectangle(win, nb_live_input, set_color(20, 20, 20, 255));
	draw_rectangle(win, check_input, set_color(20, 20, 20, 255));
	font_writing(win, &to_die_input, "itoa(nb)", 70);
	font_writing(win, &delta_input, "itoa(nb)", 70);
	font_writing(win, &nb_live_input, "itoa(nb)", 70);
	font_writing(win, &check_input, "itoa(nb)", 70);
}

void		write_info_box(t_window *win, int x, int y)
{
	SDL_Rect	to_die_rec;
	SDL_Rect	delta_rec;
	SDL_Rect	nb_live_rec;
	SDL_Rect	check_rec;
	
	to_die_rec = init_new_rect(x, y, win->w * 0.08, win->h * 0.02);
	delta_rec = init_new_rect(x, y + 50, win->w * 0.08, win->h * 0.02);
	nb_live_rec = init_new_rect(x, y + 100, win->w * 0.08, win->h * 0.02);
	check_rec = init_new_rect(x, y + 150, win->w * 0.08, win->h * 0.02);
	draw_rectangle(win, to_die_rec, set_color(20, 20, 20, 255));
	draw_rectangle(win, delta_rec, set_color(20, 20, 20, 255));
	draw_rectangle(win, nb_live_rec, set_color(20, 20, 20, 255));
	draw_rectangle(win, check_rec, set_color(20, 20, 20, 255));
	font_writing(win, &to_die_rec, "CYCLE_TO_DIE:", 70);
	font_writing(win, &delta_rec, "CYCLE_DELTA:", 70);
	font_writing(win, &nb_live_rec, "NBR_LIVES:", 70);
	font_writing(win, &check_rec, "MAX_CHECKS:", 70);
	info_input_writing(win, x, y);
}
