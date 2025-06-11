/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 09:44:31 by mbiagi            #+#    #+#             */
/*   Updated: 2025/06/11 08:29:25 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_status(int action, t_philo *philo)
{
	long	time;

	if (philo->full)
		return ;
	mutex_handle(&philo->table->write_mutex, LOCK);
	if (get_bool(&philo->table->table_mutex, &philo->table->end_program))
		return ((void)mutex_handle(&philo->table->write_mutex, UNLOCK));
	time = (getcorrecttime() - philo->table->start_program);
	if (action == FORK)
		printf("%-6ld %-2d has taken a fork\n", time, philo->id);
	else if (action == THINKING)
		printf("%-6ld %-2d is thinking\n", time, philo->id);
	else if (action == EATING)
		printf("%-6ld %-2d is eating\n", time, philo->id);
	else if (action == SLEEPING)
		printf("%-6ld %-2d is sleeping\n", time, philo->id);
	else if (action == DIED)
		printf("%-6ld %-2d died\n", time, philo->id);
	mutex_handle(&philo->table->write_mutex, UNLOCK);
}
/* 
static void	print_status(t_philo *philo, char *str)
{
	printf("%ld %d %s\n", getcorrecttime() - philo->table->start_program,
		philo->id + 1, str);
}

void	write_status(int action, t_philo *philo)
{
	pthread_mutex_lock(&philo->table->write_mutex);
	if (get_bool(&philo->philo_mutex, \
		&philo->table->end_program))
	{
		pthread_mutex_unlock(&philo->table->write_mutex);
		return ;
	}
	// if (DEBUG_FORMATTING == true)
	// {
	// 	write_status_debug(philo, action);
	// 	pthread_mutex_unlock(&philo->table->write_mutex);
	// 	return ;
	// }
	if (action == DIED)
		print_status(philo, "died");
	else if (action == EATING)
		print_status(philo, "is eating");
	else if (action == SLEEPING)
		print_status(philo, "is sleeping");
	else if (action == THINKING)
		print_status(philo, "is thinking");
	else if (action == FORK)
		print_status(philo, "has taken a fork");
	pthread_mutex_unlock(&philo->table->write_mutex);
} */

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

void	clear(t_table *table)
{
	t_philo	*philo;
	int		i;

	i = -1;
	while (++i < table->n_philo)
	{
		philo = table->philo + i;
		init_thread(&philo->thread_id, DESTROY, NULL);
	}
	mutex_handle(&table->write_mutex, DESTROY);
	mutex_handle(&table->table_mutex, DESTROY);
	free(table->fork);
	free(table->philo);
}

void	desyncronized(long time)
{
	while (getcorrecttime() < time)
		;
}
