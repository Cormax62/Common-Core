/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:16:16 by mbiagi            #+#    #+#             */
/*   Updated: 2025/03/06 12:07:31 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	here_doc(t_file *fd, char **argv)
{
	int		fil;
	char	*str;

	fd->here_d = 1;
	if (argv[2][0] == '\0')
		return (-1);
	fil = open("here_doc", O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (fil == -1)
		return (fil);
	str = get_next_line(0);
	while (control_str(str, argv[2]) == 0)
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

int	control_str(char *str, char *argv)
{
	if (str == NULL)
		return (1);
	if ((ft_strncmp(str, argv, ft_strlen(argv)) == 0) && \
	str[ft_strlen(argv)] == '\n')
		return (1);
	return (0);
}

char	**get_to_append(int fd)
{
	char	**str;
	char	*temp;
	int		line;
	int		i;

	i = 0;
	line = 0;
	temp = get_next_line(fd);
	while (temp != NULL)
	{
		line++;
		free(temp);
		temp = get_next_line(fd);
	}
	free(temp);
	str = malloc(sizeof(char *) * (line + 1));
	if (!str)
		return (NULL);
	while (line > i)
	{
		str[i] = get_next_line(fd);
		i++;
	}
	str[i] = NULL;
	return (str);
}

void	append(char **plus)
{
	int	i;

	i = 0;
	while (plus[i])
	{
		ft_putstr_fd(plus[i], 1);
		i++;
	}
}

int	real_thing(t_file *fd, int arc, char **argv, char **env)
{
	while (arc - 4 - fd->here_d >= ++fd->i)
	{
		if (pipe(fd->pipefd) == -1)
			return (close(fd->file[1]), 0);
		for_fork(arc, argv, env, *fd);
	}
	return (1);
}
