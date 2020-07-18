/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_reg_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 18:21:32 by efischer          #+#    #+#             */
/*   Updated: 2020/07/17 18:38:39 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static bool		check_reg_number(const int reg_nb)
{
	return (reg_nb > 0 && reg_nb < REG_NUMBER);
}

uint64_t		get_reg_arg(t_data *data, char *arg)
{
	if (is_number(arg) == false)
		exit_error(data, PARSE_ERROR);
	if (check_reg_number(ft_atoi(arg)) == false)
		exit_error(data, WRONG_REG_NB);
	new_token(data, E_REG, ft_strdup(arg), REGISTER_SIZE);
	data->offset += REGISTER_SIZE;
	return (REG_CODE);
}
