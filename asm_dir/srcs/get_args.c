/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 12:42:49 by efischer          #+#    #+#             */
/*   Updated: 2020/07/17 15:12:11 by ffoissey         ###   ########.fr       */
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

static int		dir_size(const enum e_token type)
{
	static char	size[NB_OP] = {LONG_DIRECT_SIZE, LONG_DIRECT_SIZE,
			LONG_DIRECT_SIZE, LONG_DIRECT_SIZE, LONG_DIRECT_SIZE,
			LONG_DIRECT_SIZE, LONG_DIRECT_SIZE, LONG_DIRECT_SIZE,
			SMALL_DIRECT_SIZE, SMALL_DIRECT_SIZE, SMALL_DIRECT_SIZE,
			SMALL_DIRECT_SIZE, LONG_DIRECT_SIZE, SMALL_DIRECT_SIZE,
			SMALL_DIRECT_SIZE, LONG_DIRECT_SIZE};

	return (size[type]);
}

static _Bool	check_label_char(const char *arg)
{
	size_t	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (ft_strchr(LABEL_CHARS, arg[i]) == NULL)
			return (false);
		i++;
	}
	return (true);
}

bool			is_number(char *s)
{
	if (*s == '-')
		s++;
	if (*s == '\0')
		return (false);
	while (*s != '\0')
	{
		if (ft_isdigit(*s) == false)
			return (false);
		s++;
	}
	return (true);
}

static uint64_t	get_next_arg(t_data *data, char *arg, const enum e_token type)
{
	uint64_t	ocp;
	size_t		i;
	size_t		size;

	arg = trim_side(arg);
	i = 0;
	if (arg[0] == DIRECT_CHAR)
	{
		size = dir_size(type);
		if (arg[1] == LABEL_CHAR)
		{
			if (check_label_char(arg + 2) == false)
				exit_error(data, WRONG_LABEL_NAME);
			new_token(data, E_LABEL, ft_strdup(arg + 2), size);
		}
		else
		{
			if (is_number(arg + 1) == false)
				exit_error(data, PARSE_ERROR);
			new_token(data, E_DIR, ft_strdup(arg + 1), size);
		}
		ocp = DIR_CODE;
		data->offset += size;
	}
	else if (arg[0] == 'r')
	{
		while (ft_isdigit(arg[i + 1]) == TRUE)
			i++;
		if (arg[i + 1] != '\0')
			exit_error(data, PARSE_ERROR);
		new_token(data, E_REG, ft_strdup(arg + 1), REGISTER_SIZE);
		ocp = REG_CODE;
		data->offset += REGISTER_SIZE;
	}
	else
	{
		if (arg[0] == LABEL_CHAR)
		{
			if (check_label_char(arg + 1) == false)
				exit_error(data, WRONG_LABEL_NAME);
			new_token(data, E_LABEL, ft_strdup(arg + 1), INDIRECT_SIZE);
		}
		else
		{
			if (is_number(arg) == false)
				exit_error(data, PARSE_ERROR);
			new_token(data, E_IND, ft_strdup(arg), INDIRECT_SIZE);
		}
		ocp = IND_CODE;
		data->offset += INDIRECT_SIZE;
	}
	return (ocp);
}

void			get_args(t_data *data, char *merge)
{
	t_token 	*op_token;
	t_token		*ocp_token;
	char		**split_arg;
	uint64_t	ocp;	
	uint64_t	new_ocp;	
	size_t		i;

	i = 0;
	ocp = 0;
	op_token = get_op_token(data);
	add_arg_type_token(data, op_token->type);
	ocp_token = get_ocp_token(data);
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
	if (ocp_token != NULL)
	{
		ocp_token->value = ft_itoa(ocp);
		check_op(data, op_token, ocp_token, i);
		data->offset++;
	}
}
