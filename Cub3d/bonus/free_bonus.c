/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 00:13:57 by edraccan          #+#    #+#             */
/*   Updated: 2025/07/11 07:27:15 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	free_sprites(t_data *data, void **anim)
{
	int	i;

	i = 0;
	while (i < SPRITES)
	{
		if (anim[i])
			mlx_destroy_image(data->mlx.mlx, anim[i]);
		i++;
	}
}

void	free_textures(t_data *data, char **t)
{
	int	i;

	i = 0;
	while (i < COORD)
	{
		if (t[i])
			free(t[i]);
		if (data->mlx.imgs[i])
			mlx_destroy_image(data->mlx.mlx, data->mlx.imgs[i]);
		i++;
	}
}

void	free_all(t_data *data)
{
	free_textures(data, data->texture);
	free_sprites(data, data->mlx.cig_ani);
	free_sprites(data, data->mlx.beer_anim);
	free_sprites(data, data->mlx.pack_anim);
	if (data->color[0])
		free(data->color[0]);
	if (data->color[1])
		free(data->color[1]);
	if (data->player)
		free(data->player);
	free_matrix(data->map);
}

int	cross_close(t_data *data)
{
	free_all(data);
	mlx_destroy_image(data->mlx.mlx, data->mlx.game);
	mlx_destroy_window(data->mlx.mlx, data->mlx.win);
	mlx_destroy_display(data->mlx.mlx);
	free(data->mlx.mlx);
	free(data->ray);
	exit(0);
}
