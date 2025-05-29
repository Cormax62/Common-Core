/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:07:38 by mbiagi            #+#    #+#             */
/*   Updated: 2025/05/29 15:14:42 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	kill_philo(t_philo *philo)
{
	long	time;

	time = getcorrecttime();
	if ((time - philo->last_dinner_time) >= philo->table->t_death / 1000)
	{
		set_bool(&philo->table->table_mutex,
			&philo->table->end_program,
			true);
		write_status(DIED, philo);
		mutex_handle(&philo->philo_mutex, UNLOCK);
		return (true);
	}
	return (false);
}

bool	is_philo_dead(t_table *table)
{
	int	i;
	int	n;

	i = -1;
	n = 0;
	while (++i < table->n_philo)
	{
		mutex_handle(&table->philo[i].philo_mutex, LOCK);
		if (kill_philo(&table->philo[i]))
			return (true);
		if (table->philo[i].full)
			n++;
		mutex_handle(&table->philo[i].philo_mutex, UNLOCK);
	}
	if (n == table->n_philo)
	{
		set_bool(&table->table_mutex, &table->end_program, true);
		return (true);
	}
	return (false);
}

void	*referee(void *data)
{
	t_table	*table;

	table = (t_table *)data;
	desyncronized(table->start_program);
	while (1)
	{
		if (is_philo_dead(table))
			return (set_bool(&table->table_mutex, &table->end_program, true),
				NULL);
		usleep(100);
	}
	return (NULL);
}
