/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 19:38:37 by amartinod         #+#    #+#             */
/*   Updated: 2020/07/17 21:56:41 by amartinod        ###   ########.fr       */
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

t_cursor		*fork_cursor(t_cursor *cursor, int32_t address)
{
	t_cursor	*new_cursor;

	new_cursor = ft_memalloc(sizeof(t_cursor));
	if (new_cursor != NULL)
	{
		new_cursor = ft_memcpy(new_cursor, cursor, sizeof(t_cursor));
		new_cursor->pc = address % MEM_SIZE;
	}
	return (new_cursor);
}
