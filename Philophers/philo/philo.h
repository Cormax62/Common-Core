/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:32:08 by mbiagi            #+#    #+#             */
/*   Updated: 2025/05/29 15:15:30 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <X11/X.h>
# include <X11/keysym.h>
# include <bsd/string.h>
# include <ctype.h>
# include <fcntl.h>
# include <linux/stat.h>
# include <pthread.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

enum	e_comm
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH
};

enum	e_action
{
	SLEEPING,
	EATING,
	THINKING,
	FORK,
	DIED
};

typedef struct s_table	t_table;

typedef struct s_philo
{
	int					id;
	long				last_dinner_time;
	long				meal_counter;
	long				fork[2];
	bool				full;
	pthread_t			thread_id;
	pthread_mutex_t		philo_mutex;
	t_table				*table;
}						t_philo;

typedef struct s_table
{
	long				n_philo;
	long				t_death;
	long				t_eat;
	long				t_sleep;
	long				max_dinner;
	long				start_program;
	bool				end_program;
	pthread_t			monitor;
	pthread_mutex_t		write_mutex;
	pthread_mutex_t		table_mutex;
	pthread_mutex_t		*fork;
	t_philo				*philo;
}						t_table;

int						parsing(char **argv);
long					ft_atol(const char *nptr);
int						is_all_digit(char **argv);
int						max_check(char **argv);
int						valid_time(char **argv);
void					init_table(t_table *table);
void					init_philo(t_table *table);
int						init_thread(pthread_t *thread, int command,
							t_philo *philo);
long					getcorrecttime(void);
int						mutex_handle(pthread_mutex_t *fork, int command);
void					*simulation(void *data);
void					*referee(void *data);
void					set_bool(pthread_mutex_t *mutex, bool *dest,
							bool value);
bool					get_bool(pthread_mutex_t *mutex, bool *value);
void					set_long(pthread_mutex_t *mutex, long *dest,
							long value);
long					get_long(pthread_mutex_t *mutex, long *value);
void					write_status(int action, t_philo *philo);
void					sleeping(long time, t_table *table);
void					eating(t_philo *philo);
void					thinking(t_philo *philo, bool silent);
bool					suicide(t_philo *philo);
void					clear(t_table *table);
void					desyncronized(long time);

#endif