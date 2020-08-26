/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:21:32 by amartinod         #+#    #+#             */
/*   Updated: 2020/07/19 10:28:46 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	Add/sub the value of the first and the second parameter (REG_CODE),
**	and stock the result in the third parameter (REG_CODE).
** If the result = 0 then carry = 1 else carry = 0.
*/

void		op_add(t_vm *vm, t_cursor *cursor)
{
	int64_t		arg_1;
	int64_t		arg_2;
	int32_t		arg_3;
	int32_t		value;

	(void)vm;
	arg_1 = (int64_t)get_register(cursor, cursor->param[0]);
	arg_2 = (int64_t)get_register(cursor, cursor->param[1]);
	arg_3 = cursor->param[2];
	value = (int32_t)(arg_1 + arg_2);
	cursor->registries[arg_3] = value;
	cursor->carry = (value == 0) ? 1 : 0;
}

void		op_sub(t_vm *vm, t_cursor *cursor)
{
	int64_t		arg_1;
	int64_t		arg_2;
	int32_t		arg_3;
	int32_t		value;

	(void)vm;
	arg_1 = (int64_t)get_register(cursor, cursor->param[0]);
	arg_2 = (int64_t)get_register(cursor, cursor->param[1]);
	arg_3 = cursor->param[2];
	value = (int32_t)(arg_1 - arg_2);
	cursor->registries[arg_3] = value;
	cursor->carry = (value == 0) ? 1 : 0;
}
