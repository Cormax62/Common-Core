/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 00:09:32 by edraccan          #+#    #+#             */
/*   Updated: 2025/07/12 11:00:47 by edraccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static int	*get_color(char *line)
{
	int		i;
	int		*nums;
	char	**s;
	char	*temp;

	i = 0;
	while (line && line[i] && ft_isspace(line[i]))
		i++;
	s = ft_split(&line[i], ',');
	if (matrix_len(s) != 3)
		return (free_matrix(s), NULL);
	nums = ft_calloc(3, sizeof(int));
	if (!nums)
		return (NULL);
	i = -1;
	while (++i < 3)
	{
		temp = ft_strtrim(s[i], " \n\t");
		if (valid_rgb(temp) == false)
			return (free(temp), free(nums), free_matrix(s), NULL);
		nums[i] = ft_atol(temp);
		free(temp);
	}
	free_matrix(s);
	return (nums);
}

static void	init_color2(t_data *data, char *line)
{
	if (line[0] == 'F')
	{
		data->count_col++;
		if (data->count_col > 2)
			return ;
		if (data->color[F] != NULL)
			return ;
		data->color[F] = NULL;
		if (ft_strncmp(line, "F ", 2) == 0)
			data->color[F] = get_color(&line[1]);
	}
	if (line[0] == 'C')
	{
		data->count_col++;
		if (data->count_col > 2)
			return ;
		if (data->color[C] != NULL)
			return ;
		data->color[C] = NULL;
		if (ft_strncmp(line, "C ", 2) == 0)
			data->color[C] = get_color(&line[1]);
	}
}

void	init_data(char *line, t_data *data)
{
	int	i;

	i = 0;
	while (line && line[i] && ft_isspace(line[i]))
		i++;
	line[ft_strlen(line) - 1] = '\0';
	if (ft_strncmp(&line[i], "NO ", 3) == 0 && !data->texture[NO])
		data->texture[NO] = ft_strdup(find_texture(&line[i + 2]));
	if (ft_strncmp(&line[i], "SO ", 3) == 0 && !data->texture[SO])
		data->texture[SO] = ft_strdup(find_texture(&line[i + 2]));
	if (ft_strncmp(&line[i], "WE ", 3) == 0 && !data->texture[WE])
		data->texture[WE] = ft_strdup(find_texture(&line[i + 2]));
	if (ft_strncmp(&line[i], "EA ", 3) == 0 && !data->texture[EA])
		data->texture[EA] = ft_strdup(find_texture(&line[i + 2]));
	if (ft_strncmp(&line[i], "DO ", 3) == 0 && !data->texture[DO])
		data->texture[DO] = ft_strdup(find_texture(&line[i + 2]));
	init_color2(data, &line[i]);
	data->n_player = 0;
	data->count_text++;
	data->doors = 1;
	gettimeofday(&data->oldtime, NULL);
	data->sober = 1;
	data->offset = 0;
}

void	init_map_loop(t_data *data, char **line, int fd)
{
	int	i;

	i = 0;
	while (*line)
	{
		data->map[i] = ft_strdup(*line);
		if (data->map[i][ft_strlen(data->map[i]) - 1] == '\n' && \
		ft_strlen(data->map[i]) > 1)
			data->map[i][ft_strlen(data->map[i]) - 1] = 0;
		else if (data->map[i][ft_strlen(data->map[i]) - 1] == '\n' && \
		ft_strlen(data->map[i]) == 1)
			data->map[i][ft_strlen(data->map[i]) - 1] = ' ';
		i++;
		free(*line);
		*line = get_next_line(fd);
	}
}

void	init_map(t_data *data, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY, 777);
	data->map = ft_calloc((data->map_lines + 1), sizeof(char *));
	line = get_next_line(fd);
	while (line)
	{
		if (!empty_line(line))
		{
			if (is_map(line))
				init_map_loop(data, &line, fd);
		}
		if (line)
			free(line);
		line = get_next_line(fd);
	}
	close(fd);
	data->player = player_pos(data);
	if (data->player)
	{
		data->p_char = data->map[(int)data->player[1]][(int)data->player[0]];
		data->player[0] += 0.5;
		data->player[1] += 0.5;
	}
}
