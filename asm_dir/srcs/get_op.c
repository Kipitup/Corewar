/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 15:37:16 by efischer          #+#    #+#             */
/*   Updated: 2020/07/17 10:46:13 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	get_op(t_data *data, char **split, size_t *index)
{
	static char	*grammar[NB_OP] = {"live", "ld", "st", "add", "sub", "and",
									"or", "xor", "zjmp", "ldi", "sti", "fork",
									"lld", "lldi", "lfork", "aff"};
	size_t		i;
	
	i = 0;
	while (i < NB_OP)
	{
		if (ft_strequ(split[*index], grammar[i]) == TRUE)
		{
			data->column += ft_strlen(split[*index]) + 1;
			new_token(data, i, ft_itoa(i + 1), 1);
			break ;
		}
		i++;
	}
	if (i == NB_OP)
		exit_error(data, PARSE_ERROR);
	data->offset++;
	(*index)++;
}
