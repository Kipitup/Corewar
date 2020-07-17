/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:21:00 by amartinod         #+#    #+#             */
/*   Updated: 2020/07/17 13:37:41 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	Takes the value in the first parameter (T_REG) and passes it either on a
**	register or in the memory (T_REG/T_IND).
*/

void		op_st(t_vm *vm, t_cursor *cursor)
{
	int32_t		arg_1;
	int32_t		arg_2;
	int32_t		address;
	uint8_t		type_of_param;

	arg_1 = cursor->param[0];
	arg_2 = cursor->param[1];
	type_of_param = param_type(vm, cursor, SECOND_PARAM);
	if (type_of_param == T_REG)
		cursor->registries[arg_2] = cursor->registries[arg_1];
	else if (type_of_param == T_IND)
	{
		address = cursor->pc + (arg_2 % IDX_MOD);
		vm->arena[address % MEM_SIZE] = cursor->registries[arg_1] >> 24;
		vm->arena[(address + 1) % MEM_SIZE] = cursor->registries[arg_1] >> 16;
		vm->arena[(address + 2) % MEM_SIZE] = cursor->registries[arg_1] >> 8;
		vm->arena[(address + 3) % MEM_SIZE] = cursor->registries[arg_1];
	}
}
