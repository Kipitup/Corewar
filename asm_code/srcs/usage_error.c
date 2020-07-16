/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 12:13:41 by efischer          #+#    #+#             */
/*   Updated: 2020/07/13 13:14:37 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		usage_error(int ac)
{
	if (ac == 1)
		ft_perror(TOO_FEW_ARG, __FILE__, __LINE__);
	else
		ft_perror(TOO_MUCH_ARG, __FILE__, __LINE__);
	ft_putendl(USAGE);
	return (EXIT_FAILURE);
}
