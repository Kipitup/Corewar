/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 14:03:49 by amartinod         #+#    #+#             */
/*   Updated: 2020/06/24 17:38:22 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static t_vector		*get_file(char *file_name)
{
	t_vector		*line;
	t_vector		*file;
	int32_t			fd;
	int8_t			ret;

	ret = TRUE;
	line = NULL;
	file = NULL;
	fd = open(file_name, O_RDWR);
	if (fd != FAILURE)
	{
		while (ret == TRUE)
		{
			ret = vct_read_line(fd, &line);
			file = vct_joinfree(&file, &line, BOTH);
			if (file == NULL)
				ret = ft_perror_failure(MALLOC_ERR, __FILE__, __LINE__);
		}
		vct_del(&line);
		vct_read_line(CLEANUP, &line);
	}
	else
		ft_perror("can't open the file", __FILE__, __LINE__);
	return (file);
}

int8_t			parse_file_and_get_info(t_vm *vm, t_vector *name, size_t index)
{
	t_vector		*file;
	int8_t			ret;

	(void)vm;
	(void)index;
	ret = SUCCESS;
	file = get_file(vct_getstr(name));
	vct_dprint_debug(STD_ERR, file);
	return (ret);
}
