/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2d_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 09:50:52 by edraccan          #+#    #+#             */
/*   Updated: 2025/07/03 16:26:58 by edraccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	put_line(t_data *data, unsigned int color, int *star, int *end)
{
	float	x_step;
	float	y_step;
	int		max_steps;
	int		i_line;

	x_step = end[0] - star[0];
	y_step = end[1] - star[1];
	max_steps = (int)fmax(fabs(x_step), fabs(y_step));
	x_step /= max_steps;
	y_step /= max_steps;
	i_line = 0;
	while (i_line < max_steps)
	{
		if (star[0] > 0 && star[1] > 0 && star[0] < W_WIN && star[1] < H_WIN)
			data->mlx.pixel[(int)(star[1] * W_WIN) + ((int)star[0])] = color;
		star[0] += x_step;
		star[1] += y_step;
		i_line++;
	}
	free(star);
	free(end);
}

static void	calc_step_and_sidedist(t_data *data)
{
	if (data->ray->raydirx < 0)
	{
		data->ray->stepx = -1;
		data->ray->sidedistx = (data->player[0] - data->ray->mapx)
			* data->ray->deltadistx;
	}
	else
	{
		data->ray->stepx = 1;
		data->ray->sidedistx = (data->ray->mapx + 1.0 - data->player[0])
			* data->ray->deltadistx;
	}
	if (data->ray->raydiry < 0)
	{
		data->ray->stepy = -1;
		data->ray->sidedisty = (data->player[1] - data->ray->mapy)
			* data->ray->deltadisty;
	}
	else
	{
		data->ray->stepy = 1;
		data->ray->sidedisty = (data->ray->mapy + 1.0 - data->player[1])
			* data->ray->deltadisty;
	}
}

static void	init_ray(t_data *data, int x)
{
	float	win_ratio;

	win_ratio = 2 * x / (float)W_WIN - 1;
	data->ray->camx = win_ratio;
	data->ray->raydirx = data->direction[0] + data->camera[0] * win_ratio;
	data->ray->raydiry = data->direction[1] + data->camera[1] * win_ratio;
	data->ray->mapx = (int)data->player[0];
	data->ray->mapy = (int)data->player[1];
	data->ray->deltadistx = sqrtf(1 + (data->ray->raydiry \
	* data->ray->raydiry) / (data->ray->raydirx * data->ray->raydirx));
	data->ray->deltadisty = sqrtf(1 + (data->ray->raydirx \
	* data->ray->raydirx) / (data->ray->raydiry * data->ray->raydiry));
}

void	raycasting_2d(t_data *data)
{
	int	x;

	x = 0;
	while (x < W_WIN)
	{
		init_ray(data, x);
		calc_step_and_sidedist(data);
		perform_dda(data);
		calc_perp_distance(data);
		calc_texture_info(data);
		draw_wall_slice(data, x);
		x++;
	}
}
