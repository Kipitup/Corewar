/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 11:05:47 by amartinod         #+#    #+#             */
/*   Updated: 2020/06/29 19:04:23 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		main(int ac, char **av)
{
	t_vm	*vm;

	if (ac > 1)
	{
		vm = init_and_parse((size_t)ac, av);
		if (vm != NULL)
			vm = set_up_arena(vm);
		if (vm != NULL)
		{
			annonce_player(vm->all_players);
			battle(vm);
			if (vm->nb_of_player_alive == 0)
				and_the_winner_is(vm);
		}
		clean_vm(&vm);
	}
	else
		ft_printf("Usage: \n");
	return (EXIT_SUCCESS);
}
