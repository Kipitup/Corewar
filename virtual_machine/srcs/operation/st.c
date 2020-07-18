/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:21:00 by amartinod         #+#    #+#             */
/*   Updated: 2020/07/18 16:25:12 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	Takes the value in the first parameter (REG_CODE) and passes it either on a
**	register or in the memory (REG_CODE/IND_CODE).
*/

void		op_st(t_vm *vm, t_cursor *cursor)
{
	int32_t		arg_1;
	int16_t		arg_2;
	int32_t		addr;
	uint8_t		type_of_param;

	arg_1 = get_register(cursor, cursor->param[0]);
	arg_2 = (int16_t)cursor->param[1];
	type_of_param = param_type(vm, cursor, SECOND_PARAM);
	if (type_of_param == REG_CODE)
		cursor->registries[arg_2] = arg_1;
	else if (type_of_param == IND_CODE)
	{
		addr = cursor->pc + (arg_2 % IDX_MOD);
		vm->arena[modulo(addr, MEM_SIZE)] = arg_1 >> 24;
		vm->arena[modulo(addr + 1, MEM_SIZE)] = arg_1 >> 16;
		vm->arena[modulo(addr + 2, MEM_SIZE)] = arg_1 >> 8;
		vm->arena[modulo(addr + 3, MEM_SIZE)] = arg_1;
		vm->arena_owner[modulo(addr, MEM_SIZE)] = cursor->id;
		vm->arena_owner[modulo(addr + 1, MEM_SIZE)] = cursor->id;
		vm->arena_owner[modulo(addr + 2, MEM_SIZE)] = cursor->id;
		vm->arena_owner[modulo(addr + 3, MEM_SIZE)] = cursor->id;
	}
}
