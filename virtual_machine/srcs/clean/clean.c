/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 11:07:28 by amartinod         #+#    #+#             */
/*   Updated: 2020/06/24 11:04:00 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		clean_carriage(t_carriage *carriage)
{
	if (carriage != NULL)
	{
		(void)carriage;
	}
}

static void		clean_player(t_player *all_player)
{
	if (all_player != NULL)
	{
		(void)all_player;
	}
}

void 			clean_vm(t_vm **vm)
{
	clean_player((*vm)->all_player);
	clean_carriage((*vm)->carriage);
	free(*vm);
	vm = NULL;
}
