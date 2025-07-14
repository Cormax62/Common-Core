/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:18:58 by edraccan          #+#    #+#             */
/*   Updated: 2025/07/02 09:48:41 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_rotation(t_data *data)
{
	if (data->p_char == 'N' || data->p_char == 'S')
	{
		data->direction[0] = 0;
		data->direction[1] = -1;
		if (data->p_char == 'S')
			data->direction[1] = 1;
	}
	else if (data->p_char == 'E' || data->p_char == 'W')
	{
		data->direction[0] = 1;
		data->direction[1] = 0;
		if (data->p_char == 'W')
			data->direction[0] = -1;
	}
}

int	init_mlx(t_data *data)
{
	int	i;

	data->mlx.mlx = mlx_init();
	if (!data->mlx.mlx)
		return (printf(T_RED"Error in mlx_init()\n"T_WHITE), false);
	data->mlx.win = mlx_new_window(data->mlx.mlx, W_WIN, H_WIN, "cub3D");
	if (!data->mlx.win)
		return (printf(T_RED"Error creating window\n"T_WHITE), false);
	data->mlx.game = mlx_new_image(data->mlx.mlx, W_WIN, H_WIN);
	data->mlx.pixel = (int *)mlx_get_data_addr(data->mlx.game, \
	&data->mlx.bpp, &data->mlx.size_line, &data->mlx.endian);
	i = 0;
	while (i < COORD)
	{
		data->mlx.imgs[i] = mlx_xpm_file_to_image(data->mlx.mlx, \
		data->texture[i], &data->mlx.wimg, &data->mlx.himg);
		data->mlx.pixel_img[i] = (int *)mlx_get_data_addr(data->mlx.imgs[i], \
		&data->mlx.bpp, &data->mlx.size_line, &data->mlx.endian);
		i++;
	}
	return (true);
}

int	init_engine(t_data *data)
{
	data->map[(int)data->player[1]][(int)data->player[0]] = '0';
	data->mlx.himg = H_IMG;
	data->mlx.wimg = W_IMG;
	if (!init_mlx(data))
		return (false);
	init_colors(data);
	init_rotation(data);
	data->camera[0] = -data->direction[1] * 0.66;
	data->camera[1] = data->direction[0] * 0.66;
	return (true);
}
