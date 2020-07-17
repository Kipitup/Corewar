/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 11:42:51 by efischer          #+#    #+#             */
/*   Updated: 2020/07/17 17:58:47 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		check_file_name(t_data *data)
{
	const char	*file_name = data->file_name;
	size_t		len;

	if (file_name == NULL || (len = ft_strlen(file_name)) < 3
		|| ft_strnequ(file_name + len - 2, ".s", 2) == false)
		exit_error(data, INVALID_FILE_NAME);
}

void			open_file(t_data *data)
{
	check_file_name(data);
	data->fd_s = open(data->file_name, O_RDONLY);
	if (data->fd_s == FAILURE)
		exit_error(data, OPEN_FAILURE);
}

static void		get_cor_name(t_data *data)
{
	size_t	len;

	len = ft_strlen(data->file_name);
	data->cor_name = ft_strnew(len + 2);
	if (data->cor_name == NULL)
		exit_error(data, MALLOC_FAILURE);
	ft_strncpy(data->cor_name, data->file_name, len - 2);
	ft_strncpy(data->cor_name + len - 2, ".cor", 4);
}

void			open_cor(t_data *data)
{
	get_cor_name(data);
	data->fd_cor = open(data->cor_name, O_CREAT | O_TRUNC | O_RDWR, S_IRWXU);
	if (data->fd_cor == FAILURE)
		exit_error(data, OPEN_FAILURE);
}
