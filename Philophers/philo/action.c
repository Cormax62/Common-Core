/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 11:24:38 by mbiagi            #+#    #+#             */
/*   Updated: 2025/05/29 15:13:16 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleeping(long time, t_table *table)
{
	long	start;

	(void)table;
	start = getcorrecttime();
	usleep(time);
}

void	eating(t_philo *philo)
{
	mutex_handle(&philo->table->fork[philo->fork[0]], LOCK);
	write_status(FORK, philo);
	mutex_handle(&philo->table->fork[philo->fork[1]], LOCK);
	write_status(FORK, philo);
	write_status(EATING, philo);
	set_long(&philo->philo_mutex, &philo->last_dinner_time, getcorrecttime());
	set_long(&philo->philo_mutex, &philo->meal_counter, \
	philo->meal_counter + 1);
	sleeping(philo->table->t_eat, philo->table);
	mutex_handle(&philo->table->fork[philo->fork[0]], UNLOCK);
	mutex_handle(&philo->table->fork[philo->fork[1]], UNLOCK);
	if (philo->meal_counter == philo->table->max_dinner)
		set_bool(&philo->philo_mutex, &philo->full, true);
	write_status(SLEEPING, philo);
	sleeping(philo->table->t_sleep, philo->table);
}

void	thinking(t_philo *philo, bool silent)
{
	long	t_think;

	pthread_mutex_lock(&philo->philo_mutex);
	t_think = (philo->table->t_death - (getcorrecttime()
				- philo->last_dinner_time) - philo->table->t_eat) / 2;
	pthread_mutex_unlock(&philo->philo_mutex);
	if (t_think < 0)
		t_think = 0;
	if (t_think == 0 && silent == true)
		t_think = 1;
	if (t_think > 600)
		t_think = 200;
	if (silent == false)
		write_status(THINKING, philo);
	sleeping(t_think, philo->table);
}
