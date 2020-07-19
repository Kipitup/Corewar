/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 20:12:40 by francis           #+#    #+#             */
/*   Updated: 2020/07/18 21:33:42 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static void	tmp_for_itoa_leaks(t_window *win, SDL_Rect *delta, SDL_Rect *live)
{
	char	*tmp_delta;
	char	*tmp_live;

	tmp_delta = ft_itoa(CYCLE_DELTA);
	tmp_live = ft_itoa(NBR_LIVE);
	classic_writing(win, delta, tmp_delta);
	classic_writing(win, live, tmp_live);
	ft_strdel(&tmp_delta);
	ft_strdel(&tmp_live);
}

static void	info_input_writing(t_window *win, t_all_rec *all_rec, int x, int y)
{
	SDL_Rect	to_die_input;
	SDL_Rect	delta_input;
	SDL_Rect	nb_live_input;
	SDL_Rect	counter_input;
	SDL_Rect	cycle_input;

	x = x + win->w * 0.10;
	to_die_input = init_new_rect(x, y, win->w * 0.032, win->h * 0.02);
	delta_input = init_new_rect(x, y + 50, win->w * 0.015, win->h * 0.02);
	nb_live_input = init_new_rect(x, y + 100, win->w * 0.015, win->h * 0.02);
	counter_input = init_new_rect(x, y + 150, win->w * 0.032, win->h * 0.02);
	cycle_input = init_new_rect(x, y + 200, win->w * 0.015, win->h * 0.02);
	all_rec->to_die = to_die_input;
	all_rec->cycle_frame = cycle_input;
	all_rec->cycle_counter = counter_input;
	tmp_for_itoa_leaks(win, &delta_input, &nb_live_input);
}

void		info_box(t_window *win, t_all_rec *all_rec, int x, int y)
{
	SDL_Rect	to_die_rec;
	SDL_Rect	delta_rec;
	SDL_Rect	nb_live_rec;
	SDL_Rect	counter_rec;
	SDL_Rect	cycle_rec;

	to_die_rec = init_new_rect(x, y, win->w * 0.08, win->h * 0.02);
	delta_rec = init_new_rect(x, y + 50, win->w * 0.08, win->h * 0.02);
	nb_live_rec = init_new_rect(x, y + 100, win->w * 0.08, win->h * 0.02);
	counter_rec = init_new_rect(x, y + 150, win->w * 0.08, win->h * 0.02);
	cycle_rec = init_new_rect(x, y + 200, win->w * 0.08, win->h * 0.02);
	classic_writing(win, &to_die_rec, "CYCLE_TO_DIE:");
	classic_writing(win, &delta_rec, "CYCLE_DELTA:");
	classic_writing(win, &nb_live_rec, "NBR_LIVES:");
	classic_writing(win, &counter_rec, "CYCLE_COUNTER:");
	classic_writing(win, &cycle_rec, "CYCLE_PER_FRAME:");
	info_input_writing(win, all_rec, x, y);
}

static void	live_and_check_writing(t_window *win, t_all_rec *rec, int x, int y)
{
	SDL_Rect	live_input;
	SDL_Rect	check_input;

	x = x + win->w * 0.10;
	live_input = init_new_rect(x, y + 250, win->w * 0.032, win->h * 0.02);
	check_input = init_new_rect(x, y + 300, win->w * 0.015, win->h * 0.02);
	rec->live_counter = live_input;
	rec->check_counter = check_input;
}

void		live_and_check_box(t_window *win, t_all_rec *all_rec, int x, int y)
{
	SDL_Rect	live_rec;
	SDL_Rect	check_rec;

	live_rec = init_new_rect(x, y + 250, win->w * 0.08, win->h * 0.02);
	check_rec = init_new_rect(x, y + 300, win->w * 0.08, win->h * 0.02);
	classic_writing(win, &live_rec, "LIVE_COUNTER:");
	classic_writing(win, &check_rec, "CHECK_COUNTER:");
	live_and_check_writing(win, all_rec, x, y);
}
