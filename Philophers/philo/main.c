/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:36:59 by mbiagi            #+#    #+#             */
/*   Updated: 2025/05/27 15:26:03 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*socrate(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while(!get_bool(&philo->table->table_mutex, &philo->table->syncronized))
		;
	set_long(&philo->philo_mutex, &philo->last_dinner_time, getcorrecttime());
	write_status(FORK, philo);
	while (!get_bool(&philo->table->table_mutex, &philo->table->end_program))
		usleep(200);
	return (NULL);
}

void	*referee(void *data)
{
	int		i;
	t_table	*table;
	// long	r_threads;

	i = -1;
	table = (t_table *)data;
	while (!all_threads_running(table))
		;
	while (!get_bool(&table->table_mutex, &table->end_program))
	{
		while (++i < table->n_philo && !get_bool(&table->table_mutex, \
		&table->end_program))
		{
			if (suicide(table->philo + i))
			{
				set_bool(&table->table_mutex, &table->end_program, true);
				write_status(DIED, table->philo + i);
			}
		}
	}
	return (NULL);
}

void	*simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while(!get_bool(&philo->table->table_mutex, &philo->table->syncronized))
		;
	set_long(&philo->philo_mutex, &philo->last_dinner_time, getcorrecttime());
	set_long(&philo->table->table_mutex, &philo->table->running_threads, \
	philo->table->running_threads + 1);
	desyncronized(philo);
	while(!get_bool(&philo->table->table_mutex, &philo->table->end_program))
	{
		if (philo->full)
			break ;
		eating(philo);
		write_status(SLEEPING, philo);
		sleeping(philo->table->t_sleep, philo->table);
		thinking(philo);
	}
	return (NULL);
}

void	start_meal(t_table *table)
{
	int	i;

	i = -1;
	if (table->max_dinner == 0)
		return ;
	else if (table->n_philo == 1)
		pthread_create(&table->philo[0].thread_id, NULL, \
			socrate, &table->philo[0]);
	else
		while (++i != table->n_philo)
			init_thread(&table->philo[i].thread_id, CREATE, \
			&table->philo[i]);
	set_bool(&table->table_mutex, &table->syncronized, true);
	pthread_create(&table->monitor, NULL, referee, table);
	table->start_program = getcorrecttime();
	i = -1;
	while (++i != table->n_philo)
		init_thread(&table->philo[i].thread_id, JOIN, NULL);
	set_bool(&table->table_mutex, &table->end_program, true);
	pthread_join(table->monitor, NULL);
}

int	main(int arc, char **argv)
{
	t_table	table;

	if (arc != 5 && arc != 6)
		return (printf("WRONG NUMBER OF ARGUMENTS!!\n"), 1);
	if (parsing(argv) == 0)
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
