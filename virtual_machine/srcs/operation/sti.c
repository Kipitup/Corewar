/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:24:37 by amartinod         #+#    #+#             */
/*   Updated: 2020/07/16 19:40:39 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void				op_sti(t_vm *vm, t_cursor *cursor)
{
	int32_t		arg_1;
	int32_t		arg_2;
	int32_t		arg_3;
	int32_t		address;
	uint8_t		type_of_param;

	arg_1 = cursor->param[0];
	type_of_param = param_type(vm, cursor, SECOND_PARAM);
	if (type_of_param == T_REG)
		arg_2 = get_register(cursor, cursor->param[1]);
	else if (type_of_param == T_IND)
		arg_2 = get_indirect(vm, cursor, 1);
	else
		arg_2 = cursor->param[1];
	type_of_param = param_type(vm, cursor, THIRD_PARAM);
	if (type_of_param == T_REG)
		arg_3 = get_register(cursor, cursor->param[2]);
	else
		arg_3 = cursor->param[2];
	address = cursor->pc + ((arg_2 + arg_3) % IDX_MOD);
	vm->arena[address % MEM_SIZE] = cursor->registries[arg_1] >> 24;
	vm->arena[(address + 1) % MEM_SIZE] = cursor->registries[arg_1] >> 16;
	vm->arena[(address + 2) % MEM_SIZE] = cursor->registries[arg_1] >> 8;
	vm->arena[(address + 3) % MEM_SIZE] = cursor->registries[arg_1];
}
