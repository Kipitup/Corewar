/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 18:32:55 by amartinod         #+#    #+#             */
/*   Updated: 2020/07/03 12:15:45 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int32_t	get_ind(t_vm *vm, t_cursor *cursor, size_t pc, size_t i)
{
	uint8_t		value;

	(void)value;
	(void)vm;
	(void)cursor;
	(void)pc;
	(void)i;
	return (IND_SIZE);
}

static int32_t	get_dir(t_vm *vm, t_cursor *cursor, size_t pc, size_t i,
		uint8_t dir_size )
{
	uint8_t		value;

	(void)value;
	(void)vm;
	(void)cursor;
	(void)pc;
	(void)i;
	return (dir_size);
}

static int32_t	get_reg(t_vm *vm, t_cursor *cursor, size_t pc, size_t i)
{	
	cursor->param[i] = vm->arena[pc % MEM_SIZE];
	ft_printf("param reg %02x\n", cursor->param[i]);
	return (1);
}

void			get_param(t_vm *vm, t_cursor *cursor, uint8_t op_cod, size_t pc)
{
	size_t		i;
	uint8_t		bytecode;
	uint8_t		bit_shift;

	i = 0;
	bit_shift = 6;
	if (g_op_tab[op_cod].bytecode == TRUE)
	{
		bytecode = vm->arena[cursor->pc + 1 % MEM_SIZE];
		while (bit_shift > 0)
		{
			if (bytecode & (0b01 << bit_shift))
				pc += get_reg(vm, cursor, pc, i);
			else if (bytecode & (0b10 << bit_shift))
				pc += get_dir(vm, cursor, pc, i, g_op_tab[op_cod].dir_size);
			else if (bytecode & (0b11 << bit_shift))
				pc += get_ind(vm, cursor, pc, i);
			bit_shift -= 2;
			i++;
		}
	}
	else
		get_dir(vm, cursor, pc, 0, g_op_tab[op_cod].dir_size);
}
