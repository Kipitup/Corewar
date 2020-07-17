/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 18:57:20 by efischer          #+#    #+#             */
/*   Updated: 2020/07/17 19:04:56 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_token	*get_ocp_token(t_data *data)
{
	t_list	*token_lst;
	t_token	*token;

	token_lst = data->token_lst;
	while (token_lst->next != NULL)
		token_lst = token_lst->next;
	token = token_lst->content;
	if (token->type == E_OCP)
		return (token);
	return (NULL);
}

static void		add_arg_type_token(t_data *data, size_t i)
{
	static char	ocp[NB_OP] = {0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1};

	if (ocp[i] == 1)
		new_token(data, E_OCP, NULL, 1);
}

void			check_op_args(t_data *data, t_token *op_token, uint64_t ocp,
					size_t nb_args)
{
	t_token		*ocp_token;

	add_arg_type_token(data, op_token->type);
	ocp_token = get_ocp_token(data);
	if (ocp_token != NULL)
	{
		ocp_token->value = ft_itoa(ocp);
		check_op(data, op_token, ocp_token, nb_args);
		data->offset++;
	}
	else
		check_no_ocp_op(data, op_token->type, ocp);
}
