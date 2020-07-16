/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_xor_or.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:23:00 by amartinod         #+#    #+#             */
/*   Updated: 2020/07/16 22:36:32 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** Performs a bitwise  AND - XOR - OR operation for the values of the first two
** arguments (T_DIR/T_REG/T_IND) and writes the result to the third argument.
** (T_REG)
*/

void		op_and(t_vm *vm, t_cursor *cursor)
{
	int32_t		arg_1;
	int32_t		arg_2;
	int32_t		arg_3;
	int32_t		value;
	uint8_t		type_of_param;

	type_of_param = param_type(vm, cursor, FIRST_PARAM);
	arg_1 = get_param_when_3_possible_type(vm, cursor, 0, type_of_param);
	type_of_param = param_type(vm, cursor, SECOND_PARAM);
	arg_2 = get_param_when_3_possible_type(vm, cursor, 1, type_of_param);
	arg_3 = cursor->param[2];
	value = arg_1 & arg_2;
	cursor->carry = (value == 0) ? 1 : 0;
	cursor->registries[arg_3] = value;
}

void		op_or(t_vm *vm, t_cursor *cursor)
{
	int32_t		arg_1;
	int32_t		arg_2;
	int32_t		arg_3;
	int32_t		value;
	uint8_t		type_of_param;

	type_of_param = param_type(vm, cursor, FIRST_PARAM);
	arg_1 = get_param_when_3_possible_type(vm, cursor, 0, type_of_param);
	type_of_param = param_type(vm, cursor, SECOND_PARAM);
	arg_2 = get_param_when_3_possible_type(vm, cursor, 1, type_of_param);
	arg_3 = cursor->param[2];
	value = arg_1 | arg_2;
	cursor->carry = (value == 0) ? 1 : 0;
	cursor->registries[arg_3] = value;
}

void		op_xor(t_vm *vm, t_cursor *cursor)
{
	int32_t		arg_1;
	int32_t		arg_2;
	int32_t		arg_3;
	int32_t		value;
	uint8_t		type_of_param;

	type_of_param = param_type(vm, cursor, FIRST_PARAM);
	arg_1 = get_param_when_3_possible_type(vm, cursor, 0, type_of_param);
	type_of_param = param_type(vm, cursor, SECOND_PARAM);
	arg_2 = get_param_when_3_possible_type(vm, cursor, 1, type_of_param);
	arg_3 = cursor->param[2];
	value = arg_1 ^ arg_2;
	cursor->carry = (value == 0) ? 1 : 0;
	cursor->registries[arg_3] = value;
}
