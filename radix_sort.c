/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soraya <soraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:08:01 by soraya            #+#    #+#             */
/*   Updated: 2026/01/30 09:45:45 by soraya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_stack *a)
{
	int	max_index;
	int	bits;

	max_index = a->size -1;
	bits = 0;
	while (max_index > 0)
	{
		max_index >>= 1;
		bits++;
	}
	return (bits);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	bits_max;
	int	i;
	int	size;
	int	bit;

	index_stack(a);
	bits_max = get_max_bits(a);
	bit = 0;
	while (bit < bits_max)
	{
		i = 0;
		size = a->size;
		while (i++ < size)
		{
			if (((a->top->index >> bit) & 1) == 0)
				pb(a, b);
			else
				ra(a);
		}
		while (b->size)
			pa(a, b);
		bit++;
	}
}