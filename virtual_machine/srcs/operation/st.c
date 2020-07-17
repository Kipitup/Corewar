/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:21:00 by amartinod         #+#    #+#             */
/*   Updated: 2020/07/17 20:22:51 by amartinod        ###   ########.fr       */
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
	int32_t		arg_2;
	int32_t		address;
	uint8_t		type_of_param;

	ft_dprintf(STD_ERR, "pc is %zu\n", cursor->pc);
	arg_1 = cursor->param[0];
	type_of_param = param_type(vm, cursor, SECOND_PARAM);
	if (type_of_param == REG_CODE)
	{
		arg_2 = cursor->param[1];
		cursor->registries[arg_2] = cursor->registries[arg_1];
	}
	else if (type_of_param == IND_CODE)
	{
		arg_2 = get_indirect(vm, cursor, ARG_2);
		address = cursor->pc + (arg_2 % IDX_MOD);
		ft_dprintf(STD_ERR, "address %d cursor->registries[arg_1] %d\n", address, cursor->registries[arg_1]);
		vm->arena[address % MEM_SIZE] = cursor->registries[arg_1] >> 24;
		vm->arena[(address + 1) % MEM_SIZE] = cursor->registries[arg_1] >> 16;
		vm->arena[(address + 2) % MEM_SIZE] = cursor->registries[arg_1] >> 8;
		vm->arena[(address + 3) % MEM_SIZE] = cursor->registries[arg_1];
	}
}
