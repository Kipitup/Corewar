/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 18:55:53 by efischer          #+#    #+#             */
/*   Updated: 2020/07/17 17:48:36 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_isblank(const char c)
{
	return (c == ' ' || c == '\t');
}

void	new_token(t_data *data, enum e_token type, char *value, size_t size)
{
	static size_t	op_offset;
	t_token			token;
	t_list			*lst_new;

	ft_bzero(&token, sizeof(t_token));
	if (type < 16)
		op_offset = data->offset;
	token.type = type;
	token.value = value;
	token.size = size;
	if (type == E_LABEL)
		token.cur_offset = op_offset;
	lst_new = ft_lstnew(&token, sizeof(t_token));
	if (lst_new == NULL)
		exit_error(data, MALLOC_FAILURE);
	ft_lstaddend(&data->token_lst, lst_new);
}

char	*ft_join_free(char *s1, char *s2, int op)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	if (op == 1)
		ft_strdel(&s1);
	else if (op == 2)
		ft_strdel(&s2);
	else
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	return (str);
}

void	ft_arrdel(char **array)
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

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (!alst || !new)
		return ;
	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	tmp = *alst;
	while ((*alst)->next != NULL)
		*alst = (*alst)->next;
	(*alst)->next = new;
	*alst = tmp;
}
