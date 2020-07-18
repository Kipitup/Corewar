/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 22:19:42 by efischer          #+#    #+#             */
/*   Updated: 2020/07/18 10:53:10 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		check_no_ocp_op(t_data *data, const enum e_token type,
				const uint64_t ocp)
{
	if (ocp > 0b10000000 && ocp != 0b11000000)
		exit_error(data, TOO_MUCH_ARG);
	if (type == E_AFF)
	{
		if (ocp != 0b01000000)
			exit_error(data, INVALID_ARG);
	}
	else
	{
		if (ocp != 0b10000000)
			exit_error(data, INVALID_ARG);
	}
}

static void	check_nb_args(t_data *data, const enum e_token type,
				const size_t nb_args)
{
	static size_t	args[NB_OP] = {1, 2, 2, 3, 3, 3, 3, 3, 1, 3, 3, 1, 2, 3, 1,
									1};

	if (args[type] > nb_args)
		exit_error(data, TOO_FEW_ARG);
	if (args[type] < nb_args)
		exit_error(data, TOO_MUCH_ARG);
}

static void	check_type_args(t_data *data, const enum e_token type,
				const uint32_t ocp)
{
	uint32_t		arg1;
	uint32_t		arg2;
	uint32_t		arg3;
	static uint32_t	types[NB_OP][3] = {{T_DIR, 0, 0}, {T_IND | T_DIR, T_REG, 0},
						{T_REG, T_REG | T_IND, 0}, {T_REG, T_REG, T_REG},
						{T_REG, T_REG, T_REG}, {T_REG | T_DIR | T_IND, T_REG
						| T_DIR | T_IND, T_REG}, {T_REG | T_DIR | T_IND, T_REG
						| T_DIR | T_IND, T_REG}, {T_REG | T_DIR | T_IND, T_REG
						| T_DIR | T_IND, T_REG}, {T_DIR, 0, 0}, {T_REG | T_DIR
						| T_IND, T_REG | T_DIR, T_REG}, {T_REG, T_REG | T_DIR
						| T_IND, T_REG | T_DIR}, {T_DIR, 0, 0}, {T_IND | T_DIR,
						T_REG, 0}, {T_REG | T_DIR | T_IND, T_REG | T_DIR,
						T_REG}, {T_DIR, 0, 0}, {T_REG, 0, 0}};

	if ((arg1 = ocp >> 6) == IND_CODE)
		arg1 = T_IND;
	if ((arg2 = ocp >> 4 & 0b11) == IND_CODE)
		arg2 = T_IND;
	if ((arg3 = ocp >> 2 & 0b11) == IND_CODE)
		arg3 = T_IND;
	if ((arg1 & types[type][0]) != arg1 || (arg2 & types[type][1]) != arg2
		|| (arg3 & types[type][2]) != arg3)
	{
		exit_error(data, INVALID_ARG);
	}
}

void		check_op(t_data *data, const t_token *op_token,
				const uint64_t ocp, const size_t nb_args)
{
	check_nb_args(data, op_token->type, nb_args);
	check_type_args(data, op_token->type, ocp);
}
