/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 23:13:06 by efischer          #+#    #+#             */
/*   Updated: 2020/07/16 00:04:30 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	debug_label(t_list *label_lst)
{
	t_label *label;

	ft_putendl("\nDebug label list\n");
	while (label_lst != NULL)
	{
		label = label_lst->content;
		ft_printf("%s offset: %d\n", label->name, label->offset);
		label_lst = label_lst->next;
	}
}
