/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soraya <soraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:18:01 by soraya            #+#    #+#             */
/*   Updated: 2026/01/16 19:26:40 by soraya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_numbers(int argc, char **input);

void	check_args(int argc, char **argv)
{
	char	**input;

	// si solo hay un argumento a tomar por culo
	if (argc == 1)
	{
		printf("exit 0");
		exit(0);
	}

	if (argc == 2)
		input = ft_split(argv[1], ' ');
	else
		input = argv + 1;

	if (check_numbers(argc, input) == 1)
	{
		printf("exit 1 porque no pasa el checkkk");
		exit(1);
	}

	int i = 0;
	while (input[i])
	{
		printf("%s\n", input[i]);
		i++;
	}
}

static int	check_numbers(int argc, char **input)
{
	int	i;
	int	j;

	i = 0;
	if (argc < 2)
		return (1);
	while (input[i])
	{
		if (input[i][0] == 0)
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
