/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:21:32 by amartinod         #+#    #+#             */
/*   Updated: 2020/07/17 13:39:47 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	Add/sub the value of the first and the second parameter (T_REG), and stock
**	the result in the third parameter (T_REG).
** If the result = 0 then carry = 1 else carry = 0.
*/

void		op_add(t_vm *vm, t_cursor *cursor)
{
	int32_t		arg_1;
	int32_t		arg_2;
	int32_t		arg_3;
	int32_t		value;

	(void)vm;
	arg_1 = get_register(cursor, cursor->param[0]);
	arg_2 = get_register(cursor, cursor->param[1]);
	arg_3 = cursor->param[2];
	value = arg_1 + arg_2;
	cursor->registries[arg_3] = value;
	cursor->carry = (value == 0) ? 1 : 0;
}

void		op_sub(t_vm *vm, t_cursor *cursor)
{
	int32_t		arg_1;
	int32_t		arg_2;
	int32_t		arg_3;
	int32_t		value;

	(void)vm;
	arg_1 = get_register(cursor, cursor->param[0]);
	arg_2 = get_register(cursor, cursor->param[1]);
	arg_3 = cursor->param[2];
	value = arg_1 - arg_2;
	cursor->registries[arg_3] = value;
	cursor->carry = (value == 0) ? 1 : 0;
}
