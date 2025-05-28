/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 09:37:12 by mbiagi            #+#    #+#             */
/*   Updated: 2025/05/28 08:22:26 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_thread(pthread_t *thread, int command, t_philo *philo)
{
	if (command == CREATE)
		return (pthread_create(thread, NULL, simulation, philo));
	else if (command == JOIN)
		return (pthread_join(*thread, NULL));
	else if (command == DETACH)
		return (pthread_detach(*thread));
	return (53550);
}

int	mutex_handle(pthread_mutex_t *fork, int command)
{
	if (command == LOCK)
		return (pthread_mutex_lock(fork));
	else if (command == UNLOCK)
		return (pthread_mutex_unlock(fork));
	else if (command == INIT)
		return (pthread_mutex_init(fork, NULL));
	else if (command == DESTROY)
		return (pthread_mutex_destroy(fork));
	return (53550);
}

static void	assign_fork(t_table *table, int pos)
{
	if (pos % 2 == 0)
	{
		table->philo->fork[0] = pos - 1;
		table->philo->fork[1] = (pos) % table->n_philo;
	}
	else
	{
		table->philo->fork[1] = pos - 1;
		table->philo->fork[0] = (pos) % table->n_philo;		
	}
}

void	init_philo(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i != table->n_philo)
	{
		philo = table->philo + i;
		philo->id = i + 1;
		philo->meal_counter = 0;
		philo->last_dinner_time = 0;
		philo->full = false;
		philo->table = table;
		mutex_handle(&philo->philo_mutex, INIT);
		assign_fork(table , i);
		i++;
	}
}

void	init_table(t_table *table)
{
	int	i;

	i = -1;
	table->running_threads = 0;
	table->end_program = false;
	table->syncronized = false;
	table->fork = malloc(table->n_philo * (sizeof(pthread_mutex_t)));
	if (table->fork == NULL)
		return (printf("MALLOC HAS...FAILED?!"), exit (1));
	while (++i < table->n_philo)
	{
		if (mutex_handle(&table->fork[i], INIT) != 0)
			return (free(table->fork), printf("SOMETHING FAILED"), exit (1));
	}
	if (mutex_handle(&table->table_mutex, INIT) != 0)
		return (free(table->fork), printf("SOMETHING FAILED"), exit (1));
	if (mutex_handle(&table->write_mutex, INIT) != 0)
		return (free(table->fork), printf("SOMETHING FAILED"), exit (1));
	table->philo = malloc(table->n_philo * (sizeof(t_philo)));
	if (table->philo == NULL)
		return (free(table->fork), printf("MALLOC HAS...FAILED?!"), exit (1));
}
