/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 15:34:13 by efischer          #+#    #+#             */
/*   Updated: 2020/07/17 10:42:31 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	get_name_cmd(t_data *data)
{
	if (ft_strstr(data->input, NAME_CMD_STRING) != data->input)
		exit_error(data, PARSE_ERROR);
	data->column += ft_strlen(NAME_CMD_STRING);
}

static void	get_name_str(t_data *data)
{
	char	*token_value;
	size_t	len;

	while (data->input[data->column] != '\0'
		&& ft_isblank(data->input[data->column]) == TRUE)
	{
		data->column++;
	}
	if (data->input[data->column] == '\0' || data->input[data->column] != '"')
		exit_error(data, PARSE_ERROR);
	token_value = get_dquote_string(data);
	len = ft_strlen(token_value);
	if (len > PROG_NAME_LENGTH)
		exit_error(data, TOO_LONG_NAME);
	new_token(data, E_STRING, token_value, PROG_NAME_LENGTH);
	data->column += len;
}

void		get_name(t_data *data)
{
	get_name_cmd(data);
	get_name_str(data);
	data->state++;
}
