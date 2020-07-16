/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 22:19:42 by efischer          #+#    #+#             */
/*   Updated: 2020/07/17 01:16:26 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	check_nb_args(t_data *data, const enum e_token type,
				const size_t nb_args)
{
	static size_t	args[NB_OP] = {1, 2, 2, 3, 3, 3, 3, 3, 1, 3, 3, 1, 2, 3, 1,
									1};

	if (args[type] > nb_args)
		exit_error(data, TOO_MUCH_ARG);
	if (args[type] < nb_args)
		exit_error(data, TOO_FEW_ARG);
}

static void	check_type_args(t_data *data, const enum e_token type,
				const uint32_t ocp)
{
	static uint32_t	types[NB_OP][3] = {{F_DIR, 0, 0}, {F_IND_DIR, F_REG, 0},
										{F_REG, F_REG_IND, 0}, {F_REG,
										F_REG, F_REG}, {F_REG, F_REG, F_REG},
										{F_ALL, F_ALL, F_REG}, {F_ALL, F_ALL,
										F_REG}, {F_ALL, F_ALL, F_REG}, {F_DIR,
										0, 0}, {F_ALL, F_REG_DIR, F_REG}, {F_REG,
										F_ALL, F_REG_DIR}, {F_DIR, 0, 0},
										{F_IND_DIR, F_REG, 0}, {F_ALL, F_REG_DIR,
										F_REG}, {F_DIR, 0, 0}, {F_REG, 0, 0}};
	uint32_t	arg1;
	uint32_t	arg2;
	uint32_t	arg3;

	(void)data;
	(void)type;
	(void)ocp;
	(void)types;
	if ((arg1 = ocp >> 6) == IND_CODE)
		arg1 = T_IND;
	if ((arg2 = ocp >> 4 & 0b11) == IND_CODE)
		arg1 = T_IND;
	if ((arg3 = ocp >> 2 & 0b11) == IND_CODE)
		arg1 = T_IND;
	if ((arg1 | types[type][0]) != arg1)
		exit_error(data, INVALID_ARG);
	if ((arg2 | types[type][1]) != arg2)
		exit_error(data, INVALID_ARG);
	if ((arg3 | types[type][2]) != arg3)
		exit_error(data, INVALID_ARG);
	ft_printf("arg1: %d, arg2: %d, arg3: %d\n", arg1, arg2, arg3);
}

void		check_op(t_data *data, const t_token *op_token,
				const t_token *ocp_token, const size_t nb_args)
{
	check_nb_args(data, op_token->type, nb_args);
	if (ocp_token != NULL)
		check_type_args(data, op_token->type, ft_atoi(ocp_token->value));
}
