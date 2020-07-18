/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 12:42:49 by efischer          #+#    #+#             */
/*   Updated: 2020/07/18 11:01:17 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_token	*get_op_token(t_data *data)
{
	t_list	*token_lst;
	t_token	*token;

	token_lst = data->token_lst;
	while (token_lst->next != NULL)
		token_lst = token_lst->next;
	token = token_lst->content;
	return (token);
}

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

static void		get_op_args(t_data *data, char *merge, t_token *op_token)
{
	t_token		*ocp_token;
	size_t		nb_args;
	uint64_t	ocp;

	nb_args = 0;
	add_arg_type_token(data, op_token->type);
	ocp_token = get_ocp_token(data);
	ocp = get_arg_tokens(data, merge, op_token, &nb_args);
	if (ocp_token != NULL)
	{
		ocp_token->value = ft_itoa(ocp);
		check_op(data, op_token, ocp, nb_args);
		data->offset++;
	}
	else
		check_no_ocp_op(data, op_token->type, ocp);
}

void			get_args(t_data *data, char *merge)
{
	t_token		*op_token;

	merge = trim_side(merge);
	if (merge == NULL || *merge == '\0' || merge[ft_strlen(merge) - 1] == ',')
		exit_error(data, PARSE_ERROR);
	op_token = get_op_token(data);
	get_op_args(data, merge, op_token);
}
