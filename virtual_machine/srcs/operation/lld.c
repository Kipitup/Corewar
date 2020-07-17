/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:25:17 by amartinod         #+#    #+#             */
/*   Updated: 2020/07/17 13:35:56 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	Works exactly as the ld operation appart from the fact that the IDX_MOD
**	is not applied.
**	if the result of the operation = 0 then carry = 0 else carry = 1.
*/
static int32_t	get_long_indirect(t_vm *vm, t_cursor *cursor, uint8_t nb_arg)
{
	size_t 		pc;
	int32_t		value;

	value = 0;
	pc = cursor->pc + cursor->param[nb_arg];
	value = value | vm->arena[pc % MEM_SIZE];
	value = value << 8;
	value = value | vm->arena[(pc + 1) % MEM_SIZE];
	value = value << 8;
	value = value | vm->arena[(pc + 2) % MEM_SIZE];
	value = value << 8;
	value = value | vm->arena[(pc + 3) % MEM_SIZE];
	return (value);
}
void			op_lld(t_vm *vm, t_cursor *cursor)
{
	int32_t		arg_1;
	int32_t		arg_2;
	uint8_t		type_of_param;

	type_of_param = param_type(vm, cursor, FIRST_PARAM);
	if (type_of_param == T_DIR)
		arg_1 = cursor->param[0];
	else if (type_of_param == T_IND)
		arg_1 = get_long_indirect(vm, cursor, 0);
	else
		return ;
	arg_2 = cursor->param[1];
	cursor->registries[arg_2] = arg_1;
	cursor->carry = (arg_1 == 0) ? 1 : 0;
}
