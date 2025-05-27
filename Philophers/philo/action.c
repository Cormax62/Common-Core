/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 09:04:18 by mbiagi            #+#    #+#             */
/*   Updated: 2025/05/27 15:22:59 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    clear(t_table *table)
{
    t_philo *philo;
    int     i;

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

bool    suicide(t_philo *philo)
{
    if (get_bool(&philo->philo_mutex, &philo->full))
        return (false);
    if ((getcorrecttime() - get_long(&philo->philo_mutex, \
    &philo->last_dinner_time)) > philo->table->t_death)
        return (true);
    else
        return (false);
}

void    sleeping(long time, t_table *table)
{
    long    start;

    start = getcorrecttime();
    while ((getcorrecttime() - start) < time)
    {
        if (get_bool(&table->table_mutex, &table->end_program))
            break ;
        if ((time - (getcorrecttime() - start)) > 1e3)
            usleep((time - (getcorrecttime() - start)) / 2);
        else
            while ((getcorrecttime() - start) < time)
                ;
    }
}

void    eating(t_philo *philo)
{
    mutex_handle(&philo->lft_fork->fork, LOCK);
    write_status(FORK, philo);
    mutex_handle(&philo->rgt_fork.fork, LOCK);
    write_status(FORK, philo);
    set_long(&philo->philo_mutex, &philo->last_dinner_time, \
        getcorrecttime() / 1e3);
    philo->meal_counter++;
    write_status(EATING, philo);
    sleeping(philo->table->t_eat, philo->table);
    if (philo->meal_counter == philo->table->max_dinner)
        set_bool(&philo->philo_mutex, &philo->full, true);
    mutex_handle(&philo->lft_fork->fork, UNLOCK);
    mutex_handle(&philo->rgt_fork.fork, UNLOCK);
}

void    thinking(t_philo *philo)
{
    long    t_think;

    write_status(THINKING, philo);
    if (philo->table->n_philo % 2 == 0)
        return ;
    t_think = (philo->table->t_eat * 2) - philo->table->t_sleep;
    if (t_think < 0)
        t_think = 0;
    sleeping(t_think / 0.42, philo->table); //da capire perchè il 0.42
}
