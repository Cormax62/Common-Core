/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:27:39 by mbiagi            #+#    #+#             */
/*   Updated: 2025/07/10 18:58:27 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	put_background(t_data *data, int *pixel)
{
	put_color(data->mlx.c_color, pixel, get_coordinates(0, 0), \
	get_coordinates(W_WIN, H_WIN / 2 - data->offset));
	put_color(data->mlx.f_color, pixel, get_coordinates(0, \
		H_WIN / 2 - data->offset), \
	get_coordinates(W_WIN, H_WIN));
}

void	print_info(t_data *data, int x, int y)
{
	char	*fps;

	mlx_string_put(data->mlx.mlx, data->mlx.win, x, y + (DIV * 3), \
		create_trgb(1, 218, 215, 205), "Press I to hide game info");
	mlx_string_put(data->mlx.mlx, data->mlx.win, x, y + (DIV * 4), \
		create_trgb(1, 218, 215, 205), "Move: W, A, S, D");
	mlx_string_put(data->mlx.mlx, data->mlx.win, x, y + (DIV * 5), \
		create_trgb(1, 218, 215, 205), "Rotate: <-, -> / mouse");
	mlx_string_put(data->mlx.mlx, data->mlx.win, x, y + (DIV * 6), \
		create_trgb(1, 218, 215, 205), "Open/close door: E");
	mlx_string_put(data->mlx.mlx, data->mlx.win, x, y + (DIV * 7), \
		create_trgb(1, 218, 215, 205), "Change gear: Q(up), R(down), Z(reset)");
	mlx_string_put(data->mlx.mlx, data->mlx.win, x, y + (DIV * 8), \
		create_trgb(1, 218, 215, 205), "Crouch: Shift");
	fps = ft_rejoin("FPS: ", ft_itoa(ceilf(1000000.0 / data->fps)), 0, 1);
	mlx_string_put(data->mlx.mlx, data->mlx.win, x, y + (DIV * 9), \
		create_trgb(1, 218, 215, 205), fps);
	free(fps);
}

void	print_sprites(t_data *data, int h, int w)
{
	struct timeval	now;
	struct timeval	old;

	gettimeofday(&old, NULL);
	gettimeofday(&now, NULL);
	(void)h;
	(void)w;
	if (data->animation == true && data->t_animation == 0)
		data->t_animation = old.tv_usec;
	if (data->animation == true && (now.tv_usec - data->t_animation) < 700000)
	{
		if (w == 60 && h == 305)
			print_beer_animation(data, get_coordinates(w, h));
		else if (w == 23 && h == 248)
			print_cig_animation(data, get_coordinates(w, h));
		else if (w == 218 && h == 500)
			print_pack_animation(data, get_coordinates(w, h));
	}
}

void	sprite_and_info(t_data *data)
{
	if (data->info)
		print_info(data, SHIFT / 2, \
			SHIFT / 2 + H_IMG * (OFFSET * 2 + 1) + SHIFT);
	else
		mlx_string_put(data->mlx.mlx, data->mlx.win, SHIFT / 2, \
		SHIFT / 2 + H_IMG * (OFFSET * 2 + 1) + SHIFT + (DIV * 3), \
		create_trgb(1, 218, 215, 205), "Press I to show game info");
	if (data->animation == true && data->sober > data->pre_sober)
		print_sprites(data, 305, 60);
	else if (data->animation == true && data->sober == 1)
		print_sprites(data, 500, 218);
	else if (data->animation == true && data->sober < data->pre_sober)
		print_sprites(data, 248, 23);
}

int	loop(t_data *data)
{
	char	*gear;

	gettimeofday(&data->newtime, NULL);
	data->fps = (((data->newtime.tv_sec - data->oldtime.tv_sec) * 1000000) + \
	((data->newtime.tv_usec - data->oldtime.tv_usec)));
	if (data->fps < 1000000 / FPS)
		return (0);
	key_input(data);
	put_background(data, data->mlx.pixel);
	raycasting_2d(data);
	put_img_minimap(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.game, 0, 0);
	data->oldtime = data->newtime;
	gear = ft_rejoin("Gear ", ft_itoa((data->sober / 0.5) - 1), 0, 1);
	mlx_string_put(data->mlx.mlx, data->mlx.win, SHIFT / 2, \
		SHIFT / 2 + H_IMG * (OFFSET * 2 + 1) + SHIFT + (DIV * 1), \
		create_trgb(1, 218, 215, 205), gear);
	sprite_and_info(data);
	return (free(gear), 0);
}
