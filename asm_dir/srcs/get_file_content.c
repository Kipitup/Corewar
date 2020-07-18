/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 12:43:06 by efischer          #+#    #+#             */
/*   Updated: 2020/07/18 15:50:26 by efischer         ###   ########.fr       */
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
	t_vector	*vct;
	size_t		len;

	while ((ret = vct_read_line(data->fd_s, &vct)) > 0)
	{
		data->input = ft_strdup(vct_getstr(vct));
		len = vct_len(vct);
		vct_del(&vct);
		if (ft_strlen(data->input) < len)
			exit_error(data, PARSE_ERROR);
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
