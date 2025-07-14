/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:05:17 by mbiagi            #+#    #+#             */
/*   Updated: 2025/07/10 18:52:12 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	init_beer(t_data *data, int w, int h)
{
	data->mlx.beer_anim[0] = mlx_xpm_file_to_image(data->mlx.mlx, B1, &w, &h);
	data->mlx.pixel_beer[0] = (int *)mlx_get_data_addr(data->mlx.beer_anim[0], \
		&data->mlx.bpp, &data->mlx.size_line, &data->mlx.endian);
	data->mlx.beer_anim[1] = mlx_xpm_file_to_image(data->mlx.mlx, B2, &w, &h);
	data->mlx.pixel_beer[1] = (int *)mlx_get_data_addr(data->mlx.beer_anim[1], \
		&data->mlx.bpp, &data->mlx.size_line, &data->mlx.endian);
	data->mlx.beer_anim[2] = mlx_xpm_file_to_image(data->mlx.mlx, B3, &w, &h);
	data->mlx.pixel_beer[2] = (int *)mlx_get_data_addr(data->mlx.beer_anim[2], \
		&data->mlx.bpp, &data->mlx.size_line, &data->mlx.endian);
	data->mlx.beer_anim[3] = mlx_xpm_file_to_image(data->mlx.mlx, B4, &w, &h);
	data->mlx.pixel_beer[3] = (int *)mlx_get_data_addr(data->mlx.beer_anim[3], \
		&data->mlx.bpp, &data->mlx.size_line, &data->mlx.endian);
	data->mlx.beer_anim[4] = mlx_xpm_file_to_image(data->mlx.mlx, B5, &w, &h);
	data->mlx.pixel_beer[4] = (int *)mlx_get_data_addr(data->mlx.beer_anim[4], \
		&data->mlx.bpp, &data->mlx.size_line, &data->mlx.endian);
	data->mlx.beer_anim[5] = mlx_xpm_file_to_image(data->mlx.mlx, B6, &w, &h);
	data->mlx.pixel_beer[5] = (int *)mlx_get_data_addr(data->mlx.beer_anim[5], \
		&data->mlx.bpp, &data->mlx.size_line, &data->mlx.endian);
}

void	init_cig(t_data *data, int w, int h)
{
	data->mlx.cig_ani[0] = mlx_xpm_file_to_image(data->mlx.mlx, CIGA1, &w, &h);
	data->mlx.pixel_cig[0] = (int *)mlx_get_data_addr(data->mlx.cig_ani[0], \
		&data->mlx.bpp, &data->mlx.size_line, &data->mlx.endian);
	data->mlx.cig_ani[1] = mlx_xpm_file_to_image(data->mlx.mlx, CIGA2, &w, &h);
	data->mlx.pixel_cig[1] = (int *)mlx_get_data_addr(data->mlx.cig_ani[1], \
		&data->mlx.bpp, &data->mlx.size_line, &data->mlx.endian);
	data->mlx.cig_ani[2] = mlx_xpm_file_to_image(data->mlx.mlx, CIGA3, &w, &h);
	data->mlx.pixel_cig[2] = (int *)mlx_get_data_addr(data->mlx.cig_ani[2], \
		&data->mlx.bpp, &data->mlx.size_line, &data->mlx.endian);
	data->mlx.cig_ani[3] = mlx_xpm_file_to_image(data->mlx.mlx, CIGA4, &w, &h);
	data->mlx.pixel_cig[3] = (int *)mlx_get_data_addr(data->mlx.cig_ani[3], \
		&data->mlx.bpp, &data->mlx.size_line, &data->mlx.endian);
	data->mlx.cig_ani[4] = mlx_xpm_file_to_image(data->mlx.mlx, CIGA5, &w, &h);
	data->mlx.pixel_cig[4] = (int *)mlx_get_data_addr(data->mlx.cig_ani[4], \
		&data->mlx.bpp, &data->mlx.size_line, &data->mlx.endian);
	data->mlx.cig_ani[5] = mlx_xpm_file_to_image(data->mlx.mlx, \
		CIGA6, &w, &h);
	data->mlx.pixel_cig[5] = (int *)mlx_get_data_addr(data->mlx.cig_ani[5], \
		&data->mlx.bpp, &data->mlx.size_line, &data->mlx.endian);
}

void	init_pack(t_data *data, int w, int h)
{
	data->mlx.pack_anim[0] = mlx_xpm_file_to_image(data->mlx.mlx, PAC1, &w, &h);
	data->mlx.pixel_pack[0] = (int *)mlx_get_data_addr(data->mlx.pack_anim[0], \
		&data->mlx.bpp, &data->mlx.size_line, &data->mlx.endian);
	data->mlx.pack_anim[1] = mlx_xpm_file_to_image(data->mlx.mlx, PAC2, &w, &h);
	data->mlx.pixel_pack[1] = (int *)mlx_get_data_addr(data->mlx.pack_anim[1], \
		&data->mlx.bpp, &data->mlx.size_line, &data->mlx.endian);
	data->mlx.pack_anim[2] = mlx_xpm_file_to_image(data->mlx.mlx, PAC3, &w, &h);
	data->mlx.pixel_pack[2] = (int *)mlx_get_data_addr(data->mlx.pack_anim[2], \
		&data->mlx.bpp, &data->mlx.size_line, &data->mlx.endian);
	data->mlx.pack_anim[3] = mlx_xpm_file_to_image(data->mlx.mlx, PAC4, &w, &h);
	data->mlx.pixel_pack[3] = (int *)mlx_get_data_addr(data->mlx.pack_anim[3], \
		&data->mlx.bpp, &data->mlx.size_line, &data->mlx.endian);
	data->mlx.pack_anim[4] = mlx_xpm_file_to_image(data->mlx.mlx, PAC5, &w, &h);
	data->mlx.pixel_pack[4] = (int *)mlx_get_data_addr(data->mlx.pack_anim[4], \
		&data->mlx.bpp, &data->mlx.size_line, &data->mlx.endian);
	data->mlx.pack_anim[5] = mlx_xpm_file_to_image(data->mlx.mlx, \
		PAC6, &w, &h);
	data->mlx.pixel_pack[5] = (int *)mlx_get_data_addr(data->mlx.pack_anim[5], \
		&data->mlx.bpp, &data->mlx.size_line, &data->mlx.endian);
}
