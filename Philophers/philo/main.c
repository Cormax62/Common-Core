/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:36:59 by mbiagi            #+#    #+#             */
/*   Updated: 2025/05/23 14:07:52 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*simulation(void *data)
{
	
}

void	start_meal(t_table *table)
{
	int	i;

	i = -1;
	if (table->max_dinner == 0)
		return ;
	else if (table->n_philo == 1)
		return ; //TODO
	else
		while (++i != table->n_philo)
			init_thread(&table->philo[i], CREATE);
	table->start_program = getcorrecttime();
	i = -1;
	while (++i != table->n_philo)
		init_thread(&table->philo[i], JOIN);
}

int	main(int arc, char **argv)
{
	t_table	table;

	if (arc != 5 && arc != 6)
		return (printf("WRONG NUMBER OF ARGUMENTS!!"), 1);
	if (parsing(argv) == 0)
		return (printf("NOT CORRECT ARGUMENT, PLEASE TRY AGAIN!!"), 1);
	table.n_philo = argv[1];
	table.t_death = ft_atol(argv[2]) * 1e3;
	table.t_eat = ft_atol(argv[3]) * 1e3;
	table.t_sleep = ft_atol(argv[4]) * 1e3;
	if (arc == 6)
		table.max_dinner = argv[5];
	else
		table.max_dinner = -1;
	init_table(&table, arc ,argv);
	init_philo(&table);
	start_meal(&table);
	return (0);
}
