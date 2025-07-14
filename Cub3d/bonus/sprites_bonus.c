/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:21:47 by mbiagi            #+#    #+#             */
/*   Updated: 2025/07/11 10:14:11 by edraccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

// NOTE: start e il punto della finestra da dove stampiamo,
// spr sono le dimensioni della sprite
void	put_pixel_sprites(t_data *data, int *pixel, int *start, int *spr)
{
	int	y;
	int	x;

	y = 0;
	while (y < spr[1])
	{
		x = 0;
		while (x < spr[0])
		{
			if (pixel[y * spr[0] + x] != 0x000000)
				data->mlx.pixel[(start[1] + y) * W_WIN + (start[0] + x)] = \
				pixel[y * spr[0] + x];
			x++;
		}
		y++;
	}
	free(start);
	free(spr);
}

void	reset_4_loop(t_data *data, int *cont)
{
	data->animation = false;
	data->t_animation = 0;
	*cont = 0;
}

void	print_pack_animation(t_data *data, int *wh)
{
	static int	cont;

	cont++;
	if (cont > 0 && cont <= 7)
		put_pixel_sprites(data, data->mlx.pixel_pack[0], \
			get_coordinates(W_WIN - wh[0] - 300, H_WIN - wh[1] - 80), wh);
	else if (cont > 7 && cont <= 14)
		put_pixel_sprites(data, data->mlx.pixel_pack[1], \
			get_coordinates(W_WIN - wh[0] - 300, H_WIN - wh[1] - 80), wh);
	else if (cont > 14 && cont <= 21)
		put_pixel_sprites(data, data->mlx.pixel_pack[2], \
			get_coordinates(W_WIN - wh[0] - 300, H_WIN - wh[1] - 80), wh);
	else if (cont > 21 && cont <= 28)
		put_pixel_sprites(data, data->mlx.pixel_pack[3], \
			get_coordinates(W_WIN - wh[0] - 300, H_WIN - wh[1] - 80), wh);
	else if (cont > 28 && cont <= 35)
		put_pixel_sprites(data, data->mlx.pixel_pack[4], \
			get_coordinates(W_WIN - wh[0] - 300, H_WIN - wh[1] - 80), wh);
	else if (cont > 35 && cont <= 42)
		put_pixel_sprites(data, data->mlx.pixel_pack[5], \
			get_coordinates(W_WIN - wh[0] - 300, H_WIN - wh[1] - 80), wh);
	else
		return (free(wh), reset_4_loop(data, &cont));
}

void	print_cig_animation(t_data *data, int *wh)
{
	static int	cont;

	cont++;
	if (cont > 0 && cont <= 7)
		put_pixel_sprites(data, data->mlx.pixel_cig[0], \
			get_coordinates(W_WIN - wh[0] - 300, H_WIN - wh[1] - 85), wh);
	else if (cont > 7 && cont <= 14)
		put_pixel_sprites(data, data->mlx.pixel_cig[1], \
			get_coordinates(W_WIN - wh[0] - 300, H_WIN - wh[1] - 85), wh);
	else if (cont > 14 && cont <= 21)
		put_pixel_sprites(data, data->mlx.pixel_cig[2], \
			get_coordinates(W_WIN - wh[0] - 300, H_WIN - wh[1] - 85), wh);
	else if (cont > 21 && cont <= 28)
		put_pixel_sprites(data, data->mlx.pixel_cig[3], \
			get_coordinates(W_WIN - wh[0] - 300, H_WIN - wh[1] - 85), wh);
	else if (cont > 28 && cont <= 35)
		put_pixel_sprites(data, data->mlx.pixel_cig[4], \
			get_coordinates(W_WIN - wh[0] - 300, H_WIN - wh[1] - 85), wh);
	else if (cont > 35 && cont <= 42)
		put_pixel_sprites(data, data->mlx.pixel_cig[5], \
			get_coordinates(W_WIN - wh[0] - 300, H_WIN - wh[1] - 85), wh);
	else
		return (free(wh), reset_4_loop(data, &cont));
}

void	print_beer_animation(t_data *data, int *wh)
{
	static int	cont;

	cont++;
	if (cont > 0 && cont <= 7)
		put_pixel_sprites(data, data->mlx.pixel_beer[0], \
			get_coordinates(W_WIN - wh[0] - 300, H_WIN - wh[1] - 85), wh);
	else if (cont > 7 && cont <= 14)
		put_pixel_sprites(data, data->mlx.pixel_beer[1], \
			get_coordinates(W_WIN - wh[0] - 300, H_WIN - wh[1] - 85), wh);
	else if (cont > 14 && cont <= 21)
		put_pixel_sprites(data, data->mlx.pixel_beer[2], \
			get_coordinates(W_WIN - wh[0] - 300, H_WIN - wh[1] - 85), wh);
	else if (cont > 21 && cont <= 28)
		put_pixel_sprites(data, data->mlx.pixel_beer[3], \
			get_coordinates(W_WIN - wh[0] - 300, H_WIN - wh[1] - 85), wh);
	else if (cont > 28 && cont <= 35)
		put_pixel_sprites(data, data->mlx.pixel_beer[4], \
			get_coordinates(W_WIN - wh[0] - 300, H_WIN - wh[1] - 85), wh);
	else if (cont > 35 && cont <= 42)
		put_pixel_sprites(data, data->mlx.pixel_beer[5], \
			get_coordinates(W_WIN - wh[0] - 300, H_WIN - wh[1] - 85), wh);
	else
		return (free(wh), reset_4_loop(data, &cont));
}
