/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soraya <soraya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:44:42 by soraya            #+#    #+#             */
/*   Updated: 2026/01/20 14:03:20 by soraya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int				nbr;
	struct s_list	*next;
	struct s_list	*prev;
}	t_node;

int		main(int argc, char **argv);
long	ft_atol(const char *nptr);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	check_args(int argc, char **argv);
char	*ft_strdup(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_free(char ***input);
void	error_exit(char ***input);

#endif