/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:23:11 by mbiagi            #+#    #+#             */
/*   Updated: 2025/01/22 18:30:15 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	input_mouse_control(t_imma *imma)
{
	destroy_immag (imma);
	mlx_destroy_window (imma->mlx_ptr, imma->win_ptr);
	mlx_destroy_display (imma->mlx_ptr);
	free (imma->mlx_ptr);
	ft_free (imma->map);
	exit(0);
}

void	destroy_immag(t_imma *imma)
{
	mlx_destroy_image(imma->mlx_ptr, imma->sprite.link_front);
	mlx_destroy_image(imma->mlx_ptr, imma->sprite.link_side_dx);
	mlx_destroy_image(imma->mlx_ptr, imma->sprite.link_side_sx);
	mlx_destroy_image(imma->mlx_ptr, imma->sprite.link_back);
	mlx_destroy_image(imma->mlx_ptr, imma->sprite.fairy1);
	mlx_destroy_image(imma->mlx_ptr, imma->sprite.fairy2);
	mlx_destroy_image(imma->mlx_ptr, imma->sprite.zelda);
	mlx_destroy_image(imma->mlx_ptr, imma->sprite.zelda_horny);
	mlx_destroy_image(imma->mlx_ptr, imma->sprite.tree);
	mlx_destroy_image(imma->mlx_ptr, imma->sprite.floor);
	mlx_destroy_image(imma->mlx_ptr, imma->sprite.knight_front);
	mlx_destroy_image(imma->mlx_ptr, imma->sprite.knight_back);
	mlx_destroy_image(imma->mlx_ptr, imma->sprite.knight_dx);
	mlx_destroy_image(imma->mlx_ptr, imma->sprite.knight_sx);
	mlx_destroy_image(imma->mlx_ptr, imma->sprite.darkness);
}

void	destroy(t_imma *imma)
{
	destroy_immag(imma);
	mlx_destroy_window (imma->mlx_ptr, imma->win_ptr);
	mlx_destroy_display (imma->mlx_ptr);
	free (imma->mlx_ptr);
	exit(0);
}
