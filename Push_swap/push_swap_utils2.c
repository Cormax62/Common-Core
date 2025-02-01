/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:15:09 by mbiagi            #+#    #+#             */
/*   Updated: 2025/02/01 13:39:25 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_lst(t_list *lst)
{
	t_list	*temp;

	while (lst)
	{
		ft_printf("free %d\n", lst->n);
		temp = lst->next;
		free(lst);
		lst = temp;
	}
}

static long	ft_number(const char *c, int x, int sign)
{
	long	num;

	num = 0;
	while ((c[x] >= 48) && (c[x] <= 57))
	{
		num = num * 10 + (c[x] - '0');
		x++;
	}
	if (sign == 1)
		return (num * -1);
	return (num);
}

long	ft_atol(const char *nptr)
{
	int	x;
	int	sign;

	x = 0;
	sign = 0;
	while ((nptr[x] == 32) || ((nptr[x] >= 9) && (nptr[x] <= 13)))
		x++;
	if (nptr[x] == 43)
		x++;
	else if (nptr[x] == 45)
	{
		sign = 1;
		x++;
	}
	else if ((nptr[x] < 48) || (nptr[x] > 57))
		return (0);
	return (ft_number(nptr, x, sign));
}
