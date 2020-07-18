/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 10:32:07 by amartinod         #+#    #+#             */
/*   Updated: 2020/07/17 16:43:20 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		annonce_player(t_player **all_players)
{
	size_t		i;
	t_player	*p;

	i = 0;
	ft_printf("Introducing contestants...");
	while (i < MAX_PLAYERS && all_players[i] != NULL)
	{
		p = all_players[i];
		ft_printf("\n* Player %zu, weighing %zu bytes, \"%s\" (\"%s\") !", p->id,
				p->size, p->name->str, p->comment->str);
		i++;
	}
}

void		and_the_winner_is(t_vm *vm)
{
	t_player	*p;

	p = vm->all_players[vm->last_player_alive - 1];
	ft_printf("Contestant %d, \"%s\", has won !\n", p->id, p->name->str);
}
