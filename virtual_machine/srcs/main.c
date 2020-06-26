/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 11:05:47 by amartinod         #+#    #+#             */
/*   Updated: 2020/06/26 17:58:48 by amartinod        ###   ########.fr       */
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
			print_all_player_and_option(vm);
			print_cursor(vm->cursor);
			if (vm->option & OPT_DUMP)
				dump_option(vm);
			clean_vm(&vm);
		}
	}
	else
		ft_printf("Usage: \n");
	return (EXIT_SUCCESS);
}
