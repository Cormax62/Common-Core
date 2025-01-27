/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:46:34 by mbiagi            #+#    #+#             */
/*   Updated: 2025/01/23 10:35:13 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(char *argv)
{
	char	buffer[2];
	int		n_new_lines;
	int		fd;
	int		found_nl;

	fd = open(argv, O_RDONLY, 777);
	buffer[1] = 0;
	n_new_lines = 1;
	while (read (fd, buffer, 1) != 0)
	{
		found_nl = 0;
		if (buffer[0] == '\n')
		{
			n_new_lines++;
			found_nl = 1;
		}
	}
	if (found_nl == 1)
		n_new_lines--;
	close (fd);
	return (n_new_lines);
}

char	**get_map(t_imma *imma, char *argv)
{
	char			**map;
	int				lines;
	int				fd;
	int				i;
	static int		check;

	(void)imma;
	i = -1;
	lines = count_lines(argv);
	fd = open(argv, O_RDONLY, 777);
	map = malloc ((lines + 1) * sizeof(char *));
	if (map == NULL)
		return (NULL);
	if (fd == -1 || lines < 3)
		return (free(map), NULL);
	while (i != lines)
		map[++i] = get_next_line (fd);
	close (fd);
	if ((check == 0) && ((is_sqare(map, lines, 0, 0) == 0) \
	|| (required(map, imma) == 0) || (path_finder(map) == 0)))
		return (ft_free (map), NULL);
	if (check++ == 0)
		return (ft_free (map), get_map(imma, argv));
	return (map);
}

void	move_map(t_imma *imma)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	imma->sprite.look_to = imma->sprite.direction;
	find_p(imma->map, &x, &y);
	imma->map[y][x] = '0';
	if ((imma->sprite.direction == 1) && (check(imma, y - 1, x) != 0))
		imma->map[y - 1][x] = 'P';
	else if ((imma->sprite.direction == 2) && (check(imma, y, x - 1) != 0))
		imma->map[y][x - 1] = 'P';
	else if ((imma->sprite.direction == 3) && (check(imma, y + 1, x) != 0))
		imma->map[y + 1][x] = 'P';
	else if ((imma->sprite.direction == 4) && (check(imma, y, x + 1) != 0))
		imma->map[y][x + 1] = 'P';
	else if (!imma->map)
		return ;
	else
		imma->map[y][x] = 'P';
	imma->sprite.direction = 0;
}

void	print_map2(t_imma *imma, int count, int i, int j)
{
	if (imma->map[j][i] == 'C')
	{
		if (count % 80 < 40)
			mlx_put_image_to_window(imma->mlx_ptr, imma->win_ptr, \
			imma->sprite.fairy2, (i * 32), (j * 32));
		else
			mlx_put_image_to_window(imma->mlx_ptr, imma->win_ptr, \
			imma->sprite.fairy1, (i * 32), (j * 32));
	}
	if ((imma->map[j][i] == 'E') && (imma->coll != 0))
		mlx_put_image_to_window(imma->mlx_ptr, imma->win_ptr, \
		imma->sprite.zelda, (i * 32), (j * 32));
	else if ((imma->map[j][i] == 'E') && (imma->coll == 0))
		mlx_put_image_to_window(imma->mlx_ptr, imma->win_ptr, \
		imma->sprite.zelda_horny, (i * 32), (j * 32));
	if (imma->map[j][i] == 'N')
	{
		if (count % 1000 < 500)
			mlx_put_image_to_window(imma->mlx_ptr, imma->win_ptr, \
			imma->sprite.knight_front, (i * 32), (j * 32));
		else
			mlx_put_image_to_window(imma->mlx_ptr, imma->win_ptr, \
			imma->sprite.knight_back, (i * 32), (j * 32));
	}
}

void	print_map(t_imma *imma)
{
	int			i;
	int			j;
	static int	count;

	j = 0;
	while (imma->map[j])
	{
		i = 0;
		while ((imma->map[j][i] != '\n') && (imma->map[j][i]))
		{
			if (imma->map[j][i] == 'P')
				mlx_put_image_to_window(imma->mlx_ptr, imma->win_ptr, \
				look(imma), (i * 32), (j * 32));
			if (imma->map[j][i] == '0')
				mlx_put_image_to_window(imma->mlx_ptr, imma->win_ptr, \
				imma->sprite.floor, (i * 32), (j * 32));
			print_map2(imma, count, i, j);
			print_map3(imma, i, j);
			i++;
		}
		j++;
	}
	++count;
}
