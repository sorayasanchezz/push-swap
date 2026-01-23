/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soraya <soraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:10:26 by soraya            #+#    #+#             */
/*   Updated: 2026/01/22 21:22:09 by soraya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	sizesrc;

	i = 0;
	sizesrc = 0;
	while (src[i])
		i++;
	sizesrc = i;
	i = 0;
	if (size == 0)
		return (sizesrc);
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	i = 0;
	return (sizesrc);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	size;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		sub = malloc(1);
		if (!sub)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	if (len <= ft_strlen(&s[start]))
		size = len;
	else
		size = ft_strlen(&s[start]);
	sub = malloc(size + 1);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, &s[start], size + 1);
	return (sub);
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
				ft_free(&array);
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
