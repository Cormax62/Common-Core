/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:20:34 by mbiagi            #+#    #+#             */
/*   Updated: 2025/02/25 09:18:12 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*parse_cmd(char *argv, char **env)
{
	int		i;
	char	*command;
	char	**path;
	char	*temp;

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
		temp = ft_strjoin(path[i], "/");
		command = ft_strjoin(temp, argv);
		free(temp);
		if (access(command, F_OK) == 0)
			return (free(argv), freemtr(path), command);
		free(command);
		i++;
	}
	freemtr(path);
	return (free(argv), NULL);
}

int	args_control2(t_file *fd, int arc, char **argv, int *file)
{
	int	i;

	i = 0;
	if (arc < 5)
		return (0);
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		file[0] = here_doc(fd, argv);
	else
		file[0] = open(argv[1], O_RDONLY);
	file[1] = open(argv[arc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if ((file[0] == -1) || (file [1] == -1))
		return (0);
	while (argv[i])
	{
		if (argv[i][0] == '\0')
			return (0);
		i++;
	}
	if ((access(argv[1], F_OK) != 0) || \
	(access(argv[1], R_OK) != 0))
		return (closefd(file), 0);
	return (1);
}

void	child(pid_t pid, char **argv, char **env, t_file fd)
{
	char	*path;
	char	**arg;

	if (pid == 0)
	{
		dup2(fd.pipefd[1], 1);
		closefd(fd.pipefd);
		closefd(fd.file);
		path = parse_cmd(ft_substr(argv[2 + fd.i + fd.here_d], 0, \
		find_space(argv[2 + fd.i + fd.here_d])), env);
		arg = ft_split(argv[2 + fd.i + fd.here_d], ' ');
		if (!path || !arg)
			return (free(path), freemtr(arg));
		execve(path, arg, env);
	}
	else
	{
		dup2(fd.pipefd[0], 0);
		closefd(fd.pipefd);
		close(fd.file[0]);
		waitpid(pid, NULL, 0);
	}
}

void	child_do(t_file fd, int arc, char **argv, char **env)
{
	char	*path;
	char	**arg;

	closefd(fd.pipefd);
	dup2(fd.file[1], 1);
	close(fd.file[1]);
	path = parse_cmd(ft_substr(argv[arc - 2], 0, \
	find_space(argv[arc - 2])), env);
	arg = ft_split(argv[arc - 2], ' ');
	if (!path || !arg)
		return (free(path), freemtr(arg));
	execve(path, arg, env);
}

int	main(int arc, char **argv, char **env)
{
	t_file	fd;

	fd.i = -1;
	fd.here_d = 0;
	if (args_control2(&fd, arc, argv, fd.file) == 0)
		return (4);
	dup2(fd.file[0], 0);
	close(fd.file[0]);
	if (fd.here_d == 1)
		unlink("here_doc");
	while (arc - 4 + fd.here_d >= ++fd.i)
	{
		if (pipe(fd.pipefd) == -1)
			return (3);
		for_fork(arc, argv, env, fd);
	}
	return (0);
}
