/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soraya <soraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 13:55:22 by soraya            #+#    #+#             */
/*   Updated: 2026/01/26 14:01:40 by soraya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stacks(t_stack *a, t_stack *b);
static int	push(t_stack *stack, int value);
static t_node	*create_node(int value);

void	build_stack_a(char **input, t_stack *a, t_stack *b)
{
	int	i;

	init_stacks(a, b);
	i = 0;
	while (input[i])
		i++;
	while (--i >= 0)
	{
		if (!push(a, ft_atol(input[i])))
		{
			ft_free_stack(a);
			error_exit(&input);
		}
	}
	ft_free(&input);
}

static void	init_stacks(t_stack *a, t_stack *b)
{
	a->top = NULL;
	a->size = 0;
	b->top = NULL;
	b->size = 0;
}

static int	push(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = create_node(value);
	if (!new_node)
		return (0);
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
	return (1);
}

static t_node	*create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->value = value;
	node->next = 0;
	return (node);
}