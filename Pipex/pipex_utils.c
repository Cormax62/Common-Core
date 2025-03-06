/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:25:26 by mbiagi            #+#    #+#             */
/*   Updated: 2025/03/05 10:19:25 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	closefd(int pipefd[2])
{
	close(pipefd[0]);
	close(pipefd[1]);
}

int	find_space(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if (str[i] == ' ')
			return (n);
		i++;
		n++;
	}
	return (n);
}

void	forking(pid_t *pid, int pipefd[2])
{
	*pid = fork();
	if (*pid == -1)
	{
		closefd(pipefd);
		exit(1);
	}
}

void	freemtr(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	for_fork(int arc, char **argv, char **env, t_file fd)
{
	pid_t	pid;

	forking(&pid, fd.pipefd);
	if (arc - 4 - fd.here_d > fd.i)
		child(pid, argv, env, fd);
	else
	{
		if (pid == 0 && (arc - 4 - fd.here_d == fd.i))
			child_do(fd, arc, argv, env);
		else
		{
			close(fd.file[1]);
			closefd(fd.pipefd);
			waitpid(pid, NULL, 0);
		}
	}
}
