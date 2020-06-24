/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 18:47:50 by amartinod         #+#    #+#             */
/*   Updated: 2020/06/24 10:57:44 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static uint8_t		is_it_all_digit(char *nb_str)
{
	size_t		i;
	size_t		len;
	int8_t		ret;

	i = (nb_str[0] == '-') ? 1 : 0;
	len = ft_strlen(nb_str);
	if (len == 0)
		return (FALSE);
	while (i < len)
	{
		ret = ft_isdigit(nb_str[i]);
		if (ret == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

ssize_t				get_nb(char *nb_str)
{
	ssize_t		nb;
	int64_t		tmp;

	nb = FAILURE;
	if (is_it_all_digit(nb_str) == TRUE)
	{
		tmp = ft_atol(nb_str);
		if (tmp <= INT_MAX && tmp >= 0 && ft_check_int_len(nb_str) == SUCCESS)
			nb = (ssize_t)tmp;
		else
			ft_perror(WRONG_OPT_VALUE, __FILE__, __LINE__);
	}
	else
		ft_perror(WRONG_OPT_VALUE, __FILE__, __LINE__);
	return (nb);
}
