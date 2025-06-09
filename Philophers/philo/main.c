/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 10:27:22 by mbiagi            #+#    #+#             */
/*   Updated: 2025/06/09 08:37:42 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*socrate(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	mutex_handle(&philo->table->fork[philo->fork[0]], LOCK);
	set_long(&philo->philo_mutex, &philo->last_dinner_time,
		philo->table->start_program);
	write_status(FORK, philo);
	sleeping(philo->table->t_death, philo->table);
	write_status(DIED, philo);
	mutex_handle(&philo->table->fork[philo->fork[0]], UNLOCK);
	return (NULL);
}

void	*simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	desyncronized(philo->table->start_program);
	if (philo->id % 2 == 0)
		thinking(philo, true);
	while (!get_bool(&philo->table->table_mutex, &philo->table->end_program))
	{
		eating(philo);
		thinking(philo, false);
	}
	return (NULL);
}

static void	lonely_philo(t_philo *philo)
{
	pthread_create(&philo->thread_id, NULL, socrate, philo);
	pthread_join(philo->thread_id, NULL);
}

void	start_meal(t_table *table)
{
	int	i;

	i = -1;
	table->start_program = getcorrecttime();
	if (table->max_dinner == 0)
		return ;
	else if (table->n_philo == 1)
		return (lonely_philo(&table->philo[0]));
	else
	{
		while (++i != table->n_philo)
		{
			table->philo[i].last_dinner_time = table->start_program;
			init_thread(&table->philo[i].thread_id, CREATE, &table->philo[i]);
		}
	}
	pthread_create(&table->monitor, NULL, referee, table);
	i = -1;
	while (++i < table->n_philo)
		init_thread(&table->philo[i].thread_id, JOIN, NULL);
	init_thread(&table->monitor, JOIN, NULL);
	set_bool(&table->table_mutex, &table->end_program, true);
}

int	main(int arc, char **argv)
{
	t_table	table;

	if (arc != 5 && arc != 6)
		return (printf("WRONG NUMBER OF ARGUMENTS!!\n"), 1);
	if (parsing(argv) == 0 || ft_atol(argv[1]) == 0)
		return (printf("NOT CORRECT ARGUMENT, PLEASE TRY AGAIN!!\n"), 1);
	table.n_philo = ft_atol(argv[1]);
	table.t_death = ft_atol(argv[2]) * 1e3;
	table.t_eat = ft_atol(argv[3]) * 1e3;
	table.t_sleep = ft_atol(argv[4]) * 1e3;
	if (arc == 6)
		table.max_dinner = ft_atol(argv[5]);
	else
		table.max_dinner = -1;
	init_table(&table);
	init_philo(&table);
	start_meal(&table);
	clear(&table);
	return (0);
}
