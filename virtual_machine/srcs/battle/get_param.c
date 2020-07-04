/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 18:32:55 by amartinod         #+#    #+#             */
/*   Updated: 2020/07/04 13:52:49 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int32_t	get_ind(t_vm *vm, t_cursor *cursor, size_t pc, size_t i)
{
	uint32_t		value;

	value = 0;
	value = value | vm->arena[pc % MEM_SIZE];
	value = value << 8;
	value = value | vm->arena[(pc + 1) % MEM_SIZE];
	cursor->param[i] = value;
	ft_printf("param ind %02x\n", cursor->param[i]);
	return (IND_SIZE);
}

static int32_t	get_dir(t_vm *vm, t_cursor *cursor, size_t pc, size_t i,
		uint8_t dir_size )
{
	uint32_t		value;

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
	cursor->param[i] = value;
	ft_printf("param dir %02x\n", cursor->param[i]);
	return (dir_size);
}

uint8_t			get_param_with_bytecode(t_vm *vm, t_cursor *cursor, size_t pc,
		uint8_t bytecode)
{
	size_t		i;
	uint8_t		bit_shift;

	i = 0;
	bit_shift = 6;
	while (bit_shift > 0)
	{
		if (bytecode & (0b01 << bit_shift))
		{
			cursor->param[i] = vm->arena[pc % MEM_SIZE];
			ft_printf("param reg %02x\n", cursor->param[i]);
			if (cursor->param[i] < 1 || cursor->param[i] > REG_NUMBER)
				return (FALSE);
			pc++;
		}
		else if (bytecode & (0b10 << bit_shift))
			pc += get_dir(vm, cursor, pc, i, g_op_tab[cursor->op_code].dir_size);
		else if (bytecode & (0b11 << bit_shift))
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
