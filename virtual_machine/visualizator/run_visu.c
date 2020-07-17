/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_visu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 09:54:14 by francis           #+#    #+#             */
/*   Updated: 2020/07/17 14:57:36 by francis          ###   ########.fr       */
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
	if (event->type == SDL_KEYUP && event->key.keysym.sym == SDLK_SPACE
			&& win->play == VISU_STOP)
		win->play = VISU_START;
	else if (event->type == SDL_KEYUP && event->key.keysym.sym == SDLK_SPACE
			&& win->play == VISU_START)
		win->play = VISU_STOP;
	//	SPEED UP AND DOWN HERE IF NEEDED
}

int		run_visu(t_vm *vm, t_window *win)
{
	t_all_rec	all_rec;

	if (win->running == ON)
	{
		if (SDL_RenderClear(win->renderer) >= 0)
		{
			draw_init_zones(vm, win, &all_rec); 
			if (SDL_PollEvent(&win->event) != 0)
				event_handler(win);
			active_zones(vm, win, &all_rec);
			SDL_RenderPresent(win->renderer);
		}
		else
		{
			ft_printf("Error SDL: %s\n", SDL_GetError());
			destroy_visual(win);
			return (FAILURE);
		}
	}
	if (win->running == OFF)
		destroy_visual(win);
	return (SUCCESS);
}
