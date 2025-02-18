/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:11:52 by mbiagi            #+#    #+#             */
/*   Updated: 2025/02/18 13:55:23 by mbiagi           ###   ########.fr       */
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

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (i);
		i ++ ;
	}
	if (str[i] == ' ')
		return (i);
	return (ft_strlen(str));
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

char	*parse_cmd(char *argv, char **env)
{
	int		i;
	char	*command;
	char	**path;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			path = ft_split(env[i] + 5, ':');
		i++;
	}
	i = 0;
	while (path[i])
	{
		command = ft_strjoin(ft_strjoin(path[i], "/"), argv);
		if (access(command, F_OK) == 0)
			return (command);
		i++;
	}
	return (NULL);
}

void	child(int arc, char **argv, char **env, t_file fd)
{
	int		i;
	pid_t	pid;

	i = -1;
	while (arc - 4 > ++i)
	{
		closefd(fd.pipefd);
		pipe(fd.pipefd);
		//
		forking(&pid, fd.pipefd);
		if (pid == 0)
		{
			dup2(fd.pipefd[1], 1);
			closefd(fd.pipefd);
			closefd(fd.file);
			execve(parse_cmd(ft_substr(argv[2 + i], 0, \
			find_space(argv[2 + i])), env), \
			ft_split(argv[2 + i], ' '), env);
		}
		else
		{
			dup2(fd.pipefd[0], 0);
			closefd(fd.pipefd);
			close(fd.file[0]);			
		}
		//wait (NULL);
	}
}

int	args_control(int arc, char **argv, int *file)
{
	file[0] = open(argv[1], O_RDONLY);
	file[1] = open(argv[arc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if ((file[0] == -1) || (file [1] == -1))
		return (0);
	if ((arc < 5) || (access(argv[1], F_OK) != 0) || \
	(access(argv[1], R_OK) != 0))
		return (closefd(file), 0);
	return (1);
}

int	main(int arc, char **argv, char **env)
{
	t_file	fd;
	pid_t	pid;

	if (args_control(arc, argv, fd.file) == 0)
		return (1);
	if (pipe(fd.pipefd) == -1)
		return (1);
	dup2(fd.file[0], 0);
	close(fd.file[0]);
	forking(&pid, fd.pipefd);
	if (pid == 0)
	{
		child(arc, argv, env, fd);
		closefd(fd.pipefd);
		dup2(fd.file[1], 1);
		close(fd.file[1]);
		execve(parse_cmd(ft_substr(argv[arc - 2], 0, \
		find_space(argv[arc - 2])), env), \
		ft_split(argv[arc - 2], ' '), env);
	}
	else
	{
		close(fd.file[1]);
		closefd(fd.pipefd);
	}
	waitpid(pid, NULL, 0);
	return (0);
}
