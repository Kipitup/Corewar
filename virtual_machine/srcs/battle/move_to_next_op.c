/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_next_op.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 15:44:13 by amartinod         #+#    #+#             */
/*   Updated: 2020/07/03 11:15:51 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** A parameter can either be 0b01 (register), 0b10 (direct), or 0b11 (indirect).
*/
void		move_to_next_op(t_vm *vm, t_cursor *cursor, uint8_t op_code)
{
	size_t		jump;
	uint8_t		bytecode;
	uint8_t		bit_shift;

	jump = 1;
	bit_shift = 6;
	if (g_op_tab[op_code].bytecode == TRUE)
	{
		jump++;
		bytecode = vm->arena[cursor->pc + 1 % MEM_SIZE];
		while (bit_shift > 0)
		{
			if (bytecode & (0b01 << bit_shift))
				jump += 1;
			else if (bytecode & (0b10 << bit_shift))
				jump += g_op_tab[op_code].dir_size;
			else if (bytecode & (0b11 << bit_shift))
				jump += 2;
			bit_shift -= 2;
		}
		cursor->pc += jump;
	}
	else
		cursor->pc += jump + g_op_tab[op_code].dir_size;
	cursor->pc = cursor->pc % MEM_SIZE;
}
