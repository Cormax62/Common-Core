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

enum t_action
{
	SLEEPING,
	EATING,
	THINKING,
	FORK,
	DIED
};

typedef struct s_table t_table;

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				*fork_id;
}	t_fork;

typedef struct s_philo
{
	int				id;
	long			last_dinner_time;
	long			meal_counter;
	t_fork			*lft_fork;
	t_fork			*rgt_fork;
	bool			full;
	pthread_t		thread_id;
	pthread_mutex_t	philo_mutex;
	t_table			*table;
}	t_philo;

typedef struct s_table
{
	int				n_philo;
	long			t_death;
	long			t_eat;
	long			t_sleep;
	long			max_dinner;
	long			start_program;
	long			running_threads;
	bool			syncronized;
	bool			end_program;
	pthread_t		monitor;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	table_mutex;
	t_fork			*fork;
	t_philo			*philo;
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
int		mutex_handle(pthread_mutex_t *fork, int command);
void	*simulation(void *data);
void    set_bool(pthread_mutex_t *mutex, bool *dest, bool value);
bool    get_bool(pthread_mutex_t *mutex, bool *value);
void    set_long(pthread_mutex_t *mutex, long *dest, long value);
long    get_long(pthread_mutex_t *mutex, long *value);
void	write_status(int action, t_philo *philo);
void    sleeping(long time, t_table *table);
void    eating(t_philo *philo);
void    thinking(t_philo *philo);
bool	all_threads_running(t_table *table);
bool    suicide(t_philo *philo);
void    clear(t_table *table);
void    desyncronized(t_philo *philo);

#endif