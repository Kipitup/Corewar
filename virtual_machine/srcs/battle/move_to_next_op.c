/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_next_op.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 15:44:13 by amartinod         #+#    #+#             */
/*   Updated: 2020/07/16 10:33:48 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** A parameter can either be 0b01 (register), 0b10 (direct), or 0b11 (indirect).
*/
void		move_to_next_op(t_vm *vm, t_cursor *cursor, uint8_t op_code)
{
	uint8_t		bytecode;
	uint8_t		bytecode_chunk;
	uint8_t		bit_shift;

	bit_shift = 6;
	cursor->pc++;
	if (g_op_tab[op_code].bytecode == TRUE)
	{
		bytecode = vm->arena[cursor->pc % MEM_SIZE];
		cursor->pc++;
		while (bit_shift > 0)
		{
			bytecode_chunk = (bytecode & (0b11 << bit_shift)) >> bit_shift;
			if (bytecode_chunk == 0b01)
				cursor->pc += 1;
			else if (bytecode_chunk == 0b10)
				cursor->pc += g_op_tab[op_code].dir_size;
			else if (bytecode_chunk == 0b11)
				cursor->pc += 2;
			bit_shift -= 2;
		}
	}
	else
		cursor->pc += g_op_tab[op_code].dir_size;
	cursor->pc = cursor->pc % MEM_SIZE;
}
