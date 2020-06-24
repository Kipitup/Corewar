/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 11:05:47 by amartinod         #+#    #+#             */
/*   Updated: 2020/06/24 10:49:15 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		main(int ac, char **av)
{
	t_vm	*vm;

	if (ac > 1)
	{
		vm = init((size_t)ac, av);
		if (vm != NULL)
		{
			(void)vm;
		}
	}
	else
		ft_printf("Usage: \n");
	return (0);
}