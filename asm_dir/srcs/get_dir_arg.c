/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 18:10:59 by efischer          #+#    #+#             */
/*   Updated: 2020/07/17 18:41:09 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		dir_size(const enum e_token type)
{
	static char	size[NB_OP] = {LONG_DIRECT_SIZE, LONG_DIRECT_SIZE,
			LONG_DIRECT_SIZE, LONG_DIRECT_SIZE, LONG_DIRECT_SIZE,
			LONG_DIRECT_SIZE, LONG_DIRECT_SIZE, LONG_DIRECT_SIZE,
			SMALL_DIRECT_SIZE, SMALL_DIRECT_SIZE, SMALL_DIRECT_SIZE,
			SMALL_DIRECT_SIZE, LONG_DIRECT_SIZE, SMALL_DIRECT_SIZE,
			SMALL_DIRECT_SIZE, LONG_DIRECT_SIZE};

	return (size[type]);
}

uint64_t		get_dir_arg(t_data *data, char *arg, const enum e_token type)
{
	size_t		size;

	size = dir_size(type);
	if (arg[0] == LABEL_CHAR)
	{
		if (check_label_char(arg + 1) == false)
			exit_error(data, WRONG_LABEL_NAME);
		new_token(data, E_LABEL, ft_strdup(arg + 1), size);
	}
	else
	{
		if (is_number(arg) == false)
			exit_error(data, PARSE_ERROR);
		new_token(data, E_DIR, ft_strdup(arg), size);
	}
	data->offset += size;
	return (DIR_CODE);
}
