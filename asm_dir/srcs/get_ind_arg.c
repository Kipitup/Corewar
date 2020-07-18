/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ind_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 18:26:33 by efischer          #+#    #+#             */
/*   Updated: 2020/07/17 18:38:51 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

uint64_t	get_ind_arg(t_data *data, char *arg)
{
	if (arg[0] == LABEL_CHAR)
	{
		if (check_label_char(arg + 1) == false)
			exit_error(data, WRONG_LABEL_NAME);
		new_token(data, E_LABEL, ft_strdup(arg + 1), INDIRECT_SIZE);
	}
	else
	{
		if (is_number(arg) == false)
			exit_error(data, PARSE_ERROR);
		new_token(data, E_IND, ft_strdup(arg), INDIRECT_SIZE);
	}
	data->offset += INDIRECT_SIZE;
	return (IND_CODE);
}
