/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_fight.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 18:34:53 by amartinod         #+#    #+#             */
/*   Updated: 2020/07/18 11:14:02 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void			execute_operation(t_vm *vm, t_cursor *cursor)
{
	uint8_t		op_code;
	uint8_t		bytecode;
	uint8_t		ret;

	ret = TRUE;
	op_code = cursor->op_code;
	ft_dprintf(STD_ERR, "op_code to check %02x | cursor is on %zu\n", op_code, cursor->pc);
	if (op_code > 0 && op_code <= NB_OF_OPE)
	{
		if (g_op_tab[op_code].bytecode == TRUE)
		{
			bytecode = vm->arena[(cursor->pc + 1) % MEM_SIZE];
			ret = check_bytecode_and_param(op_code, bytecode);
		}
		if (ret != FALSE)
		{
			ft_dprintf(STD_ERR, "\n{c_yellow}ope: %s{c_end} cursor is on %zu\n", g_op_tab[op_code].name, cursor->pc);
			ret = get_param(vm, cursor, (cursor->pc + 1) % MEM_SIZE);
		}
		if (ret != FALSE)
			g_op_tab[op_code].op_func(vm, cursor);
		else
			ft_perror("Not a good param, go to next byte", __FILE__, __LINE__);
		if (op_code != OPE_ZJMP || cursor->carry == FALSE)
			move_to_next_op(vm, cursor, op_code);
	}
	else
		cursor->pc = (cursor->pc + 1) % MEM_SIZE;
}

void				lets_fight(t_vm *vm, t_cursor *cursor)
{
	while (cursor != NULL)
	{
		if (cursor->wait_cycle == 0)
		{
			cursor->op_code = vm->arena[cursor->pc];
			if (cursor->op_code <= NB_OF_OPE)
				cursor->wait_cycle = g_op_tab[cursor->op_code].wait_cycle;
		}
		if (cursor->wait_cycle > 0)
			cursor->wait_cycle--;
		if (cursor->wait_cycle == 0)
			execute_operation(vm, cursor);
		cursor = cursor->next;
	}
	ft_dprintf(STD_ERR, "|  ");
}
