/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:08:36 by marvin            #+#    #+#             */
/*   Updated: 2025/07/01 11:08:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

// start/end[0] -> x
// start/end[1] -> y
void	put_color(unsigned int color, int *pixel, int *start, int *end)
{
	int	i;
	int	j;

	i = start[1];
	while (i < end[1])
	{
		j = start[0];
		while (j < end[0])
		{
			pixel[(int)(i * W_WIN) + j] = color;
			j++;
		}
		i++;
	}
	free(start);
	free(end);
}

size_t	create_trgb(size_t t, size_t r, size_t g, size_t b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	init_color(t_data *data)
{
	data->mlx.f_color = create_trgb(1, \
	data->color[F][0], data->color[F][1], data->color[F][2]);
	data->mlx.c_color = create_trgb(1, \
	data->color[C][0], data->color[C][1], data->color[C][2]);
	data->mlx.mini_player_color = create_trgb(1, 148, 38, 36);
	data->mlx.mini_floor_color = create_trgb(1, 163, 177, 138);
	data->mlx.mini_wall_color = create_trgb(1, 64, 61, 57);
	data->mlx.mini_empty_color = create_trgb(1, 108, 117, 125);
}

int	valid_rgb(char *rgb)
{
	int	i;

	i = 0;
	while (rgb && rgb[i])
	{
		if (!ft_isdigit(rgb[i]))
			return (false);
		i++;
	}
	if (ft_atol(rgb) > 255 || ft_atol(rgb) < 0)
		return (false);
	return (true);
}

unsigned int	set_color(int side, int stepX, int stepY)
{
	if (side == 1)
	{
		if (stepY == -1)
			return (create_trgb(1, 218, 116, 34));
		return (create_trgb(1, 104, 83, 105));
	}
	else
	{
		if (stepX == -1)
			return (create_trgb(1, 221, 151, 135));
		return (create_trgb(1, 183, 224, 0));
	}
}
