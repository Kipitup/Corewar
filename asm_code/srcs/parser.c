/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 11:23:29 by efischer          #+#    #+#             */
/*   Updated: 2020/07/16 11:01:14 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	parser_asm(t_data *data)
{
	static void	(*fct[NB_STATE])(t_data*) = {get_name, get_comment,
												get_instruction};

	fct[data->state](data);
}
