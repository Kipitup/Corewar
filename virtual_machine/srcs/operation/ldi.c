/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:24:17 by amartinod         #+#    #+#             */
/*   Updated: 2020/07/17 13:40:09 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	Loads the value (value = ARG1 (T_DIR/T_REG/T_IND) + ARG2 (T_REG/T_DIR))
**	of the first two arguments inside the third one (T_REG).
*/

void		op_ldi(t_vm *vm, t_cursor *cursor)
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
	if (type_of_param == T_REG)
		arg_2 = get_register(cursor, cursor->param[1]);
	else if (type_of_param == T_DIR)
		arg_2 = cursor->param[1];
	else
		return ;
	address = cursor->pc + ((arg_1 + arg_2) % IDX_MOD);
	value = value | vm->arena[address % MEM_SIZE];
	value = value << 8;
	value = value | vm->arena[(address + 1) % MEM_SIZE];
	value = value << 8;
	value = value | vm->arena[(address + 2) % MEM_SIZE];
	value = value << 8;
	value = value | vm->arena[(address + 3) % MEM_SIZE];
	cursor->registries[cursor->param[2]] = value;
}
