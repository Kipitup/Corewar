/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 19:38:37 by amartinod         #+#    #+#             */
/*   Updated: 2020/07/18 11:39:02 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

uint8_t		param_type(t_vm *vm, t_cursor *cursor, uint8_t bit_shift)		
{
	uint8_t		bytecode;
	uint8_t		bytecode_chunk;

	bytecode = vm->arena[cursor->pc + 1 % MEM_SIZE];
	bytecode_chunk = (bytecode & (0b11 << bit_shift)) >> bit_shift;
	return (bytecode_chunk);
}

int32_t		get_indirect(t_vm *vm, t_cursor *cursor, uint8_t nb_arg)
{
	size_t 		pc;
	int32_t		value;
	int16_t		arg;

	value = 0;
	arg = cursor->param[nb_arg];
	pc = cursor->pc + (arg % IDX_MOD);
	value = value | vm->arena[pc % MEM_SIZE];
	value = value << 8;
	value = value | vm->arena[(pc + 1) % MEM_SIZE];
	value = value << 8;
	value = value | vm->arena[(pc + 2) % MEM_SIZE];
	value = value << 8;
	value = value | vm->arena[(pc + 3) % MEM_SIZE];
	return (value);
}

int32_t		get_register(t_cursor *cursor, size_t reg_number)
{
	return (cursor->registries[reg_number]);
}

int32_t		get_param_when_3_possible_type(t_vm *vm, t_cursor *cursor, 
		uint8_t nb_arg, uint8_t type)
{
	int32_t		arg;

	arg = 0;
	if (type == T_REG)
		arg = get_register(cursor, cursor->param[nb_arg]);
	else if (type == T_IND)
		arg = get_indirect(vm, cursor, 1);
	else if (type == T_DIR)
		arg = cursor->param[nb_arg];
	return (arg);
}

int32_t			modulo(int32_t a, int32_t b)
{
	if (a % b >= 0)
		return (a % b);
	else
		return ((a % b) + b);
}
