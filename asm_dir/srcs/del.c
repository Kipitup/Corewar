/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 11:36:22 by efischer          #+#    #+#             */
/*   Updated: 2020/07/16 11:46:23 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	del_array(char **array)
{
	size_t	i;

	i = 0;
	while (array[i] != NULL)
	{
		ft_strdel(&array[i]);
		i++;
	}
	free(array);
}

void	del_token_lst(void *content, size_t content_size)
{
	t_token	*token;

	(void)content_size;
	token = content;
	ft_strdel(&token->value);
	free(content);
}

void	del_label_lst(void *content, size_t content_size)
{
	t_label	*label;

	(void)content_size;
	label = content;
	ft_strdel(&label->name);
	free(content);
}
