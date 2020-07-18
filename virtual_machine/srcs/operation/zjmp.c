/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:23:56 by amartinod         #+#    #+#             */
/*   Updated: 2020/07/18 16:41:19 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** If carry = 1 then PC = CUR_POS + (ARG1 (DIR_CODE) % IDX_MOD) else if carr = 0
** nothing is done.
*/

void		op_zjmp(t_vm *vm, t_cursor *cursor)
{
	int16_t		arg;
	int32_t		address;

	(void)vm;
	if (cursor->carry == TRUE)
	{
		arg = cursor->param[0];
		address = cursor->pc + (arg % IDX_MOD);
		cursor->pc = modulo(address, MEM_SIZE);
	}
}
