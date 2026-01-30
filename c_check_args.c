/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_check_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soraya <soraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:18:01 by soraya            #+#    #+#             */
/*   Updated: 2026/01/29 18:46:02 by soraya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_numbers(char **input);
static char	**input_numbers(int argc, char **argv);
static int	detect_duplicates(char **input);

char	**check_args(int argc, char **argv)
{
	char	**input;
	int		i;
	long	num;

	if (argc < 2)
		exit(0);
	if (argc == 2)
		input = ft_split(argv[1], ' ');
	else
		input = input_numbers(argc - 1, argv + 1);
	if (!input)
		error_exit(&input);
	if (check_numbers(input) == 1)
		error_exit(&input);
	i = 0;
	while (input[i])
	{
		num = ft_atol(input[i]);
		if (num < INT_MIN || num > INT_MAX)
			error_exit(&input);
		i++;
	}
	if (detect_duplicates(input) == 1)
		error_exit(&input);
	return (input);
}

static int	check_numbers(char **input)
{
	int	i;
	int	j;

	i = 0;
	while (input[i])
	{
		if (!input[i][0])
			return (1);
		j = 0;
		if ((input[i][j] == '+' || input[i][j] == '-')
			&& (input[i][j + 1] >= '0' && input[i][j + 1] <= '9'))
			j++;
		while (input[i][j])
		{
			if (input[i][j] < '0' || input[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static char	**input_numbers(int argc, char **argv)
{
	char	**input;
	int		i;

	i = 0;
	input = malloc(sizeof(char *) * (argc + 1));
	if (!input)
		return (NULL);
	while (i != argc)
	{
		input[i] = ft_strdup(argv[i]);
		if (!input[i])
		{
			ft_free(&input);
			return (NULL);
		}
		i++;
	}
	input[i] = 0;
	return (input);
}

static int	detect_duplicates(char **input)
{
	int		i;
	int		j;
	long	long_i;
	long	long_j;

	i = 0;
	while (input[i])
	{
		long_i = ft_atol(input[i]);
		j = i + 1;
		while (input[j])
		{
			long_j = ft_atol(input[j]);
			if (long_i == long_j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_sorted(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top;
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	ft_free_stack(stack);
	write(1, "Sorted\n", 7);
	exit(0);
}
