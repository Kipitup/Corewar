/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:24:57 by amartinod         #+#    #+#             */
/*   Updated: 2020/07/17 14:21:33 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	Creates a copy of the process and place the PC of the new process is :
**	PC = (ARG1 (DIR_CODE) % IDX_MOD) + POS_OF_OLD_PROCESS.
*/

void		op_fork(t_vm *vm, t_cursor *cursor)
{
	t_cursor	*new_cursor;
	int32_t		arg_1;
	int32_t		address;

	arg_1 = cursor->param[0];
	address = cursor->pc + (arg_1 % IDX_MOD);
	new_cursor = fork_cursor(cursor, address);
	if (new_cursor != NULL)
	{
		new_cursor->next = vm->cursor;
		vm->cursor = new_cursor;
	}
}
