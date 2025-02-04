/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:24:49 by mbiagi            #+#    #+#             */
/*   Updated: 2025/02/04 16:47:19 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_position(t_list *stack)
{
	int		i;
	int		half;
	t_list	*temp;

	i = 0;
	temp = stack;
	half = ft_lstsize(stack) / 2;
	if (stack == NULL)
		return ;
	while (temp)
	{
		temp->position = i;
		if (i < half)
			temp->above = 1;
		else
			temp->above = 0;
		temp = temp->next;
		i++;
	}
}

void	set_target(t_list *stack_a, t_list *stack_b)
{
	t_list	*a;
	t_list	*b;
	t_list	*temp;
	int		i;

	b = stack_b;
	while (b)
	{
		a = stack_a;
		i = 2147483647;
		while (a)
		{
			if ((a->n > b->n) && (a->n < i))
			{
				temp = a;
				i = a->n;
			}
			a = a->next;
		}
		if (i == 2147483647)
			b->target = find_min(stack_a);
		else
			b->target = temp;
		b = b->next;
	}
}

void	set_price(t_list *stack_a, t_list *stack_b)
{
	t_list	*a;
	t_list	*b;

	b = stack_b;
	a = stack_a;
	while (b)
	{
		b->price = b->position;
		if (!(b->above))
			b->price = ft_lstsize(stack_b) - b->position;
		if (b->target->above)
			b->price += b->target->position;
		else
			b->price += ft_lstsize(stack_a) - b->target->position;
		b = b->next;
	}
}

void	set_cheapest(t_list *stack_b)
{
	int		i;
	t_list	*b;
	t_list	*temp;

	i = 2147483647;
	if (stack_b == NULL)
		return ;
	b = stack_b;
	temp = b;
	while (b)
	{
		if (b->price < i)
		{
			temp = b;
			i = b->price;
		}
		b->cheapest = 0;
		b = b->next;
	}
	temp->cheapest = 1;
}

void	set(t_list **stack_a, t_list **stack_b)
{
	set_position(*stack_a);
	set_position(*stack_b);
	set_target(*stack_a, *stack_b);
	set_price(*stack_a, *stack_b);
	set_cheapest(*stack_b);
}
