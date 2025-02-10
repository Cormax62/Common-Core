/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:10:01 by mbiagi            #+#    #+#             */
/*   Updated: 2025/02/08 14:21:57 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_lst(t_list *lst)
{
	t_list	*temp;

	while (lst)
	{
		temp = lst->next;
		free(lst);
		lst = temp;
	}
}

t_list	*find_min(t_list *stack)
{
	int		n;
	t_list	*temp;
	t_list	*min;

	n = 2147483647;
	temp = stack;
	if (stack == NULL)
		return (NULL);
	while (temp)
	{
		if (n > temp->n)
		{
			n = temp->n;
			min = temp;
		}
		temp = temp->next;
	}
	return (min);
}

int	seq_control(t_list *stack)
{
	int		num;
	t_list	*temp;

	num = 1;
	temp = stack;
	while (stack->next)
	{
		if (stack->n < (stack->next)->n)
			num++;
		else
			num = 0;
		stack = stack->next;
	}
	if (num == ft_lstsize(temp))
		return (1);
	else
		return (0);
}

void	push_nodes(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_a) > 3)
		push(stack_a, stack_b, 0);
	alg_x_3(stack_a, stack_b);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
