/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 09:15:55 by francis           #+#    #+#             */
/*   Updated: 2020/06/20 20:21:22 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	draw_header_box(t_window *win)
{
	SDL_Rect	main_rec;
	SDL_Rect	title_rec;
	SDL_Rect	name_rec;
	int			x;
	int			y;

	x = (win->w * 0.75) + 15;
	y = 5;
	main_rec = init_new_rect(x, y, win->w * 0.24, win->h * 0.10);
	title_rec = init_new_rect(x + 5, y + 5, win->w * 0.10, win->h * 0.05);
	name_rec = init_new_rect(x + 5, y + win->h * 0.06, win->w * 0.20, win->h * 0.03);
	draw_rectangle(win, main_rec, set_color(20, 20, 20, 255));
	draw_rectangle(win, title_rec, set_color(20, 20, 20, 255));
	draw_rectangle(win, name_rec, set_color(20, 20, 20, 255));
	font_writing(win, &title_rec, "Corewar", 70);
	font_writing(win, &name_rec, "By Amartino, Efischer, Fkante", 70);
}

void	draw_players_box(t_window *win)
{
	SDL_Rect	main_rec;
	int			x;
	int			y;

	x = (win->w * 0.75) + 15;
	y = win->h * 0.11;
	main_rec = init_new_rect(x, y, win->w * 0.24, win->h * 0.885);
	draw_rectangle(win, main_rec, set_color(20, 20, 20, 255));
	write_player_box(win, x + 15, y + 25);
	write_info_box(win, x + 15, y + 545);
}

void	draw_memory(t_window *win)
{
	SDL_Rect	position1;

	position1 = init_new_rect(5, 5, win->w * 0.75, win->h * 0.99);
	draw_rectangle(win, position1, set_color(20, 20, 20, 255));
}

int8_t	draw_zones(t_window *win)
{
	int8_t	ret;

	ret = FAILURE;
	if (SDL_SetRenderDrawColor(win->renderer, 90, 90, 90, 0) >= 0)
	{
		if (SDL_RenderClear(win->renderer) >= 0)
		{
			draw_memory(win);
			draw_header_box(win);
			draw_players_box(win);
			SDL_RenderPresent(win->renderer);
		}
	}
	return (ret);
}
