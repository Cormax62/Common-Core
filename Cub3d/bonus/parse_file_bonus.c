/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 23:22:25 by edraccan          #+#    #+#             */
/*   Updated: 2025/07/11 08:02:26 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	parse_file(char *file, t_data *data, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (!empty_line(line))
		{
			if (!is_map(line))
				init_data(line, data);
			else
			{
				while (line)
				{
					data->map_lines++;
					free(line);
					line = get_next_line(fd);
				}
			}
		}
		if (line)
			free(line);
		line = get_next_line(fd);
	}
	return (close(fd), init_map(data, file), check_params(data));
}

int	check_map_values(t_data *data, int i, int j)
{
	if (i == 0 || i == data->map_lines || j == 0 || \
	j == (int)ft_strlen(data->map[i]) - 1)
		return (false);
	if (j + 1 > (int)ft_strlen(data->map[i - 1]) || \
	j + 1 > (int)ft_strlen(data->map[i + 1]))
		return (false);
	if (ft_isspace(data->map[i + 1][j]) || ft_isspace(data->map[i - 1][j]) || \
	ft_isspace(data->map[i][j + 1]) || ft_isspace(data->map[i][j - 1]))
		return (false);
	return (true);
}

int	parse_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] != '1' && !ft_isspace(data->map[i][j]))
			{
				if (!check_map_values(data, i, j))
				{
					printf(T_RED"Wrong map configuration:\n"T_WHITE);
					printf("row \t-> %s%d%s\ncolumn \t-> %s%d%s\n", T_YELLOW, \
					i + 1, T_WHITE, T_YELLOW, j + 1, T_WHITE);
					return (false);
				}
			}
			j++;
		}
		i++;
	}
	return (true);
}

int	parse_map_content(t_data *data)
{
	int	i;
	int	j;
	int	n_player;

	i = -1;
	n_player = 0;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if ((data->map[i][j] != '1' && data->map[i][j] != '0' && \
			data->map[i][j] != 'N' && data->map[i][j] != 'S' && \
			data->map[i][j] != 'W' && data->map[i][j] != 'E' && \
			data->map[i][j] != ' ' && data->map[i][j] != 'C') || \
			(data->map[i][j] == 'C' && data->texture[DO] == NULL))
				return (printf(T_RED"Wrong map content\n"T_WHITE), false);
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S' || \
			data->map[i][j] == 'E' || data->map[i][j] == 'W')
				data->n_player++;
			if (data->map[i][j] == 'C')
				data->doors = 0;
		}
	}
	return (true);
}

int	parse_all(char **av, t_data *data)
{
	int	fd;

	fd = open(av[1], O_RDONLY, 777);
	if (check_file_valid(av[1]) == false)
		exit (1);
	if (parse_file(av[1], data, fd) == false)
		return (printf(T_RED"Wrong parameters configuration\n"T_WHITE), false);
	if (parse_map(data) == false || parse_map_content(data) == false)
		return (false);
	if (data->n_player != 1)
		return (printf(T_RED"Error with player number\n"T_WHITE), false);
	return (true);
}
