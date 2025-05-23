/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:32:08 by mbiagi            #+#    #+#             */
/*   Updated: 2025/05/23 13:49:13 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
# include <strings.h>
# include <string.h>
# include <bsd/string.h>
# include <fcntl.h>
# include <unistd.h>
# include <linux/stat.h>
# include <sys/stat.h>
# include <stddef.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <pthread.h>

enum t_comm
{
	LOCK ,
	UNLOCK ,
	INIT ,
	DESTROY ,
	CREATE ,
	JOIN ,
	DETACH
};

typedef struct s_table t_table;

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				*fork_id;
}	t_fork;

typedef struct s_philo
{
	int			id;
	long		meal_counter;
	t_fork		*lft_fork;
	t_fork		*rgt_fork;
	bool		full;
	pthread_t	thread_id;
	t_table		*table;
}	t_philo;

typedef struct s_table
{
	int		n_philo;
	long	t_death;
	long	t_eat;
	long	t_sleep;
	long	max_dinner;
	long	start_program;
	bool	end_program;
	t_fork	*fork;
	t_philo	*philo;
}	t_table;

int		parsing(char **argv);
long	ft_atol(const char *nptr);
int		is_all_digit(char **argv);
int		max_check(char **argv);
int		valid_time(char **argv);
void	init_table(t_table *table, int arc, char **argv);
void	init_philo(t_table *table);
int		init_thread(t_philo *philo, int command);
long	getcorrecttime(void);
void	*simulation(void *data);

#endif