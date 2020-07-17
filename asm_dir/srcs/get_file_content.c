/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 12:43:06 by efischer          #+#    #+#             */
/*   Updated: 2020/07/17 18:00:15 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

bool	is_empty_line(char *s)
{
	if (s == NULL)
		return (true);
	while (*s != '\0' && ft_isblank(*s) == true)
		s++;
	return (*s == '\0' || *s == COMMENT_CHAR || *s == ';');
}

void	get_file_content(t_data *data)
{
	ssize_t		ret;

	while ((ret = get_next_line(data->fd_s, &data->input)) > 0)
	{
		data->line++;
		data->column = 0;
		if (is_empty_line(data->input) == false)
			parser_asm(data);
		ft_strdel(&data->input);
	}
	if (data->offset == 0)
		exit_error(data, NO_INSTRUCTION);
	open_cor(data);
	fill_cor(data);
}
