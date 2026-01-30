/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_push_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soraya <soraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:44:39 by soraya            #+#    #+#             */
/*   Updated: 2026/01/30 09:52:57 by soraya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	select_algorithm(t_stack *a, t_stack *b);

int	main(int argc, char **argv)
{
	char	**input;
	t_stack	a;
	t_stack	b;

	input = check_args(argc, argv);
	build_stack_a(input, &a, &b);
	is_sorted(&a);
	select_algorithm(&a, &b);
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}

static void	select_algorithm(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sa(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 4)
		sort_four(a, b);
	else if (a->size == 5)
		sort_five(a, b);
	else if (a->size > 5)
		radix_sort(a, b);
}
