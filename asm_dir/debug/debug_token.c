/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:43:54 by efischer          #+#    #+#             */
/*   Updated: 2020/07/17 11:15:40 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	debug_token(t_list *token_lst)
{
	static char	*token_type[NB_TOKEN] = {"E_LIVE", "E_LD", "E_ST", "E_ADD",
										"E_SUB", "E_AND", "E_OR", "E_XOR",
										"E_ZJMP", "E_LDI", "E_STI", "E_FORK",
										"E_LLD", "E_LLDI", "E_LFORK", "E_AFF",
										"E_NAME_CMD", "E_COMMENT_CMD",
										"E_LABEL_CHAR", "E_DIRECT_CHAR",
										"E_SEPARATOR_CHAR", "E_STRING",
										"E_OCP", "E_REG", "E_DIR", "E_IND",
										"E_LABEL", "E_COMMENT"};
	t_token	*token;

	ft_putendl("\nDebug token lst\n");
	while (token_lst != NULL)
	{
		token = token_lst->content;
		ft_printf("[ %s ] -> %s ( %d )\n", token_type[token->type], token->value, token->size);
		token_lst = token_lst->next;
	}
}
