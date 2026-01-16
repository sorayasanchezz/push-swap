/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soraya <soraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:44:39 by soraya            #+#    #+#             */
/*   Updated: 2026/01/16 18:37:53 by soraya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//función que comprueba que cada argumento dado son números


int	main(int argc, char **argv)
{
	//char	**input;
	//int		i;
	//long	num;

	check_args(argc, argv);
/* 
	i = 1;
	while (argv[i])
	{
		printf("Antes: %s\n", argv[i]);
		num = ft_atol(argv[i]);
		printf("Después: %ld\n", num);
		if (num < -2147483648 || num > 2147483647)
		{
			printf("return 1\n");
			return (1);			
		}
		i++;
	}
	*/
	//printf("son numeros rtn 0\n");
	return (0); 
}
