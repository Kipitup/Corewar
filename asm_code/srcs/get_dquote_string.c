/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dquote_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 17:58:10 by efischer          #+#    #+#             */
/*   Updated: 2020/07/15 18:33:57 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

//if enough time, manage multiple lines strings//

char	*get_dquote_string(t_data *data)
{
	char	*str;
	size_t	i;

	i = 0;
	data->column++;
	if (data->input[data->column] == '\0')
		exit_error(data, PARSE_ERROR);
	while (data->input[data->column + i] != '\0'
		&& data->input[data->column + i] != '"')
	{
		i++;
	}
	if (data->input[data->column + i] == '\0'
		|| data->input[data->column + i + 1] != '\0')
	{
		data->column += i;
		exit_error(data, PARSE_ERROR);
	}
	str = ft_strndup(data->input + data->column, i);
	if (str == NULL)
		exit_error(data, MALLOC_FAILURE);
	data->column += i + 1;
	return (str);
}
