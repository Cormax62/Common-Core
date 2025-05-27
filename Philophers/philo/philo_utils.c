/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 09:44:31 by mbiagi            #+#    #+#             */
/*   Updated: 2025/05/27 09:38:16 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	all_threads_running(t_table *table) //sium
{
	bool	temp;

	temp = false;
	mutex_handle(&table->table_mutex, LOCK);
	if (table->running_threads == table->n_philo)
		temp = true;
	mutex_handle(&table->table_mutex, UNLOCK);
	return (temp);
}

void	write_status(int action, t_philo *philo)
{
	long	time;

	if (philo->full)
		return ;
	time = (getcorrecttime() - philo->table->start_program) / 1e3;
	mutex_handle(&philo->table->write_mutex, LOCK);
	if (action == FORK && get_bool(&philo->philo_mutex, \
	&philo->table->end_program) == false)
		printf("%-6ld the philosopher %d has taken a fork", time, philo->id);
	else if (action == THINKING && get_bool(&philo->philo_mutex, \
	&philo->table->end_program) == false)
		printf("%-6ld the philosopher %d is thinking", time, philo->id);
	else if (action == EATING && get_bool(&philo->philo_mutex, \
	&philo->table->end_program) == false)
		printf("%-6ld the philosopher %d is eating", time, philo->id);
	else if (action == SLEEPING && get_bool(&philo->philo_mutex, \
	&philo->table->end_program) == false)
		printf("%-6ld the philosopher %d is sleeping", time, philo->id);
	else if (action == DIED)
		printf("%-6ld the philosopher %d has died", time, philo->id);
	mutex_handle(&philo->table->write_mutex, UNLOCK);
}

static long	ft_number_long(const char *c, int x, int sign)
{
	long	num;

	num = 0;
	while ((c[x] >= 48) && (c[x] <= 57))
	{
		num = num * 10 + (c[x] - '0');
		x++;
	}
	if (sign == 1)
		return (num * -1);
	return (num);
}

long	ft_atol(const char *nptr)
{
	int	x;
	int	sign;

	x = 0;
	sign = 0;
	while ((nptr[x] == 32) || ((nptr[x] >= 9) && (nptr[x] <= 13)))
		x++;
	if (nptr[x] == 43)
		x++;
	else if (nptr[x] == 45)
	{
		sign = 1;
		x++;
	}
	else if ((nptr[x] < 48) || (nptr[x] > 57))
		return (0);
	return (ft_number_long(nptr, x, sign));
}

long	getcorrecttime(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return ((long)((tv.tv_sec * 1e9) + (tv.tv_usec * 1e3)));
}
