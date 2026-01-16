/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soraya <soraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:36:21 by soraya            #+#    #+#             */
/*   Updated: 2026/01/16 13:53:10 by soraya           ###   ########.fr       */
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
/* 
int main(void)
{
    char    str[(8*8)];
    printf("%ld \n", strlcpy(str, "aaa", 0));
    printf("%ld \n", ft_strlcpy(str, "aaa", 0));
}
  */