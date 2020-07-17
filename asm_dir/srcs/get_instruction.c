/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 10:50:22 by efischer          #+#    #+#             */
/*   Updated: 2020/07/17 09:08:34 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	get_instruction(t_data *data)
{
	char	**split;
	size_t	i;

	i = 0;
	if (ft_strequ(data->input, "\0") == TRUE)
		return ;
	split = ft_split_white_spaces(data->input);
	get_label(data, split, &i);
	get_op(data, split, &i);
	get_args(data, split, &i);
	//get_comment();
	del_array(split);
}
