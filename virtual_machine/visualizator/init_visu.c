/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_visu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 12:03:48 by francis           #+#    #+#             */
/*   Updated: 2020/07/13 22:55:37 by francis          ###   ########.fr       */
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
			win->play = ON;
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

	while (win->play == ON)
	{
		if (SDL_PollEvent(&win->event) != 0)
		{
			event = win->event;
			if (event.type == SDL_QUIT)
				win->play = OFF;
			if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE)
				win->play = OFF;
			//	SPEED UP AND DOWN HERE IF NEEDED
		}
	}
}

void		destroy_visual(t_window *win)
{
	if (win != NULL)
	{
		SDL_DestroyWindow(win->window);
		SDL_DestroyRenderer(win->renderer);
	}
	SDL_Quit();
}

int			setup_window(t_vm *vm)
{
	t_window	win;

	(void)vm;
	if (create_window(&win) == SUCCESS)
	{
		if (draw_zones(&win) == FAILURE)
			ft_printf("error initializing SDL: %s\n", SDL_GetError());
		event_handler(&win);
		if (win.play == OFF)
			destroy_visual(&win);
		SDL_Delay(200);
	}
	else
	{
		ft_printf("error creating window: %s\n", SDL_GetError());
		destroy_visual(&win);
		return (FAILURE);
	}
	TTF_Quit();
	return (SUCCESS);
}
