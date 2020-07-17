/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_white_spaces.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 16:18:58 by efischer          #+#    #+#             */
/*   Updated: 2019/08/05 16:18:59 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != ' ' && s[i] != '\t')
		{
			count++;
			while (s[i] != ' ' && s[i] != '\t' && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (count);
}

static void	ft_fill_tab(char **tab, char const *s)
{
	unsigned int	i;
	unsigned int	j;
	size_t			len;

	j = 0;
	while (*s != '\0')
	{
		if (*s != ' ' && *s != '\t')
		{
			i = 0;
			len = 0;
			while (s[len] != ' ' && s[len] != '\t' && s[len] != '\0')
				len++;
			if (!(tab[j] = (char *)malloc(sizeof(char) * (len + 1))))
			{
				tab = NULL;
				return ;
			}
			while (i < len)
				tab[j][i++] = *s++;
			tab[j++][i] = '\0';
		}
		else
			s++;
	}
}

char		**ft_split_white_spaces(char const *s)
{
	unsigned int	count;
	char			**tab;

	if (s == NULL)
		return (NULL);
	count = count_word(s);
	if (count == 0)
		return (NULL);
	tab = (char**)malloc(sizeof(char*) * (count + 1));
	if (tab == NULL)
		return (NULL);
	ft_fill_tab(tab, s);
	tab[count] = 0;
	return (tab);
}
