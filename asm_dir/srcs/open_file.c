/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 11:42:51 by efischer          #+#    #+#             */
/*   Updated: 2020/07/17 09:52:06 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static size_t	ignore_parent_dir(const char *file_name)
{
	size_t	i;

	i = 0;
	while (file_name[i] != '\0'
		&& (file_name[i] == '.' || file_name[i] == '/'))
	{
		i++;
	}
	return (i);
}

static void		check_file_name(t_data *data)
{
	char	**split;
	size_t	index;

	index = ignore_parent_dir(data->file_name);
	split = ft_strsplit(data->file_name + index, '.');
	if (split[0] == NULL || ft_strequ(split[1], "s") == FALSE
		|| split[2] != NULL)
	{
		ft_arrdel(split);
		exit_error(data, INVALID_FILE_NAME);
	}
	ft_arrdel(split);
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
	char	**split;
	size_t	index;
	size_t	len;
	char	*tmp;

	index = ignore_parent_dir(data->file_name);
	split = ft_strsplit(data->file_name + index, '.');
	if (split == NULL)
		exit_error(data, MALLOC_FAILURE);
	len = ft_strlen(split[0]);
	tmp = ft_strndup(data->file_name, index + len);
	data->cor_name = ft_strjoin(tmp, ".cor");
	ft_strdel(&tmp);
	del_array(split);
}

void			open_cor(t_data *data)
{
	get_cor_name(data);
	data->fd_cor = open(data->cor_name, O_CREAT | O_TRUNC | O_RDWR, S_IRWXU);
	if (data->fd_cor == FAILURE)
		exit_error(data, OPEN_FAILURE);
}
