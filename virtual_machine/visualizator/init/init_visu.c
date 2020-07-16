/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_visu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 12:03:48 by francis           #+#    #+#             */
/*   Updated: 2020/07/16 20:43:39 by francis          ###   ########.fr       */
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
	else
		ft_printf("error initializing SDL: %s\n", SDL_GetError());
	return (ret);
}

static void	event_handler(t_window *win)
{
	SDL_Event	event;

	event = win->event;
	if (event.type == SDL_QUIT)
		win->running = OFF;
	if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE)
		win->running = OFF;
	if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_SPACE
			&& win->play == VISU_STOP)
		win->play = VISU_START;
	else if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_SPACE
			&& win->play == VISU_START)
		win->play = VISU_STOP;
	//	SPEED UP AND DOWN HERE IF NEEDED
}

int			setup_window(t_vm *vm)
{
	t_window	win;
	t_all_rec	all_rec;

	(void)vm;
	if (create_window(&win) == SUCCESS)
	{
		if (draw_init_zones(&win, &all_rec) == FAILURE)
			ft_printf("error initializing SDL: %s\n", SDL_GetError());
		while (win.running == ON)
		{
			if (SDL_PollEvent(&win.event) != 0)
				event_handler(&win);
			active_zones(&win, &all_rec);
			SDL_Delay(100);
			SDL_RenderPresent(win.renderer);
		}
	}
	else
	{
		ft_printf("error creating window: %s\n", SDL_GetError());
		destroy_visual(&win);
		return (FAILURE);
	}
	if (win.running == OFF)
		destroy_visual(&win);
	TTF_Quit();
	return (SUCCESS);
}
