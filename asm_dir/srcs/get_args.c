/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 12:42:49 by efischer          #+#    #+#             */
/*   Updated: 2020/07/17 19:04:50 by efischer         ###   ########.fr       */
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

static void		get_op_args(t_data *data, char *merge, t_token *op_token)
{
	char		**split_arg;
	uint64_t	new_ocp;
	uint64_t	ocp;
	size_t		i;

	i = 0;
	ocp = 0;
	split_arg = ft_strsplit(merge, SEPARATOR_CHAR);
	while (split_arg[i] != NULL && i < MAX_ARGS_NUMBER)
	{
		new_ocp = get_next_arg(data, split_arg[i], op_token->type);
		ocp |= new_ocp << (6 - i * 2);
		i++;
	}
	del_array(split_arg);
	if (i == MAX_ARGS_NUMBER)
		exit_error(data, TOO_MUCH_ARG);
	check_op_args(data, op_token, ocp, i);
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
