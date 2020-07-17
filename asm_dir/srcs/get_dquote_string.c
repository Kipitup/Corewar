/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dquote_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 17:58:10 by efischer          #+#    #+#             */
/*   Updated: 2020/07/17 14:49:00 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

//if enough time, manage multiple lines strings//

bool	is_end_line(char c)
{
	return (c == '\0' || c == COMMENT_CHAR || c ==';');
}

char	*get_dquote_string(t_data *data)
{
	char	*str;
	size_t	i;

	i = 0;
	data->column++;
	if (is_end_line(data->input[data->column]) == true)
		exit_error(data, PARSE_ERROR);
	while (is_end_line(data->input[data->column + i]) == false
		&& data->input[data->column + i] != '"')
	{
		i++;
	}
	if (is_end_line(data->input[data->column + i]) == true)
	{
		data->column += i;
		exit_error(data, PARSE_ERROR);
	}
	str = ft_strndup(data->input + data->column, i);
	if (str == NULL)
		str = ft_strdup("");
	if (str == NULL)
		exit_error(data, MALLOC_FAILURE);
	data->column += i + 1;
	return (str);
}
