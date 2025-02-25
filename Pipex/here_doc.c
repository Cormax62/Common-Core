/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:16:16 by mbiagi            #+#    #+#             */
/*   Updated: 2025/02/25 09:17:58 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	here_doc(t_file *fd, char **argv)
{
	int		fil;
	char	*str;

	fd->here_d = 1;
	fil = open("here_doc", O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (fil == -1)
		return (fil);
	str = get_next_line(0);
	while (ft_strncmp(str, argv[2], ft_strlen(argv[2])) != 0)
	{
		ft_putstr_fd(str, fil);
		free(str);
		str = get_next_line(0);
	}
	free(str);
	get_next_line(fil);
	close(fil);
	fil = open("here_doc", O_RDWR, 0777);
	return (fil);
}

void	for_fork(int arc, char **argv, char **env, t_file fd)
{
	pid_t	pid;

	forking(&pid, fd.pipefd);
	if (arc - 4 + fd.here_d > fd.i)
		child(pid, argv, env, fd);
	else
	{
		if (pid == 0 && (arc - 4 + fd.here_d == fd.i))
			child_do(fd, arc, argv, env);
		else
			parent(fd, pid);
	}
}
