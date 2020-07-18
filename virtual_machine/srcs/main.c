/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 11:05:47 by amartinod         #+#    #+#             */
/*   Updated: 2020/07/18 18:05:05 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		usage(void)
{
	ft_printf("Usage: ./corewar -visu [(-dump32 | -dump64) n_cycles] \
[(-n num) champ1.cor] ...\n");
}

int				main(int ac, char **av)
{
	t_vm	*vm;

	if (ac > 1)
	{
		vm = init_and_parse((size_t)ac, av);
		if (vm != NULL)
			vm = set_up_arena(vm);
		if (vm != NULL)
		{
			if ((vm->option & OPT_VISU) == 0)
				annonce_player(vm->all_players);
			battle(vm);
			if (vm->nb_of_player_alive == 0)
				and_the_winner_is(vm);
		}
		clean_vm(&vm);
	}
	else
		usage();
	return (EXIT_SUCCESS);
}
