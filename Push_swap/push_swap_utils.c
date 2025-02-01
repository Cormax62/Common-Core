/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:07:14 by mbiagi            #+#    #+#             */
/*   Updated: 2025/02/01 11:27:19 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_matrixlen(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

void	ft_free(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free (matrix[i]);
		matrix[i] = NULL;
		i++;
	}
	free (matrix);
}

int	equals_control(char **c)
{
	int	j;
	int	n;

	j = 0;
	while (c[j])
	{
		n = 1;
		while (c[j + n])
		{
			if (ft_strncmp(c[j], c[j + n], 100) == 0)
				return (0);
			n++;
		}
		j++;
	}
	return (1);
}

int	digit_control(char **split_c)
{
	int	i;
	int	j;

	j = 0;
	while (split_c[j])
	{
		i = 0;
		while (split_c[j][i])
		{
			if (((split_c[j][i] == '+') || (split_c[j][i] == '-')) && i == 0)
				i++;
			if (ft_isdigit(split_c[j][i]) == 0)
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	value_control(char **c)
{
	int		i;
	long	n;

	i = 0;
	while (c[i])
	{
		n = ft_atol(c[i]);
		if ((n < -2147483648) || (n > 2147483647))
			return (0);
		i++;
	}
	return (1);
}
