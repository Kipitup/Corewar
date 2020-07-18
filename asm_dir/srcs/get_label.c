/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_label.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 22:06:02 by efischer          #+#    #+#             */
/*   Updated: 2020/07/18 20:16:57 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

bool		check_label_char(const char *arg)
{
	size_t	i;

	i = 0;
	if (arg == NULL || arg[i] == '\0')
		return (false);
	while (arg[i] != '\0')
	{
		if (ft_strchr(LABEL_CHARS, arg[i]) == NULL)
			return (false);
		i++;
	}
	return (true);
}

bool		check_label_already_exists(t_data *data, const char *str)
{
	t_list	*label_lst;
	t_label	*label;

	label_lst = data->label_lst;
	while (label_lst != NULL)
	{
		label = label_lst->content;
		if (ft_strequ(str, label->name) == true)
			return (false);
		label_lst = label_lst->next;
	}
	return (true);
}

static void	new_label(t_data *data, char *label_name)
{
	t_label	new_label;
	t_list	*new_lst;

	ft_bzero(&new_label, sizeof(t_label));
	new_label.name = label_name;
	new_label.offset = data->offset;
	new_lst = ft_lstnew(&new_label, sizeof(t_label));
	if (new_lst == NULL)
		exit_error(data, MALLOC_FAILURE);
	ft_lstaddend(&data->label_lst, new_lst);
}

bool		get_label(t_data *data, char **split, size_t *index)
{
	char	*str;
	size_t	len;

	if (split[*index] == NULL)
		return (false);
	len = ft_strlen(split[*index]);
	if (split[*index][len - 1] == LABEL_CHAR)
	{
		str = ft_strndup(split[*index], len - 1);
		if (check_label_char(str) == false)
		{
			ft_strdel(&str);
			exit_error(data, WRONG_LABEL_NAME);
		}
		if (check_label_already_exists(data, str) == false)
		{
			ft_strdel(&str);
			exit_error(data, LABEL_ALREADY_EXIST);
		}
		new_label(data, str);
		data->column += len;
		(*index)++;
		return (true);
	}
	return (false);
}
