/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:43:37 by mbiagi            #+#    #+#             */
/*   Updated: 2025/01/29 17:51:30 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *stack_a, t_list *stack_b, bool a, bool b)
{
	int	bank;

	if (a == true)
	{
		if (ft_lstsize(stack_a) <= 1)
			return ;
		bank = stack_a->n;
		stack_a->n = (stack_a->next)->n;
		(stack_a->next)->n = bank;
	}
	if (b == true)
	{
		if (ft_lstsize(stack_b) <= 1)
			return ;
		bank = stack_b->n;
		stack_b->n = (stack_b->next)->n;
		(stack_b->next)->n = bank;
	}
	if ((a == true) && (b == true))
		ft_printf("ss\n");
	else if (a == true)
		ft_printf("sa\n");
	else if (b == true)
		ft_printf("sb\n");
}

void	push(t_list **stack_a, t_list **stack_b, bool c)
{
	t_list	*temp;

	if (c == true)
	{
		if (stack_b == NULL)
			return ;
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		ft_lstadd_front(stack_a, temp);
		free(temp);
		ft_printf("pa\n");
	}
	else if (c == false)
	{
		if (stack_a == NULL)
			return ;
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		ft_lstadd_front(stack_b, temp);
		free(temp);
		ft_printf("pb\n");
	}
}

void	rotate(t_list **stack_a, t_list **stack_b, bool a, bool b)
{
	t_list	*temp;

	if (a == true)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		temp->next = NULL;
		ft_lstadd_back(stack_a, temp);
	}
	if (b == true)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		temp->next = NULL;
		ft_lstadd_back(stack_b, temp);
	}
	if ((a == true) && (b == true))
		ft_printf("rr\n");
	else if (a == true)
		ft_printf("ra\n");
	else if (b == true)
		ft_printf("rb\n");
}

void	rr_funct(t_list **stack_b)
{
	t_list	*temp;
	t_list	*node;

	node = *stack_b;
	temp = ft_lstlast(*stack_b);
	ft_lstadd_front(stack_b, temp);
	while (node->next != temp)
		node = node->next;
	node->next = NULL;
}

void	reverse(t_list **stack_a, t_list **stack_b, bool a, bool b)
{
	t_list	*temp;
	t_list	*node;

	if (a == true)
	{
		node = *stack_a;
		temp = ft_lstlast(*stack_a);
		ft_lstadd_front(stack_a, temp);
		while (node->next != temp)
			node = node->next;
		node->next = NULL;
	}
	if (b == true)
		rr_funct(stack_b);
	if ((a == true) && (b == true))
		ft_printf("rrr\n");
	else if (a == true)
		ft_printf("rra\n");
	else if (b == true)
		ft_printf("rrb\n");
}
