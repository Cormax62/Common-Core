/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:39:34 by mbiagi            #+#    #+#             */
/*   Updated: 2025/07/03 15:24:13 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	calculating(t_data *data, t_ray *ray)
{
	if (ray->raydirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (data->player[0] - ray->mapx)
			* ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapx + 1.0 - data->player[0])
			* ray->deltadistx;
	}
	if (ray->raydiry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (data->player[1] - ray->mapy)
			* ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->mapy + 1.0 - data->player[1])
			* ray->deltadisty;
	}
}

static void	init_ray(t_data *data, t_ray *ray)
{
	ray->raydirx = data->direction[0];
	ray->raydiry = data->direction[1];
	ray->mapx = data->player[0];
	ray->mapy = data->player[1];
	ray->deltadistx = sqrtf(1 + (ray->raydiry * ray->raydiry) / \
	(ray->raydirx * ray->raydirx));
	ray->deltadisty = sqrtf(1 + (ray->raydirx * ray->raydirx) / \
	(ray->raydiry * ray->raydiry));
}

static void	calc_sidedist(t_ray *ray)
{
	if (ray->sidedistx < ray->sidedisty)
	{
		ray->sidedistx += ray->deltadistx;
		ray->mapx += ray->stepx;
		ray->side = 0;
	}
	else
	{
		ray->sidedisty += ray->deltadisty;
		ray->mapy += ray->stepy;
		ray->side = 1;
	}
}

float	cursor(t_data *data, t_ray *ray, char c)
{
	init_ray(data, ray);
	calculating(data, ray);
	while (1)
	{
		calc_sidedist(ray);
		if (data->map[ray->mapy][ray->mapx] == c)
		{
			if (ray->side == 0)
				return ((ray->mapx - data->player[0] + \
				(1 - ray->stepx) / 2) / ray->raydirx);
			else
				return ((ray->mapy - data->player[1] + \
				(1 - ray->stepy) / 2) / ray->raydiry);
		}
		if (data->map[ray->mapy][ray->mapx] == '1')
			break ;
	}
	return (-1);
}

void	open_door(t_data *data)
{
	t_ray	ray;

	if ((cursor(data, &ray, 'C') <= 2.0) && (cursor(data, &ray, 'C') > 0))
		data->map[ray.mapy][ray.mapx] = 'O';
	else if ((cursor(data, &ray, 'O') <= 2.0) && (cursor(data, &ray, 'O') > 0))
		data->map[ray.mapy][ray.mapx] = 'C';
}
