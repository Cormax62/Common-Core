/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:45:51 by mbiagi            #+#    #+#             */
/*   Updated: 2025/01/27 12:07:45 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include "./printf/ft_printf.h"

# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
# include <strings.h>
# include <string.h>
# include <bsd/string.h>
# include <fcntl.h>
# include <unistd.h>
# include <linux/stat.h>
# include <sys/stat.h>
# include <stddef.h>
# include <X11/X.h>
# include <X11/keysym.h>

void	ft_free(char **matrix);
int		digit_control(char **split_c);
long	ft_atol(const char *nptr);
int		equals_control(char **c);
void	one_str_handle(char *argv);
void	one_str_handle(char *argv);
int		value_control(char **c);
long	ft_atol(const char *nptr);

// typedef struct s_stack_a
// {
// 	int					n;
// 	struct s_stack_a	next;	
// }	t_stack_a;

// typedef struct s_stack_b
// {
// 	int					n;
// 	struct s_stack_b	next;	
// }	t_stack_b;

#endif