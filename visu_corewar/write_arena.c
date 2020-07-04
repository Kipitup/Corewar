/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_arena.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 09:19:26 by francis           #+#    #+#             */
/*   Updated: 2020/07/04 12:06:21 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int8_t	write_init_arena(t_window *win)
{
	SDL_Point	point;
	SDL_Rect	rec;
	int			count;

	point = set_point(8, 8);
	count = 0;
	while (count < MEM_SIZE)
	{
		rec = init_new_rect(point.x, point.y, win->w * 0.009, win->h * 0.015);
		draw_rectangle(win, rec, set_color(20, 20, 20, 255));
		classic_writing(win, &rec, "00");
		point.x = point.x + win->w * 0.012;
		if ((count + 1) % 64 == 0 && count != 0)
		{
			point.y = point.y + win->h * 0.016;
			point.x = 8;
		}
		count++;
	}
	return (SUCCESS);
}
