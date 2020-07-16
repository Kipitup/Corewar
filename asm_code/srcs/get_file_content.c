/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 12:43:06 by efischer          #+#    #+#             */
/*   Updated: 2020/07/16 20:08:29 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	get_file_content(t_data *data)
{
	ssize_t		ret;

	data->line = -1;
	while ((ret = get_next_line(data->fd, &data->input)) > 0)
	{
		data->line++;
		data->column = 0;
		parser_asm(data);
		ft_strdel(&data->input);
	}
	debug_token(data->token_lst);
//	debug_label(data->label_lst);
}
