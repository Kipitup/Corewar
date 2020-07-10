/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 14:03:49 by amartinod         #+#    #+#             */
/*   Updated: 2020/07/10 20:36:32 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int8_t			parse_file_and_get_info(t_vm *vm, t_vector *file, size_t index)
{
	t_vector		*line;
	int				fd;	
	int8_t			ret;

	line = NULL;
	ret = TRUE;
	(void)vm;
	(void)index;
	return	(1);
	fd = open(vct_getstr(file), O_RDONLY);
	if (fd != FAILURE)
	{
		while (ret == TRUE)
		{
			ret = vct_read_line(STD_IN, &line);
			vct_del(&line);
		}
		vct_del(&line);
		vct_read_line(CLEANUP, &line);
	}
	else
		ret = ft_perror_failure(CANT_OPEN, __FILE__, __LINE__);
	return (ret);
}
