/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_visu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 09:54:14 by francis           #+#    #+#             */
/*   Updated: 2020/07/19 11:43:24 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "visu.h"

void	event_handler(t_window *win)
{
	SDL_Event	*event;

	event = &win->event;
	if (event->type == SDL_QUIT)
		win->running = OFF;
	if (event->type == SDL_KEYUP && event->key.keysym.sym == SDLK_ESCAPE)
		win->running = OFF;
	if ((event->type == SDL_KEYUP && event->key.keysym.sym == SDLK_UP))
		win->cycle_frame = win->cycle_frame == 512 ? 512 : win->cycle_frame * 2;
	if ((event->type == SDL_KEYUP && event->key.keysym.sym == SDLK_DOWN))
		win->cycle_frame = win->cycle_frame == 1 ? 1 : win->cycle_frame / 2;
}

void	run_visu(t_vm *vm, t_window *win)
{
	t_all_rec	all_rec;

	if (vm->option & OPT_VISU && vm->cycle_counter % win->cycle_frame == 0)
	{
		if (win->running == ON)
		{
			SDL_RenderClear(win->renderer);
			draw_init_zones(vm, win, &all_rec);
			if (SDL_PollEvent(&win->event) != 0)
				event_handler(win);
			active_zones(vm, win, &all_rec);
			SDL_RenderPresent(win->renderer);
		}
		if (win->running == OFF)
			destroy_visual(win);
	}
}

void	end_visu(t_vm *vm, t_window *win)
{
	t_all_rec	all_rec;

	if (vm->option & OPT_VISU && win != NULL && win->running == ON)
	{
		while (win->running == ON)
		{
			SDL_RenderClear(win->renderer);
			draw_init_zones(vm, win, &all_rec);
			if (SDL_PollEvent(&win->event) != 0)
				event_handler(win);
			ending_screen(vm, win, &all_rec);
			SDL_RenderPresent(win->renderer);
		}
		destroy_visual(win);
	}
}
