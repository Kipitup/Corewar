/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 09:19:26 by francis           #+#    #+#             */
/*   Updated: 2020/07/18 11:34:23 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static int8_t	uint8_t_to_hexa(char *str, uint8_t arena_mem)
{
	char	*tmp;
	int8_t	ret;

	ret = FAILURE;
	if ((tmp = ft_itoa_base(arena_mem, 16)) != NULL)
	{
		if (arena_mem < 16)
		{
			str[0] = '0';
			str[1] = tmp[0];
		}
		else
		{
			str[0] = tmp[0];
			str[1] = tmp[1];
		}
		str[2] = '\0';
		ft_strdel(&tmp);
		ret = SUCCESS;
	}
	return (ret);
}

void			init_arena(t_window *win)
{
	SDL_Point	point;
	SDL_Rect	rec;
	int			count;

	point = set_point(8, 8);
	count = 0;
	while (count < MEM_SIZE)
	{
		rec = init_new_rect(point.x, point.y, win->w * 0.009, win->h * 0.015);
		classic_writing(win, &rec, "00");
		point.x = point.x + win->w * 0.012;
		if ((count + 1) % 64 == 0 && count != 0)
		{
			point.y = point.y + win->h * 0.016;
			point.x = 8;
		}
		count++;
	}
}

void			active_arena(t_vm *vm, t_window *win)
{
	SDL_Point			point;
	SDL_Rect			rec;
	static t_color_func	color[NB_COLOR] = {classic_writing, purple_writing,
		blue_writing, green_writing, red_writing};
	int					count;
	char				mem[3];

	point = set_point(8, 8);
	count = 0;
	while (count < MEM_SIZE)
	{
		rec = init_new_rect(point.x, point.y, win->w * 0.009, win->h * 0.015);
		uint8_t_to_hexa(mem, vm->arena[count]);
		color[vm->arena_owner[count]](win, &rec, mem);
		point.x = point.x + win->w * 0.012;
		if ((count + 1) % 64 == 0 && count != 0)
		{
			point.y = point.y + win->h * 0.016;
			point.x = 8;
		}
		count++;
	}
}
