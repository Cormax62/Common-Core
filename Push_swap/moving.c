/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:34:31 by mbiagi            #+#    #+#             */
/*   Updated: 2025/02/04 14:59:28 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_cheappest(t_list *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest == 1)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	finish(t_list **stack, t_list *top, char c)
{
	while (*stack != top)
	{
		if (c == 'b')
		{
			if (top->above)
				rotate(NULL, stack, 0, 1);
			else
				reverse(NULL, stack, 0, 1);
		}
		if (c == 'a')
		{
			if (top->above)
				rotate(stack, NULL, 1, 0);
			else
				reverse(stack, NULL, 1, 0);
		}
	}
}

void	move(t_list **stack_a, t_list **stack_b)
{
	t_list	*a;
	t_list	*b;
	t_list	*cheap;

	a = *stack_a;
	b = *stack_b;
	cheap = find_cheappest(*stack_b);
	if (cheap->above && cheap->target->above)
		rotate(stack_a, stack_b, 1, 1);
	else if (!(cheap->above) && !(cheap->target->above))
		reverse(stack_a, stack_b, 1, 1);
	finish(stack_b, cheap, 'b');
	finish(stack_a, cheap->target, 'a');
	push(stack_a, stack_b, 1);
}
