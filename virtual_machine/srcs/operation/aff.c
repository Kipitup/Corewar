/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:26:10 by amartinod         #+#    #+#             */
/*   Updated: 2020/07/19 11:13:21 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** This operation takes the value from the registry passed as argument
** (REG_CODE), casts it to the type char and prints it to the standard output.
*/

void		op_aff(t_vm *vm, t_cursor *cursor)
{
	int32_t		arg_1;
	char		c;

	(void)vm;
	arg_1 = get_register(cursor, cursor->param[0]);
	c = (char)arg_1;
	ft_printf("Aff: %c\n", (c % 256));
}
