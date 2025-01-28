/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:45:44 by mbiagi            #+#    #+#             */
/*   Updated: 2025/01/28 08:46:57 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	create_lst(char **c)
// {
// 	int	n;
// 	n = ft_matrixlen(c);
// }

void	more_str_handle(char **argv)
{
	if ((digit_control(argv) == 0) || (equals_control(argv) == 0) ||\
	(value_control(argv) == 0))
		return (ft_putstr_fd("Error\n[invalid argument]", 2));
	ft_printf("Daje tuuto giusto");
	// create_lst(argv);
}

void	one_str_handle(char *argv)
{
	char	**split_c;
	
	if (argv[0] == '\0')
		return (ft_putstr_fd("Error\n[invalid argument]", 2));
	split_c = ft_split(argv, ' ');
	if ((digit_control(split_c) == 0) || (equals_control(split_c) == 0) ||\
	(value_control(split_c) == 0))
	{
		ft_free(split_c);
		return (ft_putstr_fd("Error\n[invalid argument]", 2));
	}
	// create_lst(split_c);
	ft_printf("Daje tutto giusto");
	free(split_c);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	else if (argc == 2)
		one_str_handle(argv[1]);
	else if (argc > 2)
		more_str_handle(&argv[1]);
	return (0);
}
