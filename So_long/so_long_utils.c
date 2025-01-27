/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:43:54 by mbiagi            #+#    #+#             */
/*   Updated: 2025/01/22 16:35:09 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free (map[i]);
		map[i] = NULL;
		i++;
	}
	free (map);
}

void	find_p(char **map, int *x, int *y)
{
	while (map[*y])
	{
		while (map[*y][*x] != '\n')
		{
			if (map[*y][*x] == 'P')
				return ;
			(*x)++;
		}
		(*x) = 0;
		(*y)++;
	}
}

void	floodfill(char **map, int x, int y)
{
	if ((map[y][x] == '1') || map[y][x] == 'x')
		return ;
	if ((map[y][x] == 'E') || (map[y][x] == 'N'))
	{
		map[y][x] = '1';
		return ;
	}
	else
		map[y][x] = 'x';
	floodfill (map, (x + 1), y);
	floodfill (map, (x - 1), y);
	floodfill (map, x, (y + 1));
	floodfill (map, x, (y - 1));
}

int	check(t_imma *imma, int y, int x)
{
	if (!imma->map)
		return (0);
	if (imma->map[y][x] == '1')
		return (0);
	if ((imma->map[y][x] == 'E') && (imma->coll > 0))
		return (0);
	else if (imma->map[y][x] == 'E')
	{
		ft_free(imma->map);
		imma->map = NULL;
		return (0);
	}
	if (imma->map[y][x] == 'N')
	{
		ft_free(imma->map);
		imma->map = NULL;
		return (0);
	}
	if ((imma->map) && (imma->map[y][x] == 'C'))
		imma->coll -= 1;
	return (1);
}

void	*look(t_imma *imma)
{
	if (imma->sprite.look_to == 3)
		return (imma->sprite.link_front);
	else if (imma->sprite.look_to == 1)
		return (imma->sprite.link_back);
	else if (imma->sprite.look_to == 2)
		return (imma->sprite.link_side_sx);
	else if (imma->sprite.look_to == 4)
		return (imma->sprite.link_side_dx);
	return (imma->sprite.link_front);
}
