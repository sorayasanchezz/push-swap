/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soraya <soraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:10:26 by soraya            #+#    #+#             */
/*   Updated: 2026/01/16 13:32:19 by soraya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free(char **array)
{
	int	j;

	j = -1;
	while (array[++j])
		free(array[j]);
	free(array);
}

static int	ft_wordcount(char const *s, char c)
{
	int		i;
	int		num1;

	i = 0;
	num1 = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			num1++;
		i++;
	}
	return (num1);
}

static char	**ft_write(char const *s, char c, char **array)
{
	int		i;
	int		num1;
	int		start;

	i = 0;
	num1 = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			start = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			array[num1] = ft_substr(s, start, (i + 1 - start));
			if (!array[num1])
			{
				ft_free(array);
				return (NULL);
			}
			num1++;
		}
		i++;
	}
	array[num1] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (NULL);
	array = malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!array)
		return (NULL);
	array = ft_write(s, c, array);
	return (array);
}
