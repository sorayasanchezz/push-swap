/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_free.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soraya <soraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:04:22 by soraya            #+#    #+#             */
/*   Updated: 2026/01/22 20:57:43 by soraya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char ***input)
{
	int	i;

	i = -1;
	if (!input || !*input)
		return ;
	while ((*input)[++i])
		free((*input)[i]);
	free(*input);
	*input = NULL;
}

void	error_exit(char ***input)
{
	ft_free(input);
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_free_stack(t_stack *stack)
{
	t_node	*tmp;

	if (!stack)
		return ;
	while (stack->top)
	{
		tmp = stack->top;
		stack->top = stack->top->next;
		free(tmp);
	}
	stack->size = 0;
}
