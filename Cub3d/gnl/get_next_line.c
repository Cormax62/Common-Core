/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 23:52:08 by edraccan          #+#    #+#             */
/*   Updated: 2025/06/15 12:25:18 by edraccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*set_buffer(char *line)
{
	int		i;
	char	*buffer;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i] || !line[1])
		return (NULL);
	buffer = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (buffer[0] == '\0')
	{
		free(buffer);
		buffer = NULL;
	}
	line[i + 1] = '\0';
	return (buffer);
}

char	*get_new_line(int fd, char *line, char *buffer)
{
	int		bytes;
	char	*tmp;

	bytes = 1;
	while (bytes != 0)
	{
		bytes = read(fd, line, BUFFER_SIZE);
		if (bytes == -1)
			return (NULL);
		if (bytes == 0)
			break ;
		line[bytes] = '\0';
		if (!buffer)
			buffer = ft_strdup("");
		tmp = buffer;
		buffer = ft_strjoin(tmp, line);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n') != NULL)
			break ;
	}
	return (buffer);
}

/* NOTE
** mandatory function, set buffer to the new read line until it doesn't
** find a \n, after it will copy on line only the part of buffer before \n
** (included) and after it updates buffer to the values after \n and
** it returns line
*/
char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	line = get_new_line(fd, tmp, buffer);
	free(tmp);
	if (!line)
		return (NULL);
	buffer = set_buffer(line);
	return (line);
}

/* 
int main()
{
	// int fd = open("test.txt", O_RDONLY);
	char *s = get_next_line(0);
	// printf("%s", s);
	// free(s);
	// s = get_next_line(fd);
	// while (s)
	// {
	// 	printf("%s", s);
	// 	free(s);
	// 	s = get_next_line(fd);
	// }
	free(s);
	// close(fd);
}
 */