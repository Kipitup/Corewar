/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:24:37 by amartinod         #+#    #+#             */
/*   Updated: 2020/07/16 16:21:37 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		op_sti(t_vm *vm, t_cursor *cursor)
{
	size_t		i;

	i = 0;
	while (i < g_op_tab[cursor->op_code].nb_param)
	{
		ft_printf("param n* %zu = %02x\n",i , cursor->param[i]);
		i++;
	}
	(void)vm;
	(void)cursor;
}
