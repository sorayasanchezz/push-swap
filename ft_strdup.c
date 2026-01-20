/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soraya <soraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 23:11:13 by soraya            #+#    #+#             */
/*   Updated: 2026/01/19 16:59:57 by soraya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(const char *s)
{
	char	*dup;

	dup = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s, (ft_strlen(s) + 1) * sizeof(char));
	return (dup);
}
