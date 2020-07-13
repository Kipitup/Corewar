/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 12:00:11 by efischer          #+#    #+#             */
/*   Updated: 2020/07/13 12:47:58 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		main(int ac, char **av)
{
	char	*file_name;
	char	*file_content;

	if (ac == 2)
	{
		file_name = av[1];
		if (check_file_name(file_name) == false)
			return (EXIT_FAILURE);
		file_content = get_file_content(file_name);
		ft_putendl(file_content);
		ft_strdel(&file_content);
	}
	else
		return (usage_error(ac));
	return (EXIT_SUCCESS);
}
