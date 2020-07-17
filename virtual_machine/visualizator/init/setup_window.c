/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 12:03:48 by francis           #+#    #+#             */
/*   Updated: 2020/07/17 15:00:07 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

/*
 **	setup the window to host program corewar.
 **	important steps are to create the window depending on the user's screen
 **	and set the renderer. Renderer depends on the surface of the window.
 **	Avoid using directly the surface so SDL will not loose the pointer to it,
 **	As the renderer works on the surface.
 */
int8_t		create_window(t_window *win)
{
	SDL_DisplayMode	display_info;
	int8_t	ret;

	ret = FAILURE;
	if (SDL_Init(SDL_INIT_EVERYTHING) == SUCCESS && TTF_Init() != FAILURE)
	{
		SDL_GetDesktopDisplayMode(0, &display_info);
		win->w = display_info.w * 0.9;
		win->h = display_info.h * 0.9;
		win->window = SDL_CreateWindow("Corewar", SDL_WINDOWPOS_CENTERED,
				SDL_WINDOWPOS_CENTERED, win->w, win->h, 0);
		win->renderer = SDL_CreateRenderer(win->window, -1,
				SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (SDL_SetRenderDrawBlendMode(win->renderer, SDL_BLENDMODE_BLEND) < 0)
			ret = RENDER_FAILURE;
		if (win->window != NULL && win->renderer != NULL && ret == FAILURE)
		{
			win->running = ON;
			win->play = VISU_STOP;
			ret = SUCCESS;
		}
	}
	return (ret);
}

void	setup_window(t_vm *vm, t_window *win)
{
	t_all_rec rec;

	if (create_window(win) == SUCCESS)
	{
		if (SDL_SetRenderDrawColor(win->renderer, 20, 20, 20, 0) >= 0)
		{
			draw_init_zones(vm, win, &rec); 
			draw_arena(win);
			SDL_RenderPresent(win->renderer);
		}
		else
		{
			ft_printf("Error SDL: %s\n", SDL_GetError());
			destroy_visual(win);
		}
	}
	else
	{
		ft_printf("Error creating window: %s\n", SDL_GetError());
		destroy_visual(win);
	}
}
