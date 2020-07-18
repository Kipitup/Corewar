/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_dump.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 10:36:55 by amartinod         #+#    #+#             */
/*   Updated: 2020/07/18 16:29:14 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static uint8_t	is_on_cursor(t_cursor *cursor, size_t i)
{
	uint8_t		ret;

	ret = FALSE;
	while (cursor != NULL)
	{
		if (cursor->pc == i)
		{
			ret = TRUE;
			break ;
		}
		cursor = cursor->next;
	}
	return (ret);
}

static void		dump_option_bis(size_t i, size_t dump_type)
{			
	if (i % dump_type == 0)
		ft_dprintf(STD_OUT, "\n0x%04x : ", i);
	if (i % 8 == 0 && COLOR_MODE == TRUE)
		ft_dprintf(STD_OUT, " ");
}

void			dump_option(t_vm *vm)
{
	size_t		i;
	size_t		dump_type;

	i = 0;
	if (vm != NULL)
	{
		dump_type = (vm->option & OPT_DUMP32) ? 32 : 64;
		while (i < MEM_SIZE)
		{
			dump_option_bis(i, dump_type);
			if (is_on_cursor(vm->cursor, i) == TRUE && COLOR_MODE == FALSE)
				ft_dprintf(STD_OUT, "%02b ", 16, vm->arena[i]);
			else if (is_on_cursor(vm->cursor, i) == TRUE && COLOR_MODE == TRUE)
				ft_dprintf(STD_OUT, "{c_red}%02b {c_end}", 16, vm->arena[i]);
			else if (vm->arena[i] > 0 && COLOR_MODE == FALSE)
				ft_dprintf(STD_OUT, "%02b ", 16, vm->arena[i]);
			else if (vm->arena[i] > 0 && COLOR_MODE == TRUE)
				ft_dprintf(STD_OUT, "{c_green}%02b {c_end}", 16, vm->arena[i]);
			else
				ft_dprintf(STD_OUT, "%02b ", 16, vm->arena[i]);
			i++;
		}
		ft_dprintf(STD_OUT, "\n");
	}
}
