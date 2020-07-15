/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 12:00:11 by efischer          #+#    #+#             */
/*   Updated: 2020/07/15 17:33:42 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		ft_bzero(&data, sizeof(t_data));
		data.file_name = av[1];
		open_file(&data);
		get_file_content(&data);
		close(data.fd);
	}
	else
		return (usage_error(ac));
	return (EXIT_SUCCESS);
}
