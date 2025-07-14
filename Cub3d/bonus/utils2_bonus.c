/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:56:24 by mbiagi            #+#    #+#             */
/*   Updated: 2025/07/14 10:06:17 by edraccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	approx(float n)
{
	int	temp;

	temp = (int)n;
	if (fabsf(n - temp) >= 0.9)
		return ((int)n + 1);
	return ((int)n);
}

int	is_player(char c)
{
	if (c == 'N')
		return (true);
	if (c == 'S')
		return (true);
	if (c == 'W')
		return (true);
	if (c == 'E')
		return (true);
	return (false);
}

float	*player_pos(t_data *data)
{
	float	*pos;
	int		i;
	int		j;

	i = 0;
	pos = ft_calloc(2, sizeof(int));
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (is_player(data->map[i][j]))
			{
				pos[0] = j;
				pos[1] = i;
				return (pos);
			}
			j++;
		}
		i++;
	}
	return (free(pos),NULL);
}

int	*get_coordinates(int x, int y)
{
	int	*ret;

	ret = malloc(sizeof(int) * 2);
	ret[0] = x;
	ret[1] = y;
	return (ret);
}

char	get_char(t_data *data, int x, int y)
{
	if (x < 0 || y < 0)
		return (-1);
	if (y >= data->map_lines)
		return (-1);
	if ((size_t)x >= ft_strlen(data->map[y]))
		return (-1);
	return (data->map[y][x]);
}
