/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soraya <soraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 15:58:44 by soraya            #+#    #+#             */
/*   Updated: 2026/01/24 20:50:41 by soraya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_stack(t_stack *from, t_stack *to)
{
	t_node	*move;

	if (!to || !from || !from->top)
		return ;
	move = from->top;
	from->top = move->next;
	move->next = to->top;
	to->top = move;
	from->size--;
	to->size++;
}

void	pa(t_stack *a, t_stack *b)
{
	push_stack(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	push_stack(a, b);
	write(1, "pb\n", 3);
}
