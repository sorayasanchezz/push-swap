/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soraya <soraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:53:52 by soraya            #+#    #+#             */
/*   Updated: 2026/01/16 13:32:51 by soraya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
/* 
int	main(void)
{
	printf("%s", ft_substr("Hola que tal", 1, 49));
}
*/