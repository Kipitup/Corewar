/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:23:00 by amartinod         #+#    #+#             */
/*   Updated: 2020/07/16 20:04:29 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		op_and(t_vm *vm, t_cursor *cursor)
{
	int32_t		arg_1;
	int32_t		arg_2;
	int32_t		arg_3;
	uint8_t		type_of_param;

	type_of_param = param_type(vm, cursor, FIRST_PARAM);
	arg_1 = get_param_when_3_possible_type(vm, cursor, 0, type_of_param);
	type_of_param = param_type(vm, cursor, SECOND_PARAM);
	arg_2 = get_param_when_3_possible_type(vm, cursor, 1, type_of_param);
	(void)arg_3;
}
