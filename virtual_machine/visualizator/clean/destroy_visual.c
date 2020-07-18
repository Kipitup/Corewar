/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_visual.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 17:04:19 by francis           #+#    #+#             */
/*   Updated: 2020/07/18 14:55:58 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void		destroy_visual(t_window *win)
{
	if (win != NULL)
	{
		SDL_RenderClear(win->renderer);
		SDL_DestroyRenderer(win->renderer);
		SDL_DestroyWindow(win->window);
		TTF_CloseFont(win->font);
		win->font = NULL;
	}
	TTF_Quit();
	SDL_Quit();
}
