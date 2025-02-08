/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:13:44 by mbiagi            #+#    #+#             */
/*   Updated: 2025/02/07 15:47:16 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	control_alg(t_list *stack_a)
{
	t_list	*stack_b;

	stack_b = NULL;
	if (ft_lstsize(stack_a) == 1)
		return (ft_free_lst(stack_a));
	else if ((ft_lstsize(stack_a) == 2) && (stack_a->n > (stack_a->next)->n))
		swap(&stack_a, &stack_b, 1, 0);
	else if (ft_lstsize(stack_a) == 3)
		alg_x_3(&stack_a, &stack_b);
	else if (ft_lstsize(stack_a) == 4)
		alg_x_4(&stack_a, &stack_b);
	else if (ft_lstsize(stack_a) == 5)
		alg_x_5(&stack_a, &stack_b);
	else
		serious_alg(&stack_a, &stack_b);
	ft_free_lst(stack_a);
}

void	handle_push2(t_list **stack_a, t_list **stack_b, t_list *s, t_list *t)
{
	t = *stack_a;
	if (t->next->n == s->n)
	{
		swap(stack_a, stack_b, 1, 0);
		push(stack_a, stack_b, 0);
		alg_x_4(stack_a, stack_b);
		push(stack_a, stack_b, 1);
	}
	else if (t->next->next->n == s->n)
	{
		rotate(stack_a, stack_b, 1, 0);
		swap(stack_a, stack_b, 1, 0);
		push(stack_a, stack_b, 0);
		alg_x_4(stack_a, stack_b);
		push(stack_a, stack_b, 1);
	}
	else
	{
		reverse(stack_a, stack_b, 1, 0);
		reverse(stack_a, stack_b, 1, 0);
		push(stack_a, stack_b, 0);
		alg_x_4(stack_a, stack_b);
		push(stack_a, stack_b, 1);
	}
}

void	alg_x_5(t_list **stack_a, t_list **stack_b)
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
		alg_x_4(stack_a, stack_b);
		push(stack_a, stack_b, 1);
	}
	else if (ft_lstlast(temp)->n == stack->n)
	{
		reverse(stack_a, stack_b, 1, 0);
		push(stack_a, stack_b, 0);
		alg_x_4(stack_a, stack_b);
		push(stack_a, stack_b, 1);
	}
	else
		handle_push2(stack_a, stack_b, stack, temp);
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
			swap(stack_a, stack_b, 1, 0);
		}
	}
	else
	{
		if ((*stack_a)->n < (temp->next)->n)
			swap(stack_a, stack_b, 1, 0);
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
	if (seq_control(head) == 1)
		return ;
	head = *stack_a;
	while ((*stack_a)->next != NULL)
	{
		if ((*stack_a)->n < ((*stack_a)->next)->n)
			n++;
		if (((*stack_a)->n < ((*stack_a)->next)->n) && (n == 1))
			temp = *stack_a;
		*stack_a = (*stack_a)->next;
	}
	if (n == 0)
	{
		rotate(&head, stack_b, 1, 0);
		swap(&head, stack_b, 1, 0);
	}
	else if (n == 1)
		alg_x_3_pt2(&head, stack_b, temp);
	*stack_a = head;
}
