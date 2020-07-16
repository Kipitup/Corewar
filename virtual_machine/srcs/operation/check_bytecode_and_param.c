/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bytecode_and_param.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 18:12:42 by amartinod         #+#    #+#             */
/*   Updated: 2020/07/04 10:22:35 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

//ft_printf("bytecode       %08b\n", 2, bytecode);

/*
** The problem with the param type is that it doesn't match the parameter.
** As I said a parameter can either be 0b01, 0b10, or 0b11.
** But since a operation can take several type of parameter,
** 0b11 could either be 0b01 or 0b10.
** So the param type is either 0b001, 0b010 or 0b100.
** That is why if the bytecode == 3 (0b11), I increment it to 4 (0b100) to
** match the param type.
*/
static uint8_t		is_param_ok(uint8_t bytecode_chunk, uint8_t type_param)
{
	uint8_t 	ret;

	ret = FALSE;
	if (bytecode_chunk >= 0b01 && bytecode_chunk <= 0b11)
	{
		if (bytecode_chunk == 0b11)
			bytecode_chunk = 0b100;
		ret = bytecode_chunk & type_param;
	}
	return (ret);
}

/*
** The bytecode contain all the parameter type. The last 2 bits contains the
** the type of the first parameter and so on :
** 0b 00 00 00 00
**    1  2  3  4
** A parameter can either be 0b01, 0b10, or 0b11.
** The bytecode_chunk contain the 2 bits of the param type, hence the bit shift.
*/
uint8_t				check_bytecode_and_param(uint8_t op_code, uint8_t bytecode)
{
	uint8_t		ret;
	uint8_t		bytecode_chunk;

	ret = FALSE;
	if (g_op_tab[op_code].nb_param >= 1)
	{
		bytecode_chunk = (bytecode & 0b11000000) >> 6; 
		ret = is_param_ok(bytecode_chunk, g_op_tab[op_code].type_param[0]);
	}
	if (g_op_tab[op_code].nb_param >= 2 && ret != FALSE)
	{
		bytecode_chunk = (bytecode & 0b00110000) >> 4; 
		ret = is_param_ok(bytecode_chunk, g_op_tab[op_code].type_param[1]);
	}
	if (g_op_tab[op_code].nb_param >= 3 && ret != FALSE)
	{
		bytecode_chunk = (bytecode & 0b00001100) >> 2; 
		ret = is_param_ok(bytecode_chunk, g_op_tab[op_code].type_param[2]);
	}
	return (ret);
}
