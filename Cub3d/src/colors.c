/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:03:43 by edraccan          #+#    #+#             */
/*   Updated: 2025/06/30 18:06:18 by edraccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

void	init_colors(t_data *data)
{
	data->mlx.f_color = create_trgb(1, \
	data->color[F][0], data->color[F][1], data->color[F][2]);
	data->mlx.c_color = create_trgb(1, \
	data->color[C][0], data->color[C][1], data->color[C][2]);
	data->mlx.mini_player_color = create_trgb(1, 255, 0, 0);
	data->mlx.mini_floor_color = create_trgb(1, 0, 255, 0);
	data->mlx.mini_wall_color = create_trgb(1, 0, 0, 255);
	data->mlx.mini_empty_color = create_trgb(1, 51, 51, 51);
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
