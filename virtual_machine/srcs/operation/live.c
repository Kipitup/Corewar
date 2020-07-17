/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:18:54 by amartinod         #+#    #+#             */
/*   Updated: 2020/07/17 22:56:00 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** The live function looks at the only parameter (DIR_CODE), if it is the number
** of a player it will then ping the vm that the player
** last_live_cycle = current_cycle.
*/

void		op_live(t_vm *vm, t_cursor *cursor)
{
	int32_t		num;
	uint8_t		nb_player;

	nb_player = 1;
	while (vm->all_players[nb_player - 1] != NULL && nb_player < MAX_PLAYERS)
		nb_player++;
	vm->live_counter++;
	cursor->last_live = vm->cycle_counter;
	num = -cursor->param[0];
	if (num > 0 && num <= nb_player)
	{
		vm->last_player_alive = num;
		ft_dprintf(STD_ERR, "last player alive is %d\n", num * -1);
	}
}
