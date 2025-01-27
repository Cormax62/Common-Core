/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   immage_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:12:10 by mbiagi            #+#    #+#             */
/*   Updated: 2025/01/22 18:27:56 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	take_immag2(t_imma *imma)
{
	int	i;

	i = 32;
	imma->sprite.zelda_horny = mlx_xpm_file_to_image \
	(imma->mlx_ptr, "./textures/8.xpm", &i, &i);
	imma->sprite.tree = mlx_xpm_file_to_image \
	(imma->mlx_ptr, "./textures/9.xpm", &i, &i);
	imma->sprite.floor = mlx_xpm_file_to_image \
	(imma->mlx_ptr, "./textures/10.xpm", &i, &i);
	imma->sprite.knight_front = mlx_xpm_file_to_image \
	(imma->mlx_ptr, "./textures/11.xpm", &i, &i);
	imma->sprite.knight_back = mlx_xpm_file_to_image \
	(imma->mlx_ptr, "./textures/12.xpm", &i, &i);
	imma->sprite.knight_dx = mlx_xpm_file_to_image \
	(imma->mlx_ptr, "./textures/13.xpm", &i, &i);
	imma->sprite.knight_sx = mlx_xpm_file_to_image \
	(imma->mlx_ptr, "./textures/14.xpm", &i, &i);
	imma->sprite.darkness = mlx_xpm_file_to_image \
	(imma->mlx_ptr, "./textures/15.xpm", &i, &i);
}

void	take_immag(t_imma *imma)
{
	int	i;

	i = 32;
	imma->moves = 0;
	imma->sprite.link_front = mlx_xpm_file_to_image \
	(imma->mlx_ptr, "./textures/1.xpm", &i, &i);
	imma->sprite.link_side_dx = mlx_xpm_file_to_image \
	(imma->mlx_ptr, "./textures/2.xpm", &i, &i);
	imma->sprite.link_side_sx = mlx_xpm_file_to_image \
	(imma->mlx_ptr, "./textures/3.xpm", &i, &i);
	imma->sprite.link_back = mlx_xpm_file_to_image \
	(imma->mlx_ptr, "./textures/4.xpm", &i, &i);
	imma->sprite.fairy1 = mlx_xpm_file_to_image \
	(imma->mlx_ptr, "./textures/5.xpm", &i, &i);
	imma->sprite.fairy2 = mlx_xpm_file_to_image \
	(imma->mlx_ptr, "./textures/6.xpm", &i, &i);
	imma->sprite.zelda = mlx_xpm_file_to_image \
	(imma->mlx_ptr, "./textures/7.xpm", &i, &i);
	take_immag2(imma);
}
