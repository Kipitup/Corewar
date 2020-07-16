/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:23:56 by amartinod         #+#    #+#             */
/*   Updated: 2020/07/16 23:32:45 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** If carry = 1 then PC = CUR_POS + (ARG1 (T_DIR) % IDX_MOD) else if carr = 0
** nothing is done.
*/

void		op_zjmp(t_vm *vm, t_cursor *cursor)
{
	int32_t		arg;
	int32_t		address;

	(void)vm;
	ft_printf("carry is %d\n", cursor->carry);
	if (cursor->carry == TRUE)
	{
		arg = cursor->param[0];
		address = cursor->pc + (arg % IDX_MOD);
		cursor->pc = address % MEM_SIZE;
	}
}
