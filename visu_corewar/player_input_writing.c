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

void	player4_input_writing(t_window *win, int x, int y)
{
	SDL_Rect	name_input;
	SDL_Rect	processus_input;
	SDL_Rect	last_live_input;

	x = x + win->w * 0.07;
	name_input = init_new_rect(x, y, win->w * 0.10, win->h * 0.02);
	processus_input = init_new_rect(x + 5, y + 30, win->w * 0.04, win->h * 0.015);
	last_live_input = init_new_rect(x + 5, y + 60, win->w * 0.04, win->h * 0.015);
	draw_rectangle(win, name_input, set_color(20, 20, 20, 255));
	draw_rectangle(win, processus_input, set_color(20, 20, 20, 255));
	draw_rectangle(win, last_live_input, set_color(20, 20, 20, 255));
	red_writing(win, &name_input, "name of the player4");
	red_writing(win, &processus_input, "itoa(nb)"); 
	red_writing(win, &last_live_input, "itoa(nb)"); 
}

void	player3_input_writing(t_window *win, int x, int y)
{
	SDL_Rect	name_input;
	SDL_Rect	processus_input;
	SDL_Rect	last_live_input;

	x = x + win->w * 0.07;
	name_input = init_new_rect(x, y, win->w * 0.10, win->h * 0.02);
	processus_input = init_new_rect(x + 5, y + 30, win->w * 0.04, win->h * 0.015);
	last_live_input = init_new_rect(x + 5, y + 60, win->w * 0.04, win->h * 0.015);
	draw_rectangle(win, name_input, set_color(20, 20, 20, 255));
	draw_rectangle(win, processus_input, set_color(20, 20, 20, 255));
	draw_rectangle(win, last_live_input, set_color(20, 20, 20, 255));
	green_writing(win, &name_input, "name of the player3");
	green_writing(win, &processus_input, "itoa(nb)"); 
	green_writing(win, &last_live_input, "itoa(nb)"); 
}

void	player2_input_writing(t_window *win, int x, int y)
{
	SDL_Rect	name_input;
	SDL_Rect	processus_input;
	SDL_Rect	last_live_input;

	x = x + win->w * 0.07;
	name_input = init_new_rect(x, y, win->w * 0.10, win->h * 0.02);
	processus_input = init_new_rect(x + 5, y + 30, win->w * 0.04, win->h * 0.015);
	last_live_input = init_new_rect(x + 5, y + 60, win->w * 0.04, win->h * 0.015);
	draw_rectangle(win, name_input, set_color(20, 20, 20, 255));
	draw_rectangle(win, processus_input, set_color(20, 20, 20, 255));
	draw_rectangle(win, last_live_input, set_color(20, 20, 20, 255));
	blue_writing(win, &name_input, "name of the player2");
	blue_writing(win, &processus_input, "itoa(nb)"); 
	blue_writing(win, &last_live_input, "itoa(nb)"); 
}

void	player1_input_writing(t_window *win, int x, int y)
{
	SDL_Rect	name_input;
	SDL_Rect	processus_input;
	SDL_Rect	last_live_input;
	
	x = x + win->w * 0.07;
	name_input = init_new_rect(x, y, win->w * 0.10, win->h * 0.02);
	processus_input = init_new_rect(x + 5, y + 30, win->w * 0.04, win->h * 0.015);
	last_live_input = init_new_rect(x + 5, y + 60, win->w * 0.04, win->h * 0.015);
	draw_rectangle(win, name_input, set_color(20, 20, 20, 255));
	draw_rectangle(win, processus_input, set_color(20, 20, 20, 255));
	draw_rectangle(win, last_live_input, set_color(20, 20, 20, 255));
	font_writing(win, &name_input, "name of the player1", 70);
	font_writing(win, &processus_input, "itoa(nb)", 70); 
	font_writing(win, &last_live_input, "itoa(nb)", 70); 
}
