/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:47:26 by mbiagi            #+#    #+#             */
/*   Updated: 2025/02/08 11:51:42 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_push(t_list **stack_a, t_list **stack_b, t_list *stack)
{
	t_list	*temp;

	temp = *stack_a;
	if (temp->next->n == stack->n)
	{
		swap(stack_a, stack_b, 1, 0);
		push(stack_a, stack_b, 0);
		alg_x_3(stack_a, stack_b);
		push(stack_a, stack_b, 1);
	}
	else
	{
		reverse(stack_a, stack_b, 1, 0);
		reverse(stack_a, stack_b, 1, 0);
		push(stack_a, stack_b, 0);
		alg_x_3(stack_a, stack_b);
		push(stack_a, stack_b, 1);
	}
}

void	alg_x_4(t_list **stack_a, t_list **stack_b)
{
	t_list	*stack;
	t_list	*temp;

	temp = *stack_a;
	stack = *stack_a;
	if (seq_control(stack) == 1)
		return ;
	stack = find_min(stack);
	if (temp->n == stack->n)
	{
		push(stack_a, stack_b, 0);
		alg_x_3(stack_a, stack_b);
		push(stack_a, stack_b, 1);
	}
	else if (ft_lstlast(temp)->n == stack->n)
	{
		reverse(stack_a, stack_b, 1, 0);
		push(stack_a, stack_b, 0);
		alg_x_3(stack_a, stack_b);
		push(stack_a, stack_b, 1);
	}
	else
		handle_push(stack_a, stack_b, stack);
}

void	serious_alg(t_list **stack_a, t_list **stack_b)
{
	t_list	*min;
	int		small;

	if (seq_control(*stack_a) == 1)
		return ;
	push_nodes(stack_a, stack_b);
	while (*stack_b)
	{
		set(stack_a, stack_b);
		move(stack_a, stack_b);
	}
	set_position(*stack_a);
	min = find_min(*stack_a);
	small = min->n;
	if (min->above)
		while (((*stack_a)->n != min->n) && ((*stack_a)->n != small))
			rotate(stack_a, stack_b, 1, 0);
	else
		while (((*stack_a)->n != min->n) && ((*stack_a)->n != small))
			reverse(stack_a, stack_b, 1, 0);
}
