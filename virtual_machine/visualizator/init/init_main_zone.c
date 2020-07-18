/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main_zone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 09:15:55 by francis           #+#    #+#             */
/*   Updated: 2020/07/18 11:45:42 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	draw_header_rec(t_window *win)
{
	SDL_Rect	main_rec;
	SDL_Rect	title_rec;
	SDL_Rect	nam;
	int			x;
	int			y;

	x = (win->w * 0.75) + 15;
	y = 5;
	main_rec = init_new_rect(x, y, win->w * 0.24, win->h * 0.10);
	title_rec = init_new_rect(x + 5, y + 5, win->w * 0.10, win->h * 0.05);
	nam = init_new_rect(x + 5, y + win->h * 0.06, win->w * 0.20, win->h * 0.03);
	classic_writing(win, &title_rec, "Corewar");
	classic_writing(win, &nam, "By Amartino, Efischer, Fkante");
}

void	draw_player_info_comm_rec(t_vm *vm, t_window *win, t_all_rec *all_rec)
{
	SDL_Rect	main_rec;
	SDL_Point	point;
	int			x;
	int			y;

	x = (win->w * 0.75) + 15;
	y = win->h * 0.11;
	main_rec = init_new_rect(x, y, win->w * 0.24, win->h * 0.885);
	point = set_point(x + 15, y + 25);
	player_box(vm, win, all_rec, point);
	info_box(win, all_rec, x + 15, y + 450);
	command_box(win, all_rec, x + 15, y + win->h * 0.75);
}

void	draw_arena(t_window *win)
{
	SDL_Rect	position1;

	position1 = init_new_rect(5, 5, win->w * 0.75, win->h * 0.99);
	init_arena(win);
}

void	draw_init_zones(t_vm *vm, t_window *win, t_all_rec *all_rec)
{
	draw_header_rec(win);
	draw_player_info_comm_rec(vm, win, all_rec);
}
