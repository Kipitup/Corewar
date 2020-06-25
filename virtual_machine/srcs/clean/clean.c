/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 11:07:28 by amartinod         #+#    #+#             */
/*   Updated: 2020/06/25 18:21:42 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			clean_carriage(t_carriage **carriage)
{
	t_carriage	*tmp;
	t_carriage	*to_del;

	if (carriage != NULL && *carriage != NULL)
	{
		to_del = *carriage;
		while (to_del != NULL)
		{
			tmp = to_del->next;
			free(to_del);
			to_del = tmp;
		}
	}
}

static void		free_player(t_player *player)
{
	if (player != NULL)
	{
		vct_del(&(player->name));
		vct_del(&(player->comment));
		if (player->exec != NULL)
			ft_memdel((void**)&(player->exec));
	}
}

void			clean_player(t_player **player)
{
	if (player != NULL)
	{
		free_player(*player);
		free(*player);
		player = NULL;
	}
}

void 			clean_vm(t_vm **vm)
{
	t_vm		*tmp;
	size_t		i;

	i = 0;
	if (vm != NULL && *vm != NULL)
	{
		tmp = *vm;
		if (tmp->all_players != NULL)
		{
			while (i < MAX_PLAYERS)
			{
				free_player(tmp->all_players[i]);
				i++;
			}
			free(tmp->all_players);
		}
		clean_carriage(&(tmp->carriage));
		free(*vm);
		vm = NULL;
	}
}
