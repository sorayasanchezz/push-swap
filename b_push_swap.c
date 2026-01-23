/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_push_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soraya <soraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:44:39 by soraya            #+#    #+#             */
/*   Updated: 2026/01/23 17:48:00 by soraya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		init_stack(t_stack *stack);
static t_node	*create_node(int value);
static int		push(t_stack *stack, int value);

int	main(int argc, char **argv)
{
	char	**input;
	t_stack	a;
	t_stack	b;
	int		i;

	input = check_args(argc, argv);
	init_stack(&a);
	init_stack(&b);
	i = 0;
	while (input[i])
		i++;
	while (--i >= 0)
	{
		if (!push(&a, ft_atol(input[i])))
		{
			ft_free_stack(&a);
			error_exit(&input);
		}
	}
	ft_free(&input);
	is_sorted(&a);
	ft_free_stack(&a);
	return (0);
}

static void	init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->size = 0;
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
