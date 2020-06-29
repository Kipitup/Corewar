/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_fight.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 18:34:53 by amartinod         #+#    #+#             */
/*   Updated: 2020/06/29 18:35:29 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		assign_new_opcode(t_vm *vm, t_cursor *cursor)
{
	(void)vm;
	(void)cursor;
}

static void		execute_operation(t_vm *vm, t_cursor *cursor)
{
	(void)vm;
	(void)cursor;
}

void			lets_fight(t_vm *vm, t_cursor *cursor)
{
	while (cursor != NULL)
	{
		if (cursor->wait_cycle == 0)
			assign_new_opcode(vm, cursor);
		if (cursor->wait_cycle > 0)
			cursor->wait_cycle--;
		if (cursor->wait_cycle == 0)
			execute_operation(vm, cursor);
		cursor = cursor->next;
	}
}

