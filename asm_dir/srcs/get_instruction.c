/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 10:50:22 by efischer          #+#    #+#             */
/*   Updated: 2020/07/17 17:53:50 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*trim_side(char *s)
{
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (ft_isblank(*s) == true)
		s++;
	i = ft_strlen(s);
	if (i-- == 0)
		return (NULL);
	while (i >= 0 && ft_isblank(*(s + i)) == true)
	{
		s[i] = '\0';
		i--;
	}
	return (s);
}

char	*merge_tab(char **tab, size_t i)
{
	char	*merge;
	char	*tmp;

	if (tab[i] == NULL)
		return (NULL);
	merge = ft_strdup(tab[i++]);
	while (tab[i] != NULL && tab[i][0] != COMMENT_CHAR && tab[i][0] != ';')
	{
		merge = ft_join_free(merge, tab[i], 1);
		if ((tmp = ft_strchr(merge, COMMENT_CHAR))
			|| (tmp = ft_strchr(merge, ';')))
		{
			*tmp = '\0';
			break ;
		}
		i++;
		if (tab[i] != NULL)
			merge = ft_join_free(merge, " ", 1);
	}
	return (merge);
}

void	get_instruction(t_data *data)
{
	char	**split;
	char	*input;
	char	*merge;
	size_t	i;

	i = 0;
	if (ft_strequ(data->input, "\0") == TRUE)
		return ;
	input = ft_strdup(trim_side(data->input));
	free(data->input);
	data->input = input;
	split = ft_split_white_spaces(data->input);
	while (get_label(data, split, &i) == true)
		;
	if (split[i] != NULL)
	{
		get_op(data, split, &i);
		merge = merge_tab(split, i);
		if (merge == NULL)
			exit_error(data, NO_ARG);
		get_args(data, merge);
		i++;
		ft_strdel(&merge);
	}
	del_array(split);
}
