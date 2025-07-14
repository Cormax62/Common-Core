/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:56:24 by mbiagi            #+#    #+#             */
/*   Updated: 2025/06/30 23:22:21 by edraccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
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
	return (free(pos), NULL);
}

int	*get_coordinates(int x, int y)
{
	int	*ret;

	ret = malloc(sizeof(int) * 2);
	ret[0] = x;
	ret[1] = y;
	return (ret);
}
