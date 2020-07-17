/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 12:43:06 by efischer          #+#    #+#             */
/*   Updated: 2020/07/17 12:56:56 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	get_file_content(t_data *data)
{
	ssize_t		ret;

	while ((ret = get_next_line(data->fd_s, &data->input)) > 0)
	{
		data->line++;
		data->column = 0;
		parser_asm(data);
		ft_strdel(&data->input);
	}
//	debug_label(data->label_lst);
	open_cor(data);
	fill_cor(data);
	debug_token(data->token_lst);
}
