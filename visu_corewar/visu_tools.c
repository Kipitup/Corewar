/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 11:28:03 by francis           #+#    #+#             */
/*   Updated: 2020/06/20 11:28:40 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

SDL_Color	set_color(int red, int green, int blue, int alpha)
{
	SDL_Color	color;

	color.r = red;
	color.g = green;
	color.b = blue;
	color.a = alpha;
	return (color);
}

SDL_Rect	init_new_rect(int x, int y, int width, int height)
{
	SDL_Rect	new_rect;

	new_rect.x = x;
	new_rect.y = y;
	new_rect.w = width;
	new_rect.h = height;
	return (new_rect);
}

/*
**	defines a two dimensional point
*/
SDL_Point	set_point(int x, int y)
{
	SDL_Point	point;
	
	point.x = x;
	point.y = y;
	return (point);
}

int8_t      set_tab_int3(int *dest, int size, int color, int style)
{
	int8_t	ret;

	ret = FAILURE;
	if (dest != NULL)
	{
		dest[0] = size;
		dest[1] = color;
		dest[2] = style;
		ret = SUCCESS;
	}
	return (ret);
}

int8_t	draw_rectangle(t_window *win, SDL_Rect rect, SDL_Color color)
{
	if (SDL_SetRenderDrawColor(win->renderer, color.r, color.g,
			color.b, color.a) < 0)
		return (FAILURE);
	if ((SDL_RenderFillRect(win->renderer, &rect) < 0))
		return (FAILURE);
	return (SUCCESS);
}
