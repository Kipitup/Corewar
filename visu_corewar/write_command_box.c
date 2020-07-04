/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_command_box.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 12:10:13 by francis           #+#    #+#             */
/*   Updated: 2020/07/04 12:29:21 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	write_command_rec(t_window *win, int x, int y)
{
	SDL_Rect	command_rec;
	SDL_Rect	up_speed_rec;
	SDL_Rect	down_speed_rec;

	command_rec = init_new_rect(x, y, win->w * 0.08, win->h* 0.02);
	up_speed_rec = init_new_rect(x + 30, y + 50, win->w * 0.10, win->h* 0.02);
	down_speed_rec = init_new_rect( x + 30, y + 100, win->w * 0.12, win->h* 0.02);
	draw_rectangle(win, command_rec, set_color(20, 20, 20, 255));
	draw_rectangle(win, up_speed_rec, set_color(20, 20, 20, 255));
	draw_rectangle(win, down_speed_rec, set_color(20, 20, 20, 255));
	classic_writing(win, &command_rec, "COMMANDS :");
	classic_writing(win, &up_speed_rec, "Up arrow - Speed Up");
	classic_writing(win, &down_speed_rec, "Down arrow - Speed Down");
}
