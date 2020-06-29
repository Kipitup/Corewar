/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 10:32:07 by amartinod         #+#    #+#             */
/*   Updated: 2020/06/29 10:38:05 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		annonce_player(t_player **all_players)
{
	size_t		i;
	t_player	*p;

	i = 0;
	ft_printf("Introducing contestants...\n");
	while (all_players[i] != NULL)
	{
		p = all_players[i];
		ft_printf("* Player %zu, weighing %3zu bytes, \"%s\" (\"%s\")\n", p->id,
				p->size, p->name->str, p->comment->str);
		i++;
	}
}
