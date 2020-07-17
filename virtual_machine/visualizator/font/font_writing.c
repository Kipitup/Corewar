/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font_writing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 18:35:00 by francis           #+#    #+#             */
/*   Updated: 2020/07/17 17:52:10 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	classic_writing(t_window *win, SDL_Rect *rect, char *str)
{
	static SDL_Surface	*srf;
	static SDL_Texture	*text;

	srf = TTF_RenderText_Blended(win->font, str, set_color(255, 255, 255, 150));
	text = SDL_CreateTextureFromSurface(win->renderer, srf);
	SDL_RenderCopy(win->renderer, text, NULL, rect);
	SDL_FreeSurface(srf);
	srf = NULL;
	SDL_DestroyTexture(text);
}

void	green_writing(t_window *win, SDL_Rect *rect, char *str)
{
	SDL_Surface	*surf;
	SDL_Texture	*text;
	
	surf = TTF_RenderText_Blended(win->font, str, set_color(0, 200, 0, 200));
	text = SDL_CreateTextureFromSurface(win->renderer, surf);
	SDL_RenderCopy(win->renderer, text, NULL, rect);
	SDL_FreeSurface(surf);
	surf = NULL;
	SDL_DestroyTexture(text);
}

void	blue_writing(t_window *win, SDL_Rect *rect, char *str)
{
	SDL_Surface	*srf;
	SDL_Texture	*text;

	srf = TTF_RenderText_Blended(win->font, str, set_color(127, 255, 255, 200));
	text = SDL_CreateTextureFromSurface(win->renderer, srf);
	SDL_RenderCopy(win->renderer, text, NULL, rect);
	SDL_FreeSurface(srf);
	srf = NULL;
	SDL_DestroyTexture(text);
}

void	red_writing(t_window *win, SDL_Rect *rect, char *str)
{
	SDL_Surface	*surf;
	SDL_Texture	*text;

	surf = TTF_RenderText_Blended(win->font, str, set_color(200, 0, 0, 200));
	text = SDL_CreateTextureFromSurface(win->renderer, surf);
	SDL_RenderCopy(win->renderer, text, NULL, rect);
	SDL_FreeSurface(surf);
	surf = NULL;
	SDL_DestroyTexture(text);
}

void	purple_writing(t_window *win, SDL_Rect *rect, char *str)
{
	SDL_Surface	*surf;
	SDL_Texture	*text;

	surf = TTF_RenderText_Blended(win->font, str, set_color(121, 7, 242, 200));
	text = SDL_CreateTextureFromSurface(win->renderer, surf);
	SDL_RenderCopy(win->renderer, text, NULL, rect);
	SDL_FreeSurface(surf);
	surf = NULL;
	SDL_DestroyTexture(text);
}
