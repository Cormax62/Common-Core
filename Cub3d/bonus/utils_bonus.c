/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:31:39 by edraccan          #+#    #+#             */
/*   Updated: 2025/07/11 07:49:11 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

// trova il path della texture nella riga presa da gnl
char	*find_texture(char *line)
{
	int	i;

	i = 0;
	while (line && line[i] && ft_isspace(line[i]))
		i++;
	if (!line[i] || line[i] == '\n')
		return (NULL);
	return (&line[i]);
}

int	empty_line(char *line)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		if (line[i] != ' ' && line[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}

int	check_file_valid(char *file)
{
	char	*str;
	int		fd;

	fd = open(file, O_RDONLY, 777);
	if (fd < 0)
	{
		close(fd);
		printf("Error\n%sMap file not found\n"T_WHITE, T_RED);
		return (false);
	}
	close(fd);
	str = ft_strrchr(file, '.');
	if (!str)
	{
		printf("Error\n%sInvalid map extension\n"T_WHITE, T_RED);
		return (false);
	}
	if (str[0] == '.' && str[1] == 'c' && str[2] == 'u' && str[3] == 'b' && \
	str[4] == '\0')
		return (true);
	printf("Error\n%sInvalid map extension\n"T_WHITE, T_RED);
	return (false);
}

int	check_params(t_data *data)
{
	int	i;
	int	fd;

	i = 0;
	while (i < COORD - data->doors)
	{
		if (data->texture[i] == NULL)
			return (false);
		i++;
	}
	if (data->color[0] == NULL || data->color[1] == NULL)
		return (false);
	if (data->count_text > COORD + 2 || data->count_col > COLORS)
		return (false);
	i = 0;
	while (i < COORD - data->doors)
	{
		fd = open(data->texture[i], O_RDWR, 777);
		if (fd < 0)
			return (close(fd), false);
		close (fd);
		i++;
	}
	return (true);
}

int	is_map(char	*line)
{
	int	i;

	i = 0;
	while (line && line[i] && ft_isspace(line[i]))
		i++;
	if (ft_strncmp(&line[i], "NO ", 3) == 0)
		return (false);
	if (ft_strncmp(&line[i], "SO ", 3) == 0)
		return (false);
	if (ft_strncmp(&line[i], "WE ", 3) == 0)
		return (false);
	if (ft_strncmp(&line[i], "EA ", 3) == 0)
		return (false);
	if (ft_strncmp(&line[i], "DO ", 3) == 0)
		return (false);
	if (line[i] == 'F')
		return (false);
	if (line[i] == 'C')
		return (false);
	if (ft_strchr(&line[i], '/'))
		return (false);
	return (true);
}
