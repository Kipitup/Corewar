/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 15:37:16 by efischer          #+#    #+#             */
/*   Updated: 2020/07/16 14:53:18 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	get_op(t_data *data)
{
	static char	*grammar[NB_OP] = {"live", "ld", "st", "add", "sub", "and",
									"or", "xor", "zjmp", "ldi", "sti", "fork",
									"lld", "lldi", "lfork", "aff"};
	char		**split;
	size_t		i;
	
	i = 0;
	split = ft_split_white_spaces(data->input + data->column);
	while (i < NB_OP)
	{
		if (ft_strequ(split[0], grammar[i]) == TRUE)
		{
			data->column += ft_strlen(split[0]) + 1;
			new_token(data, i, ft_itoa(i + 1));
			break ;
		}
		i++;
	}
	if (i == NB_OP)
		exit_error(data, PARSE_ERROR);
	del_array(split);
}
