/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 09:37:12 by mbiagi            #+#    #+#             */
/*   Updated: 2025/06/07 16:02:49 by mbiagi           ###   ########.fr       */
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

static void	assign_fork(t_philo *philo, int pos)
{
	(void)pos;
	philo->fork[0] = philo->id - 1;
	philo->fork[1] = (philo->id) % philo->table->n_philo;
	if (philo->id % 2)
	{
		philo->fork[0] = (philo->id) % philo->table->n_philo;
		philo->fork[1] = philo->id - 1;
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
		assign_fork(&table->philo[i], i);
		i++;
	}
}

void	init_table(t_table *table)
{
	int	i;

	i = -1;
	table->end_program = false;
	table->fork = malloc(table->n_philo * (sizeof(pthread_mutex_t)));
	if (table->fork == NULL)
		return ;
	while (++i < table->n_philo)
	{
		if (mutex_handle(&table->fork[i], INIT) != 0)
			return (free(table->fork));
	}
	if (mutex_handle(&table->table_mutex, INIT) != 0)
		return (free(table->fork));
	if (mutex_handle(&table->write_mutex, INIT) != 0)
		return (free(table->fork));
	table->philo = malloc(table->n_philo * (sizeof(t_philo)));
	if (table->philo == NULL)
		return (free(table->fork));
}
