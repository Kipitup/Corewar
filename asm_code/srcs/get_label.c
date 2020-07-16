/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_label.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 22:06:02 by efischer          #+#    #+#             */
/*   Updated: 2020/07/16 22:02:26 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	new_label(t_data *data, char *label_name)
{
	t_label	new_label;
	t_list	*new_lst;

	ft_bzero(&new_label, sizeof(t_label));
	new_label.name = label_name;
	new_lst = ft_lstnew(&new_label, sizeof(t_label));
	if (new_lst == NULL)
		exit_error(data, MALLOC_FAILURE);
	ft_lstaddend(&data->label_lst, new_lst);
}

void		get_label(t_data *data, char **split, size_t *index)
{
	size_t	len;

	len = ft_strlen(split[*index]);
	if (split[*index][len - 1] == LABEL_CHAR)
	{
		new_label(data, ft_strdup(split[*index]));
		data->column += len;
		(*index)++;
	}
}
