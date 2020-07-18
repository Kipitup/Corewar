/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 19:22:40 by francis           #+#    #+#             */
/*   Updated: 2020/07/18 11:34:46 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	player4_input_writing(t_window *win, t_all_rec *all_rec, int x, int y)
{
	SDL_Rect	name_input;

	x = x + win->w * 0.09;
	name_input = init_new_rect(x, y, win->w * 0.06, win->h * 0.03);
	all_rec->name4 = name_input;
}

void	player3_input_writing(t_window *win, t_all_rec *all_rec, int x, int y)
{
	SDL_Rect	name_input;

	x = x + win->w * 0.09;
	name_input = init_new_rect(x, y, win->w * 0.06, win->h * 0.03);
	all_rec->name3 = name_input;
}

void	player2_input_writing(t_window *win, t_all_rec *all_rec, int x, int y)
{
	SDL_Rect	name_input;

	x = x + win->w * 0.09;
	name_input = init_new_rect(x, y, win->w * 0.06, win->h * 0.03);
	all_rec->name2 = name_input;
}

void	player1_input_writing(t_window *win, t_all_rec *all_rec, int x, int y)
{
	SDL_Rect	name_input;

	x = x + win->w * 0.09;
	name_input = init_new_rect(x, y, win->w * 0.06, win->h * 0.03);
	all_rec->name1 = name_input;
}
