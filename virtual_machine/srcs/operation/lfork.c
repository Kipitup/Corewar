/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:25:49 by amartinod         #+#    #+#             */
/*   Updated: 2020/07/18 15:28:22 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		op_lfork(t_vm *vm, t_cursor *cursor)
{
	t_cursor	*new_cursor;
	int16_t		arg_1;
	int32_t		address;

	arg_1 = cursor->param[0];
	address = cursor->pc + arg_1;
	new_cursor = fork_cursor(cursor, address);
	if (new_cursor != NULL)
	{
		new_cursor->next = vm->cursor;
		vm->cursor = new_cursor;
	}
	else
	{
		clean_vm(&vm);
		exit(EXIT_FAILURE);
	}
}
