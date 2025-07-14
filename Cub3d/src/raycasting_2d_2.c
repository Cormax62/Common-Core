/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2d_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 09:34:47 by mbiagi            #+#    #+#             */
/*   Updated: 2025/07/02 14:50:02 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	drawing(t_data *data, int step, int dir1, int dir2)
{
	data->ray->color = data->mlx.pixel_img[dir1][data->ray->texturey
		* W_TEXT + data->ray->texturex];
	if (step == -1)
		data->ray->color = data->mlx.pixel_img[dir2][data->ray->texturey
			* W_TEXT + data->ray->texturex];
}

void	draw_wall_slice(t_data *data, int x)
{
	int	y;

	data->ray->step = 1.0 * H_TEXT / (float)data->ray->lineh;
	data->ray->textpos = (data->ray->drawstart - H_WIN / 2 \
	+ data->ray->lineh / 2) * data->ray->step;
	y = data->ray->drawstart;
	while (y < data->ray->drawend)
	{
		data->ray->texturey = (int)data->ray->textpos & (H_TEXT - 1);
		data->ray->textpos += data->ray->step;
		if (data->ray->side == 0)
			drawing(data, data->ray->stepx, EA, WE);
		else
			drawing(data, data->ray->stepy, SO, NO);
		data->mlx.pixel[y * W_WIN + x] = data->ray->color;
		y++;
	}
}

void	calc_texture_info(t_data *data)
{
	data->ray->lineh = (int)(H_WIN / data->ray->perpwalldist);
	data->ray->drawstart = fmax(0, -data->ray->lineh / 2 + H_WIN / 2);
	data->ray->drawend = fmin(H_WIN - 1, data->ray->lineh / 2 + H_WIN / 2);
	if (data->ray->side == 0)
		data->ray->wallx = data->player[1]
			+ data->ray->perpwalldist * data->ray->raydiry;
	else
		data->ray->wallx = data->player[0]
			+ data->ray->perpwalldist * data->ray->raydirx;
	data->ray->wallx -= floor(data->ray->wallx);
	data->ray->texturex = (int)(data->ray->wallx * (float)W_TEXT);
	if ((data->ray->side == 0 && data->ray->raydirx > 0)
		|| (data->ray->side == 1 && data->ray->raydiry < 0))
		data->ray->texturex = W_TEXT - data->ray->texturex - 1;
}

void	calc_perp_distance(t_data *data)
{
	if (data->ray->side == 0)
		data->ray->perpwalldist = (data->ray->mapx - data->player[0] \
			+ (1 - data->ray->stepx) / 2) / data->ray->raydirx;
	else
		data->ray->perpwalldist = (data->ray->mapy - data->player[1] \
			+ (1 - data->ray->stepy) / 2) / data->ray->raydiry;
	if (data->ray->perpwalldist < 0)
		data->ray->perpwalldist = 0.01;
}

void	perform_dda(t_data *data)
{
	data->ray->hitwall = 0;
	while (data->ray->hitwall == 0)
	{
		if (data->ray->sidedistx < data->ray->sidedisty)
		{
			data->ray->sidedistx += data->ray->deltadistx;
			data->ray->mapx += data->ray->stepx;
			data->ray->side = 0;
		}
		else
		{
			data->ray->sidedisty += data->ray->deltadisty;
			data->ray->mapy += data->ray->stepy;
			data->ray->side = 1;
		}
		if (data->map[data->ray->mapy][data->ray->mapx] == '1')
			data->ray->hitwall = 1;
	}
}
