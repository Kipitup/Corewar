/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:21:00 by amartinod         #+#    #+#             */
/*   Updated: 2020/07/18 11:47:48 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	Takes the value in the first parameter (REG_CODE) and passes it either on a
**	register or in the memory (REG_CODE/IND_CODE).
*/

void		op_st(t_vm *vm, t_cursor *cursor)
{
	int32_t		a1;
	int16_t		arg_2;
	int32_t		address;
	uint8_t		type_of_param;

	ft_dprintf(STD_ERR, "pc is %zu\n", cursor->pc);
	a1 = cursor->param[0];
	arg_2 = (int16_t)cursor->param[1];
	ft_dprintf(STD_ERR, "arg 2 is %d\n", arg_2);
	type_of_param = param_type(vm, cursor, SECOND_PARAM);
	if (type_of_param == REG_CODE)
		cursor->registries[arg_2] = cursor->registries[a1];
	else if (type_of_param == IND_CODE)
	{
		address = cursor->pc + (arg_2 % IDX_MOD);
		ft_dprintf(STD_ERR, "address is %d\n", address);
		vm->arena[modulo(address, MEM_SIZE)] = cursor->registries[a1] >> 24;
		vm->arena[modulo(address + 1, MEM_SIZE)] = cursor->registries[a1] >> 16;
		vm->arena[modulo(address + 2, MEM_SIZE)] = cursor->registries[a1] >> 8;
		vm->arena[modulo(address + 3, MEM_SIZE)] = cursor->registries[a1];
	}
}
