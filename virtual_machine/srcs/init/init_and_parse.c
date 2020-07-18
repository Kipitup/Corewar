/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 11:18:57 by amartinod         #+#    #+#             */
/*   Updated: 2020/07/18 15:20:41 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int8_t		get_player(t_vm *vm, size_t *i, char **av, size_t index)
{
	t_vector	*file;
	int8_t		ret;

	ret = check_file_name(av[*i], ft_strlen(av[*i]));
	if (ret == SUCCESS)
	{
		file = vct_newstr(av[*i]);
		if (file != NULL)
			ret = parse_file_and_get_info(vm, file, index);
		else
			ret = ft_perror_failure(MALLOC_ERR, __FILE__, __LINE__);
	}
	(*i)++;
	return (ret);
}

/*
** The first 4 bit of vm->option are used by the classic option, dump and visu.
** The last 4 are used to remember if a specific position was put with the "-n"
** option. So here: (vm->option & ((1 << position) << BITWISE_OPT_SHIFT)
** The BITWISE_OPT_SHIFT is there to skip the first 4 bit of the classic option.
**
** Also the position is decremented so it can be used as an index
*/

static int8_t		opt_position(t_vm *vm, size_t *i, size_t ac, char **av)
{
	ssize_t		position;
	int8_t		ret;

	(*i)++;
	ret = FAILURE;
	if (*i + 1 < ac)
	{
		position = get_nb(av[*i]);
		if (position > MAX_PLAYERS || position == 0)
			ft_perror(POSITION_OUT_OF_RANGE, __FILE__, __LINE__);
		else if ((vm->option & ((1 << position) << BITWISE_OPT_SHIFT)) != 0)
			ft_perror(INDEX_ALREADY_USED, __FILE__, __LINE__);
		else if (position != FAILURE)
		{
			vm->option |= ((1 << position) << BITWISE_OPT_SHIFT);
			ret = SUCCESS;
			(*i)++;
			ret = get_player(vm, i, av, position);
		}
	}
	else
		ft_perror(NO_ARG_FOR_N, __FILE__, __LINE__);
	return (ret);
}

static int8_t		opt_dump(t_vm *vm, size_t *i, size_t ac, char **av)
{
	ssize_t		nb;
	int8_t		ret;

	ret = FAILURE;
	vm->option &= ~OPT_RESET_DUMP;
	vm->option |= OPT_DUMP;
	vm->option |= (ft_strequ(av[*i], "-dump32") == TRUE)
		? OPT_DUMP32 : OPT_DUMP64;
	(*i)++;
	if (*i < ac)
	{
		nb = get_nb(av[*i]);
		if (nb != FAILURE)
		{
			ret = SUCCESS;
			vm->opt_dump = nb;
			(*i)++;
		}
	}
	else
		ft_perror(NO_ARG_FOR_DUMP, __FILE__, __LINE__);
	return (ret);
}

static int8_t		get_option(t_vm *vm, size_t *i, size_t ac, char **av)
{
	char		*str;
	int8_t		ret;

	ret = SUCCESS;
	str = av[*i];
	if (ft_strequ(str, "-visu") == TRUE)
	{
		vm->option |= OPT_VISU;
		(*i)++;
	}
	else if (ft_strequ(str, "-dump32") == TRUE)
		ret = opt_dump(vm, i, ac, av);
	else if (ft_strequ(str, "-dump64") == TRUE)
		ret = opt_dump(vm, i, ac, av);
	else if (ft_strequ(str, "-n") == TRUE)
		ret = opt_position(vm, i, ac, av);
	else
		ret = ft_perror_failure(INVALID_OPT, __FILE__, __LINE__);
	return (ret);
}

/*
** The address of i send in the function, so it incrementation is done there.
*/

t_vm				*init_and_parse(size_t ac, char **av)
{
	t_vm		*vm;
	size_t		i;
	int8_t		ret;

	i = 1;
	ret = SUCCESS;
	vm = malloc_vm_and_players();
	if (vm != NULL)
	{
		while (i < ac && ret == SUCCESS)
		{
			if (av[i][0] == '-')
				ret = get_option(vm, &i, ac, av);
			else
				ret = get_player(vm, &i, av, NO_SPECIFIC_POSITION);
		}
		if (ret == SUCCESS)
			ret = is_player_well_assigned(vm);
		if (ret == FAILURE)
			clean_vm(&vm);
	}
	return (vm);
}
