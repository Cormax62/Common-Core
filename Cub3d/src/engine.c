/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:27:39 by mbiagi            #+#    #+#             */
/*   Updated: 2025/07/03 16:23:51 by edraccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	put_background(t_data *data, int *pixel)
{
	put_color(data->mlx.c_color, pixel, get_coordinates(0, 0), \
	get_coordinates(W_WIN, H_WIN / 2));
	put_color(data->mlx.f_color, pixel, get_coordinates(0, H_WIN / 2), \
	get_coordinates(W_WIN, H_WIN));
}

int	loop(t_data *data)
{
	long	fps;

	gettimeofday(&data->newtime, NULL);
	fps = (((data->newtime.tv_sec - data->oldtime.tv_sec) * 1000000) + \
	((data->newtime.tv_usec - data->oldtime.tv_usec)));
	if (fps < 1000000 / FPS)
		return (0);
	key_input(data);
	put_background(data, data->mlx.pixel);
	raycasting_2d(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.game, 0, 0);
	data->oldtime = data->newtime;
	return (0);
}
