/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 18:47:50 by amartinod         #+#    #+#             */
/*   Updated: 2020/06/23 18:58:01 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

ssize_t		get_nb(char *nb_str)
{
	ssize_t		nb;

	nb = 2;
	if (nb_str == NULL)
		return (FAILURE);
	else
		return (nb);
}
