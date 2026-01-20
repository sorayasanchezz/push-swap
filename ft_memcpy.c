/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soraya <soraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:59:55 by soraya            #+#    #+#             */
/*   Updated: 2026/01/19 17:00:42 by soraya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
/* 
int main(void)
{
    
    char    fr[13] = "abcdefghi";
    char    *dest = &fr[1];
    char    *src = &fr[3];
    
    char    fr2[13] = "abcdefghi";
    char    *dest2 = &fr2[1];
    char    *src2 = &fr2[3];

    memcpy(dest, src, 3);
    printf("%s \n", fr);
    ft_memcpy(dest2, src2, 3);
    printf("%s \n", fr2);

}
 */