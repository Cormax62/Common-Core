/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:13:44 by mbiagi            #+#    #+#             */
/*   Updated: 2025/01/29 18:00:15 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	control_alg(t_list *stack_a)
{
	t_list	*stack_b;
	// t_list	*temp;

	// temp = stack_a;
	stack_b = NULL;
	if ((ft_lstsize(stack_a) == 2) && (stack_a->n > (stack_a->next)->n))
		swap(stack_a, stack_b, 1, 0);
	if (ft_lstsize(stack_a) == 3)
		alg_x_3(&stack_a, &stack_b);
	ft_free_lst(stack_a);
}

void	alg_x_3_pt2(t_list **stack_a, t_list **stack_b, t_list *temp)
{
	t_list	*back;

	if (temp->n == (*stack_a)->n)
	{
		back = ft_lstlast(*stack_a);
		if ((back)->n < temp->n)
			reverse(stack_a, stack_b, 1, 0);
		else
		{
			reverse(stack_a, stack_b, 1, 0);
			swap(*stack_a, *stack_b, 1, 0);
		}
	}
	else
	{
		if ((*stack_a)->n < (temp->next)->n)
			swap(*stack_a, *stack_b, 1, 0);
		else
			rotate(stack_a, stack_b, 1, 0);
	}
}

void	alg_x_3(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	t_list	*head;
	int		n;

	n = 0;
	head = *stack_a;
	while ((*stack_a)->next != NULL)
	{
		if ((*stack_a)->n < ((*stack_a)->next)->n)
			n++;
		if (((*stack_a)->n < ((*stack_a)->next)->n) && (n == 1))
			temp = *stack_a;
		*stack_a = (*stack_a)->next;
	}
	// if (n == 2)
	// 	return (*stack_a = head);
	if (n == 0)
	{
		rotate(&head, stack_b, 1, 0);
		swap(head, *stack_b, 1, 0);
	}
	else if (n == 1)
		alg_x_3_pt2(&head, stack_b, temp);
	*stack_a = head;
}
