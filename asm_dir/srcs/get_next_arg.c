/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 18:08:19 by efischer          #+#    #+#             */
/*   Updated: 2020/07/17 18:39:00 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

bool		is_number(char *s)
{
	if (*s == '-')
		s++;
	if (*s == '\0')
		return (false);
	while (*s != '\0')
	{
		if (ft_isdigit(*s) == false)
			return (false);
		s++;
	}
	return (true);
}

uint64_t	get_next_arg(t_data *data, char *arg, const enum e_token type)
{
	arg = trim_side(arg);
	if (arg[0] == DIRECT_CHAR)
		return (get_dir_arg(data, arg + 1, type));
	else if (arg[0] == 'r')
		return (get_reg_arg(data, arg + 1));
	return (get_ind_arg(data, arg));
}
