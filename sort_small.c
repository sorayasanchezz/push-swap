/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soraya <soraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:09:37 by soraya            #+#    #+#             */
/*   Updated: 2026/01/27 20:03:34 by soraya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
	if (first > second && second < third && third > first)
		sa(a);
	else if (first < second && second > third && third < first)
		rra(a);
	else if (first > second && second > third && third < first)
	{
		sa(a);
		rra(a);
	}
	else if (first < second && second > third && third > first)
	{
		rra(a);
		sa(a);
	}
	else if (first > second && second < third && third < first)
		ra(a);
}

static int	find_min_index(t_stack *a)
{
	t_node	*node;
	int		min_value;
	int		min_index;
	int		index;

	node = a->top;
	min_value = node->value;
	min_index = 0;
	index = 0;
	while (node)
	{
		if (node->value < min_value)
		{
			min_value = node->value;
			min_index = index;
		}
		node = node->next;
		index++;
	}
	return (min_index);
}

static void	push_min_to_b(t_stack *a, t_stack *b)
{
	int		index;

	index = find_min_index(a);
	if (index <= a->size / 2)
	{
		while (index--)
			ra(a);
	}
	else
	{
		while (index++ < a->size)
			rra(a);
	}
	pb(a, b);
}

void	sort_four(t_stack *a, t_stack *b)
{
	push_min_to_b(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	push_min_to_b(a, b);
	push_min_to_b(a, b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}
