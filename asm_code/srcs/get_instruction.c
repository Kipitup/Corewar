/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 10:50:22 by efischer          #+#    #+#             */
/*   Updated: 2020/07/16 12:49:25 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	get_instruction(t_data *data)
{
	if (ft_strequ(data->input, "\0") == TRUE)
		return ;
	get_label(data);
	get_op(data);
	get_args(data);
	//check_op();
	//get_comment();
}
