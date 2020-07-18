/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_box.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 12:10:13 by francis           #+#    #+#             */
/*   Updated: 2020/07/18 11:37:04 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static void	init_pause_rec(t_window *win, t_all_rec *all_rec, int x, int y)
{
	SDL_Rect	run_pause;
	int			h;

	h = win->h * 0.02;
	x = win->w * 0.92;
	y = win->h * 0.94;
	run_pause = init_new_rect(x, y, win->w * 0.05, h);
	all_rec->run_pause = run_pause;
}

void		command_box(t_window *win, t_all_rec *all_rec, int x, int y)
{
	SDL_Rect	command_rec;
	SDL_Rect	up_speed_rec;
	SDL_Rect	down_speed_rec;
	int			h;

	h = win->h * 0.02;
	command_rec = init_new_rect(x, y, win->w * 0.08, h);
	up_speed_rec = init_new_rect(x + 30, y + 30, win->w * 0.10, h);
	down_speed_rec = init_new_rect(x + 30, y + 60, win->w * 0.12, h);
	classic_writing(win, &command_rec, "COMMANDS :");
	classic_writing(win, &up_speed_rec, "Up arrow - Speed Up");
	classic_writing(win, &down_speed_rec, "Down arrow - Speed Down");
	init_pause_rec(win, all_rec, x, y);
}
