/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:11:55 by mbiagi            #+#    #+#             */
/*   Updated: 2025/03/05 10:25:08 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"

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
# include <sys/wait.h>

typedef struct s_file
{
	int		pipefd[2];
	int		file[2];
	int		i;
	int		here_d;
	char	**plus;
	pid_t	pid;
}	t_file;

int		args_control(int arc, char **argv, int *file);
int		args_control2(t_file *fd, int arc, char **argv, int *file);
void	child(pid_t pid, char **argv, char **env, t_file fd);
void	child_do(t_file fd, int arc, char **argv, char **env);
char	*parse_cmd(char *argv, char **env);
void	closefd(int pipefd[2]);
int		find_space(char *str);
void	forking(pid_t *pid, int pipefd[2]);
void	freemtr(char **matrix);
int		here_doc(t_file *fd, char **argv);
void	for_fork(int arc, char **argv, char **env, t_file fd);
int		control_str(char *str, char *argv);
char	**get_to_append(int fd);
void	append(char **plus);
int		real_thing(t_file *fd, int arc, char **argv, char **env);
int		till_word(char *str);

#endif