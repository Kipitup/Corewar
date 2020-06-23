/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 11:18:57 by amartinod         #+#    #+#             */
/*   Updated: 2020/06/23 20:01:43 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int8_t		get_player(t_vm *vm, size_t *i, char **av, size_t position)
{
	int8_t		ret;

	ret = SUCCESS;
	(void)vm;
	(void)position;
	ft_printf("player %s\n",  av[*i]);
	(*i)++;
	return (ret);
}

static int8_t		opt_position_player(t_vm *vm, size_t *i, char **av)
{
	ssize_t		position;
	int8_t		ret;

	ret = SUCCESS;
	ft_printf("position %s\n",  av[*i]);
	(*i)++;
	ft_printf("position nb %s\n",  av[*i]);
	position = get_nb(av[*i]);
	if (position == FAILURE)
		ret = FAILURE;
	else
	{
		(*i)++;
		get_player(vm, i, av, position);
	}
	return (ret);
}

static int8_t		opt_dump(t_vm *vm, size_t *i, char **av, uint8_t dump_type)
{
	ssize_t		nb;
	int8_t		ret;

	ft_printf("dump %s\n",  av[*i]);

	ret = SUCCESS;
	vm->option |= OPT_DUMP;
	vm->option |= dump_type;
	(*i)++;
	nb = get_nb(av[*i]);
	if (nb == FAILURE)
		ret = FAILURE;
	else
	{
		ft_printf("dump nb %s\n",  av[*i]);
		vm->opt_dump = nb;
		(*i)++;
	}
	return (ret);
}

static int8_t		get_option(t_vm *vm, size_t *i, char **av)
{
	char 		*str;
	int8_t		ret;

	ret = SUCCESS;
	str = av[*i];
	if (ft_strequ(str, "-visu") == TRUE)
	{
		vm->option |= OPT_VISU;
		(*i)++;
		ft_printf("visu %s\n",  str);
	}
	else if (ft_strequ(str, "-dump32") == TRUE)
		ret = opt_dump(vm, i ,av, OPT_DUMP32);
	else if (ft_strequ(str, "-dump64") == TRUE)
		ret = opt_dump(vm, i, av, OPT_DUMP64);
	else if (ft_strequ(str, "-n") == TRUE)
		ret = opt_position_player(vm, i, av);
	else
		ret = ft_perror_failure("error", __FILE__, __LINE__);
	return (ret);
}

t_vm				*init(size_t ac, char **av)
{
	t_vm		*vm;
	size_t		i;
	int8_t		ret;

	i = 1;
	ret = SUCCESS;
	vm = ft_memalloc(sizeof(t_vm));
	if (vm != NULL)
	{
		while (i < ac && ret == SUCCESS)
		{
			if (av[i][0] == '-')
				ret = get_option(vm, &i, av);
			else
				ret = get_player(vm, &i, av, NO_SPECIFIC_POSITION);
		}
		if (ret == FAILURE)
			clean_vm(&vm);
	}
	return (vm);
}
