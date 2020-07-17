/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:24:37 by amartinod         #+#    #+#             */
/*   Updated: 2020/07/17 13:36:55 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** This operation writes the value of the first parameter (T_REG) at the
** address (addr = (ARG2 (T_REG/T_DIR/T_IND) + ARG3 (T_REG/T_DIR)) % IDX_MOD).
*/

void				op_sti(t_vm *vm, t_cursor *cursor)
{
	int32_t		arg_1;
	int32_t		arg_2;
	int32_t		arg_3;
	int32_t		address;
	uint8_t		type_of_param;

	arg_1 = cursor->param[0];
	type_of_param = param_type(vm, cursor, SECOND_PARAM);
	arg_2 = get_param_when_3_possible_type(vm, cursor, ARG_2, type_of_param);
	type_of_param = param_type(vm, cursor, THIRD_PARAM);
	if (type_of_param == T_REG)
		arg_3 = get_register(cursor, cursor->param[2]);
	else if (type_of_param == T_DIR)
		arg_3 = cursor->param[2];
	else
		return ;
	address = cursor->pc + ((arg_2 + arg_3) % IDX_MOD);
	vm->arena[address % MEM_SIZE] = cursor->registries[arg_1] >> 24;
	vm->arena[(address + 1) % MEM_SIZE] = cursor->registries[arg_1] >> 16;
	vm->arena[(address + 2) % MEM_SIZE] = cursor->registries[arg_1] >> 8;
	vm->arena[(address + 3) % MEM_SIZE] = cursor->registries[arg_1];
}
