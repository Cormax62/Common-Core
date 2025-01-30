/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:45:51 by mbiagi            #+#    #+#             */
/*   Updated: 2025/01/29 16:58:40 by mbiagi           ###   ########.fr       */
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
# include <stdbool.h>

// typedef struct s_list
// {
// 	int				n;
// 	struct s_list	*next;
// }	t_list;

void	ft_free(char **matrix);
int		digit_control(char **split_c);
long	ft_atol(const char *nptr);
int		equals_control(char **c);
int		ft_matrixlen(char **matrix);
t_list	*one_str_handle(char *argv);
t_list	*one_str_handle(char *argv);
int		value_control(char **c);
long	ft_atol(const char *nptr);
void	reverse(t_list **stack_a, t_list **stack_b, bool a, bool b);
void	rr_funct(t_list **stack_b);
void	rotate(t_list **stack_a, t_list **stack_b, bool a, bool b);
void	push(t_list **stack_a, t_list **stack_b, bool c);
void	swap(t_list *stack_a, t_list *stack_b, bool a, bool b);
void	control_alg(t_list *stack_a);
void	alg_x_3(t_list **stack_a, t_list **stack_b);
void	alg_x_3_pt2(t_list **stack_a, t_list **stack_b, t_list * temp);
void	ft_free_lst(t_list *lst);

#endif