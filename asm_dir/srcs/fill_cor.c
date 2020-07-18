/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_cor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 09:53:33 by efischer          #+#    #+#             */
/*   Updated: 2020/07/17 11:46:54 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	write_nb(const t_data *data, const int content, const size_t size)
{
	size_t	i;

	i = 1;
	while (i < size + 1)
	{
		ft_putchar_fd((content >> 8 * (size - i)), data->fd_cor);
		i++;
	}
}

static void	write_null(const t_data *data, const size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		ft_putchar_fd('\0', data->fd_cor);
		i++;
	}
}

static void	write_str(const t_data *data, const char *content,
			const size_t size)
{
	size_t	i;

	i = 0;
	while (i < size && content[i] != '\0')
	{
		ft_putchar_fd(content[i], data->fd_cor);
		i++;
	}
	write_null(data, size - i);
}

static void	write_cor(const t_data *data, const t_token *token)
{
	if (token->type == E_STRING)
		write_str(data, token->value, token->size);
	else
		write_nb(data, ft_atoi(token->value), token->size);
}

void		fill_cor(t_data *data)
{
	t_list	*token_lst;

	replace_label_offset(data);
	ft_printf("Writing output program to %s\n", data->cor_name);
	token_lst = data->token_lst;
	write_nb(data, COREWAR_EXEC_MAGIC, 4);
	write_cor(data, token_lst->content);
	token_lst = token_lst->next;
	write_null(data, 4);
	write_nb(data, data->offset, 4);
	write_cor(data, token_lst->content);
	token_lst = token_lst->next;
	write_null(data, 4);
	while (token_lst != NULL)
	{
		write_cor(data, token_lst->content);
		token_lst = token_lst->next;
	}
}
