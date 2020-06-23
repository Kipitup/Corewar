/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font_writing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 18:35:00 by francis           #+#    #+#             */
/*   Updated: 2020/06/20 20:03:30 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

// change size by color maybe as the size is affected by the rect size !!

int8_t	font_writing(t_window *win, SDL_Rect *rect, char *str, int size)
{
	SDL_Surface	*textsurf;
	SDL_Texture	*text;
	TTF_Font	*font;
	int8_t		ret;

	ret = SUCCESS;
	font = TTF_OpenFont(FONT_PATH, size);
	textsurf = TTF_RenderText_Blended(font, str, set_color(255, 255, 255, 255));
	text = SDL_CreateTextureFromSurface(win->renderer, textsurf);
	SDL_RenderCopy(win->renderer, text, NULL, rect);
	SDL_FreeSurface(textsurf);
	textsurf = NULL;
	TTF_CloseFont(font);
	return (ret);
}

int8_t	green_writing(t_window *win, SDL_Rect *rect, char *str)
{
	SDL_Surface	*textsurf;
	SDL_Texture	*text;
	TTF_Font	*font;
	int8_t		ret;

	ret = SUCCESS;
	font = TTF_OpenFont(FONT_PATH, 70);
	textsurf = TTF_RenderText_Blended(font, str, set_color(0, 200, 0, 255));
	text = SDL_CreateTextureFromSurface(win->renderer, textsurf);
	SDL_RenderCopy(win->renderer, text, NULL, rect);
	SDL_FreeSurface(textsurf);
	textsurf = NULL;
	TTF_CloseFont(font);
	return (ret);
}

int8_t	blue_writing(t_window *win, SDL_Rect *rect, char *str)
{
	SDL_Surface	*textsurf;
	SDL_Texture	*text;
	TTF_Font	*font;
	int8_t		ret;

	ret = SUCCESS;
	font = TTF_OpenFont(FONT_PATH, 70);
	textsurf = TTF_RenderText_Blended(font, str, set_color(0, 0, 200, 255));
	text = SDL_CreateTextureFromSurface(win->renderer, textsurf);
	SDL_RenderCopy(win->renderer, text, NULL, rect);
	SDL_FreeSurface(textsurf);
	textsurf = NULL;
	TTF_CloseFont(font);
	return (ret);
}

int8_t	red_writing(t_window *win, SDL_Rect *rect, char *str)
{
	SDL_Surface	*textsurf;
	SDL_Texture	*text;
	TTF_Font	*font;
	int8_t		ret;

	ret = SUCCESS;
	font = TTF_OpenFont(FONT_PATH, 70);
	textsurf = TTF_RenderText_Blended(font, str, set_color(200, 0, 0, 255));
	text = SDL_CreateTextureFromSurface(win->renderer, textsurf);
	SDL_RenderCopy(win->renderer, text, NULL, rect);
	SDL_FreeSurface(textsurf);
	textsurf = NULL;
	TTF_CloseFont(font);
	return (ret);
}
