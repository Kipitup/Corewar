/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 18:32:55 by amartinod         #+#    #+#             */
/*   Updated: 2020/07/16 23:11:41 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int32_t	get_ind(t_vm *vm, t_cursor *cursor, size_t pc, size_t i)
{
	int32_t		value;

	value = 0;
	value = value | vm->arena[pc % MEM_SIZE];
	value = value << 8;
	value = value | vm->arena[(pc + 1) % MEM_SIZE];
	cursor->param[i] = value;
	ft_printf("param ind %02x (%d)\n", value, value);
	return (IND_SIZE);
}

static int32_t	get_dir(t_vm *vm, t_cursor *cursor, size_t pc, size_t i,
		uint8_t dir_size )
{
	int64_t		value;

	value = 0;
	value = value | vm->arena[pc % MEM_SIZE];
	value = value << 8;
	value = value | vm->arena[(pc + 1) % MEM_SIZE];
	if (dir_size == 4)
	{
		value = value << 8;
		value = value | vm->arena[(pc + 2) % MEM_SIZE];
		value = value << 8;
		value = value | vm->arena[(pc + 3) % MEM_SIZE];
	}
	else if ((value & 0x8000) == 0x8000)
		value = (int16_t)value;
	cursor->param[i] = (int32_t)value;
	ft_printf("param dir %02x (%d)\n", value, value);
	return (dir_size);
}

uint8_t			get_param_with_bytecode(t_vm *vm, t_cursor *cursor, size_t pc,
		uint8_t bytecode)
{
	size_t		i;
	uint8_t		bit_shift;
	uint8_t		bytecode_chunk;

	i = 0;
	bit_shift = 6;
	while (bit_shift > 0)
	{
		bytecode_chunk = (bytecode & (0b11 << bit_shift)) >> bit_shift;
		if (bytecode_chunk == 0b01)
		{
			cursor->param[i] = vm->arena[pc % MEM_SIZE];
			ft_printf("param reg %02x (%d)\n", cursor->param[i], cursor->param[i]);
			if (cursor->param[i] < 1 || cursor->param[i] > REG_NUMBER)
				return (FALSE);
			pc++;
		}
		else if (bytecode_chunk == 0b10)
			pc += get_dir(vm, cursor, pc, i, g_op_tab[cursor->op_code].dir_size);
		else if (bytecode_chunk == 0b11)
			pc += get_ind(vm, cursor, pc, i);
		bit_shift -= 2;
		i++;
	}
	return (TRUE);
}

uint8_t			get_param(t_vm *vm, t_cursor *cursor, size_t pc)
{
	uint8_t		bytecode;
	uint8_t		ret;

	ret = TRUE;
	if (g_op_tab[cursor->op_code].bytecode == TRUE)
	{
		bytecode = vm->arena[cursor->pc + 1 % MEM_SIZE];
		pc++;
		ret = get_param_with_bytecode(vm, cursor, pc, bytecode);
	}
	else
		get_dir(vm, cursor, pc, 0, g_op_tab[cursor->op_code].dir_size);
	return (ret);
}

/*
** static uint8_t		param_type(t_vm *vm, t_cursor *cursor, uint8_t bit_shift)		
** {
** 	uint8_t		bytecode;
** 	uint8_t		bytecode_chunk;
** 
** 	bytecode = vm->arena[cursor->pc + 1 % MEM_SIZE];
** 	bytecode_chunk = (bytecode & (0b11 << bit_shift)) >> bit_shift;
** 	return (bytecode_chunk);
** }
*/
