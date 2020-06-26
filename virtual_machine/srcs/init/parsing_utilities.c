/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 18:47:50 by amartinod         #+#    #+#             */
/*   Updated: 2020/06/26 14:56:20 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

ssize_t				get_nb(char *nb_str)
{
	ssize_t		nb;
	int64_t		tmp;

	nb = FAILURE;
	if (ft_is_str_a_number(nb_str) == TRUE)
	{
		tmp = ft_atol(nb_str);
		if (tmp <= INT_MAX && tmp >= 0 && ft_check_int_len(nb_str) == SUCCESS)
			nb = (ssize_t)tmp;
		else
			ft_perror(WRONG_OPT_VALUE, __FILE__, __LINE__);
	}
	else
		ft_perror(WRONG_OPT_VALUE, __FILE__, __LINE__);
	return (nb);
}

int8_t				check_file_name(char *file, size_t len)
{
	int8_t		ret;

	if (len < MINIMUM_LEN)
		ret = ft_perror_failure(NOT_VALID_FILE, __FILE__, __LINE__);
	else if (ft_strequ(file + len - 4, ".cor") == FALSE)
		ret = ft_perror_failure(WRONG_EXTENSION, __FILE__, __LINE__);
	else if (ft_strchr(file, ' ') != NULL || ft_strchr(file, '\n') != NULL
			|| ft_strchr(file, '\t') != NULL)
	{
		ret = ft_perror_failure(INCORRECT_FILE_NAME, __FILE__, __LINE__);
	}
	else
		ret = SUCCESS;
	return (ret);
}

uint8_t				hexa(t_vector *file, size_t i)
{
	return ((uint8_t)vct_getchar_at(file, i));
}

t_vm				*malloc_vm_and_players(void)
{
	t_vm		*vm;

	vm = ft_memalloc(sizeof(t_vm));
	if (vm != NULL)
		vm->all_players = ft_memalloc(sizeof(t_player*) * MAX_PLAYERS);
	if (vm == NULL || vm->all_players == NULL)
		ft_perror_failure(MALLOC_ERR, __FILE__, __LINE__);
	return (vm);
}

int8_t				is_player_well_assigned(t_vm *vm)
{
	size_t		i;
	int8_t		ret;
	uint8_t		is_free;

	i = 0;
	ret = SUCCESS;
	is_free = FALSE;
	while (i < MAX_PLAYERS)
	{
		if (vm->all_players[i] == NULL)
			is_free = TRUE;
		else if (is_free == TRUE)
			ret = ft_perror_failure(WRONG_POSITION, __FILE__, __LINE__);
		i++;
	}
	return (ret);
}
