/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:26:49 by mbiagi            #+#    #+#             */
/*   Updated: 2025/01/22 16:33:47 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_sqare(char **map, int lines, int i, int j)
{
	if ((ft_strlen(map[0]) - 1) != (ft_strlen(map[lines - 1])))
		return (ft_printf("Error\n[no square map]"), 0);
	while (map[j][i] == '1')
		i++;
	if (map[j][i] != '\n')
		return (ft_printf("Error\n[no square map]"), 0);
	else
		j++;
	while ((map[j][0] == '1') && (map[j][i - 1] == '1') && (j != lines - 1) \
	&& (map[j][i] == '\n') && (map[j + 1]) && (map[j][i] != 0))
		j++;
	if (j == lines - 1)
	{
		i = 0;
		while (map[j][i] == '1')
			i++;
		if (map[j][i] != '\0')
			return (ft_printf("Error\n[no square map]"), 0);
	}
	else
		return (ft_printf("Error\n[no square map]"), 0);
	return (1);
}

int	search(char **map, int n)
{
	int	j;
	int	i;
	int	nx;

	j = 0;
	i = 0;
	nx = 0;
	while (map[j])
	{
		while (map[j][i])
		{
			if (map[j][i] == n)
				nx++;
			if ((map[j][i] != '1') && (map[j][i] != '0') && \
			(map[j][i] != 'P') && (map[j][i] != 'C') && (map[j][i] != 'E') \
			&& (map[j][i] != '\n') && (map[j][i] != 'N'))
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (nx);
}

int	required(char **map, t_imma *imma)
{
	int	np;
	int	nc;
	int	ne;

	np = 80;
	nc = 67;
	ne = 69;
	np = search(map, np);
	nc = search(map, nc);
	imma->coll = nc;
	ne = search(map, ne);
	if ((np == 1) && (nc >= 1) && (ne == 1))
		return (1);
	return (ft_printf("Error\n[no valid item]"), 0);
}

int	path_finder(char **map)
{
	int	x;
	int	y;
	int	i;
	int	j;

	j = 0;
	x = 0;
	y = 0;
	find_p(map, &x, &y);
	floodfill(map, x, y);
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if ((map[j][i] != '1') && (map[j][i] != '0') && \
			(map[j][i] != 'x') && (map[j][i] != '\n'))
				return (ft_printf("Error\n[no valid path]"), 0);
			i++;
		}
		j++;
	}
	return (1);
}

int	check_file_valid(char *file)
{
	char	*str;
	int		fd;

	fd = open(file, O_RDONLY, 777);
	if (fd < 0 || !file)
	{
		close(fd);
		ft_printf("Error\n[no map]\n");
		return (0);
	}
	close(fd);
	str = ft_strchr(file, '.');
	if (!str)
	{
		ft_printf("Error\n[invalid map file]\n");
		return (0);
	}
	if (str[0] == '.' && str[1] == 'b' && str[2] == 'e' && str[3] == 'r' \
	&& str[4] == '\0')
		return (1);
	ft_printf("Error\n[invalid map file]\n");
	return (0);
}
