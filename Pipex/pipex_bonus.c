/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:20:34 by mbiagi            #+#    #+#             */
/*   Updated: 2025/03/05 13:14:49 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*parse_cmd(char *argv, char **env)
{
	int		i;
	char	*command;
	char	**path;
	char	*temp;

	i = -1;
	path = NULL;
	while (env[++i])
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			path = ft_split(env[i] + 5, ':');
	if (!path)
		return (argv);
	i = -1;
	while (path[++i])
	{
		temp = ft_strjoin(path[i], "/");
		command = ft_strjoin(temp, argv);
		free(temp);
		if (access(command, F_OK) == 0)
			return (free(argv), freemtr(path), command);
		free(command);
	}
	return (free(argv), freemtr(path), NULL);
}

int	args_control2(t_file *fd, int arc, char **argv, int *file)
{
	int	i;

	i = -1;
	if (arc < 5)
		return (0);
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		file[0] = here_doc(fd, argv);
		file[1] = open(argv[arc - 1], O_RDWR | O_CREAT, 0777);
	}
	else
	{
		file[0] = open(argv[1], O_RDONLY);
		file[1] = open(argv[arc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	}
	if (file[0] == -1)
		return (close(file[1]), 0);
	if (file[1] == -1)
		return (close(file[0]), 0);
	while (argv[++i])
		if (argv[i][0] == '\0' || till(argv[i]) == (int) ft_strlen(argv[i]))
			return (closefd(file), 0);
	if ((access(argv[1], F_OK) != 0) || (access(argv[1], R_OK) != 0))
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
		path = parse_cmd(ft_substr(argv[2 + fd.i + fd.here_d], till(\
		argv[2 + fd.i]), find_space(argv[2 + fd.i + fd.here_d])), env);
		arg = ft_split(argv[2 + fd.i + fd.here_d], ' ');
		if (!path)
			path = argv[2 + fd.i];
		execve(path, arg, env);
		return (freemtr(arg), exit(1));
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
	if (fd.here_d == 1)
		append(fd.plus);
	path = parse_cmd(ft_substr(argv[arc - 2], till(argv[arc - 2]), \
	find_space(argv[arc - 2])), env);
	arg = ft_split(argv[arc - 2], ' ');
	if (!path)
		path = argv[arc - 2];
	execve(path, arg, env);
	return (freemtr(arg), exit(1));
}

int	main(int arc, char **argv, char **env)
{
	t_file	fd;
	int		w;

	fd.i = -1;
	fd.here_d = 0;
	w = 0;
	if (args_control2(&fd, arc, argv, fd.file) == 0)
		return (4);
	dup2(fd.file[0], 0);
	close(fd.file[0]);
	if (fd.here_d == 1)
	{
		unlink("here_doc");
		fd.plus = get_to_append(fd.file[1]);
		if (fd.plus == NULL)
			return (close(fd.file[1]), 1);
	}
	if (real_thing(&fd, arc, argv, env) == 0)
		return (1);
	while (wait(&w) > 0)
		;
	if (fd.here_d == 1)
		freemtr(fd.plus);
	return (0);
}
