/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 12:42:49 by efischer          #+#    #+#             */
/*   Updated: 2020/07/16 20:14:41 by efischer         ###   ########.fr       */
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
	static char	ocp[NB_OP] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1};

	if (ocp[i] == 1)
		new_token(data, E_OCP, NULL);
}

/*static int		dir_size(enum e_token type)
{
	static char	size[NB_OP] = {4, 4, 4, 4, 4, 4, 4, 4, 2, 2, 2, 2, 4, 2, 2, 4};

	return (size[type]);
}*/

static uint64_t	get_next_arg(t_data *data, char *arg)
{
	uint64_t	ocp;
	size_t		i;

	i = 0;
	if (arg[0] == DIRECT_CHAR)
	{
		if (arg[1] == LABEL_CHAR)
			new_token(data, E_LABEL, ft_strdup(arg + 2));
		else
			new_token(data, E_ARG, ft_strdup(arg + 1));
		ocp = DIR_CODE;
	}
	else if (arg[0] == 'r')
	{
		while (ft_isdigit(arg[i + 1]) == TRUE)
			i++;
		if (arg[i + 1] != '\0')
			exit_error(data, PARSE_ERROR);
		new_token(data, E_ARG, ft_strdup(arg + 1));
		ocp = REG_CODE;
	}
	else
	{
		if (arg[0] == LABEL_CHAR)
			new_token(data, E_LABEL, ft_strdup(arg + 1));
		else
		{
			while (ft_isdigit(arg[i]) == TRUE)
				i++;
			if (arg[i] != '\0')
			{
				ft_putendl(arg);
				exit_error(data, PARSE_ERROR);
			}
			new_token(data, E_ARG, ft_strdup(arg));
		}
		ocp = IND_CODE;
	}
	return (ocp);
}

void			get_args(t_data *data)
{
	t_token 	*op_token;
	t_token		*ocp_token;
	char		**split;
	char		**split_arg;
	uint64_t	ocp;	
	uint64_t	new_ocp;	
	size_t		i;

	i = 0;
	ocp = 0;
	op_token = get_op_token(data);
	add_arg_type_token(data, op_token->type);
	ocp_token = get_ocp_token(data);
	split = ft_split_white_spaces(data->input + data->column);
	split_arg = ft_strsplit(split[0], SEPARATOR_CHAR);
	while (split_arg[i] != NULL && i < MAX_ARGS_NUMBER)
	{
		new_ocp = get_next_arg(data, split_arg[i]);
		ocp |= new_ocp << (6 - i * 2);
		i++;
	}
	del_array(split);
	del_array(split_arg);
	if (i == MAX_ARGS_NUMBER)
		exit_error(data, TOO_MUCH_ARG);
	if (ocp_token != NULL)
		ocp_token->value = ft_itoa(ocp);
}
