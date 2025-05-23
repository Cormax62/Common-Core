/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 09:37:12 by mbiagi            #+#    #+#             */
/*   Updated: 2025/05/23 13:59:26 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_thread(t_philo *philo, int command)
{
	if (command == CREATE)
		return (pthread_create(&philo->thread_id, NULL, simulation, &philo));
	else if (command == JOIN)
		return (pthread_join(philo->thread_id, NULL));
	else if (command == DETACH)
		return (pthread_detach(philo->thread_id));
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
		return (pthread_mutex_unlock(fork));
}

static void	assign_fork(t_table *table, int pos)
{
	if (pos % 2 == 0)
	{
		table->philo->lft_fork = &table->fork[pos];
		table->philo->rgt_fork = &table->fork[(pos + 1) % table->n_philo];
	}
	else
	{
		table->philo->rgt_fork = &table->fork[pos];
		table->philo->lft_fork = &table->fork[(pos + 1) % table->n_philo];		
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
		philo->full = false;
		philo->table = table;
		assign_fork(table , i);
		i++;
	}
}

void	init_table(t_table *table, int arc, char **argv)
{
	int	i;

	i = -1;
	table->end_program = false;
	table->fork = malloc(table->n_philo * (sizeof(t_fork)));
	if (table->fork == NULL)
		return (printf("MALLOC HAS...FAILED?!"), exit (1));
	while (++i < table->n_philo)
	{
		if (mutex_handle(&table->fork[i].fork, INIT) != 0)
			return (free(table->fork), printf("SOMETHING FAILED"), exit (1));
		table->fork[i].fork_id = i;
	}
	table->philo = malloc(table->n_philo * (sizeof(t_philo)));
	if (table->philo == NULL)
		return (free(table->fork), printf("MALLOC HAS...FAILED?!"), exit (1));
}
