/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testeos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soraya <soraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 20:46:05 by soraya            #+#    #+#             */
/*   Updated: 2026/01/23 17:28:36 by soraya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack	*stack)
{
	t_node	*tmp;

	tmp = stack->top;
	if (!stack || !stack->top)
	{
		printf("Stack vacío\n");
		return ;
	}
	printf("top -> final: ");
	while (tmp)
	{
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
}
