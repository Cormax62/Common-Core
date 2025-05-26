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

void	*socrates(void *data)
{
	t_philo	*philo;

	philo = (t_philo)data;
	while(!get_bool(philo->table->table_mutex, philo->table->syncronized))
		;
	set_long(&philo->philo_mutex, &philo->last_dinner_time, getcorrecttime());
	write_status(FORK, philo);
	while (!get_bool(&table->table_mutex, table->end_program))
		usleep(200);
	return (NULL);
}

void	*referee(void *data)
{
	int		i;
	t_table	*table;
	long	r_threads;

	i = -1;
	table = (t_table)data;
	while (!all_threads_running(table))
		;
	while (!get_bool(&table->table_mutex, table->end_program))
	{
		while (++i < table->n_philo && !get_bool(&table->table_mutex, /
		table->end_program))
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

	philo = (t_philo)data;
	while(!get_bool(philo->table->table_mutex, philo->table->syncronized))
		;
	set_long(&philo->philo_mutex, &philo->last_dinner_time, getcorrecttime());
	set_long(&philo->table->table_mutex, philo->table->running_threads, /
	philo->table->running_threads + 1;)
	desyncronized(philo);
	while(!get_bool(philo->table->table_mutex, philo->table->end_program))
	{
		if (philo->full) // FORSE AVRA' LEAK, DA CONTROLLARE A PROGRAMMA FINITO
			break ;
		eating(philo);
		write_status(SLEEPING, philo);
		sleeping(philo->table->t_sleep, philo->table);
		thinking();
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
		pthread_create(&table->philo[0], NULL, socrate(), &table->philo[0])
	else
		while (++i != table->n_philo)
			init_thread(&table->philo[i], CREATE);
	pthread_create(&table->monitor, NULL, referee, table)
	table->start_program = getcorrecttime();
	set_bool(*table->table_mutex, table->syncronized, true);
	i = -1;
	while (++i != table->n_philo)
		init_thread(&table->philo[i], JOIN);
	set_bool(&table->table_mutex, &table->end_program, true);
	init_thread(&table->monitor, JOIN);
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
	clear(&table);
	return (0);
}
