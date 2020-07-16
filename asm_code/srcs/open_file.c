/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 11:42:51 by efischer          #+#    #+#             */
/*   Updated: 2020/07/15 12:01:32 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	check_file_name(t_data *data)
{
	char	**split;

	split = ft_strsplit(data->file_name, '.');
	if (split[0] == NULL || ft_strequ(split[1], "s") == FALSE
		|| split[2] != NULL)
	{
		ft_arrdel(split);
		exit_error(data, INVALID_FILE_NAME);
	}
	ft_arrdel(split);
}

void		open_file(t_data *data)
{
	check_file_name(data);
	data->fd = open(data->file_name, O_RDONLY);
	if (data->fd == FAILURE)
		exit_error(data, OPEN_FAILURE);
}
