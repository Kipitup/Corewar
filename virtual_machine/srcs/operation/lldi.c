/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:25:35 by amartinod         #+#    #+#             */
/*   Updated: 2020/07/18 15:26:04 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	Works exactly as the ldi operation appart from the fact that the IDX_MOD
**	is not applied.
*/

void		op_lldi(t_vm *vm, t_cursor *cursor)
{
	int32_t		arg_1;
	int32_t		arg_2;
	int32_t		address;
	int32_t		value;
	uint8_t		type_of_param;

	value = 0;
	type_of_param = param_type(vm, cursor, FIRST_PARAM);
	arg_1 = get_param_when_3_possible_type(vm, cursor, ARG_1, type_of_param);
	type_of_param = param_type(vm, cursor, SECOND_PARAM);
	if (type_of_param == REG_CODE)
		arg_2 = get_register(cursor, cursor->param[1]);
	else if (type_of_param == DIR_CODE)
		arg_2 = cursor->param[1];
	else
		return ;
	address = cursor->pc + (arg_1 + arg_2);
	value = value | vm->arena[modulo(address, MEM_SIZE)];
	value = value << 8;
	value = value | vm->arena[modulo(address + 1, MEM_SIZE)];
	value = value << 8;
	value = value | vm->arena[modulo(address + 2, MEM_SIZE)];
	value = value << 8;
	value = value | vm->arena[modulo(address + 3, MEM_SIZE)];
	cursor->registries[cursor->param[2]] = value;
	cursor->carry = (value == 0) ? 1 : 0;
}
