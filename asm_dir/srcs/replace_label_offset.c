/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_label_offset.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 11:01:27 by efischer          #+#    #+#             */
/*   Updated: 2020/07/17 13:35:11 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*label_offset(t_data *data, char *label_name, size_t cur_offset)
{
	t_list	*label_lst;
	t_label	*label;
	
	label_lst = data->label_lst;
	while (label_lst != NULL)
	{
		label = label_lst->content;
		if (ft_strequ(label->name, label_name) == TRUE)
		{
			ft_strdel(&label_name);
			return (ft_itoa(label->offset - cur_offset));
		}
		label_lst = label_lst->next;
	}
	return (NULL);
}

void		replace_label_offset(t_data *data)
{
	t_list	*token_lst;
	t_token	*token;

	token_lst = data->token_lst;
	while (token_lst != NULL)
	{
		token = token_lst->content;
		if (token->type == E_LABEL)
		{
			token->value = label_offset(data, token->value, token->cur_offset);
			if (token->value == NULL)
				exit_error(data, UNDEFINED_LABEL);
		}
		token_lst = token_lst->next;
	}
}
