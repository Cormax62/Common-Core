/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 10:57:20 by marvin            #+#    #+#             */
/*   Updated: 2025/07/01 10:57:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

int	mouse_control(int x, int y, t_data *data)
{
	float	angle;
	float	olddirx;
	float	oldplanex;

	(void)y;
	angle = 0;
	if (x < W_WIN / 2)
		angle = -MOUSE_SPEED * data->sober;
	else if (x > W_WIN / 2)
		angle = MOUSE_SPEED * data->sober;
	if (abs(x - (W_WIN / 2)) > 2)
	{
		olddirx = data->direction[0];
		data->direction[0] = data->direction[0] * cos(angle) - \
		data->direction[1] * sin(angle);
		data->direction[1] = olddirx * sin(angle) + \
		data->direction[1] * cos(angle);
		oldplanex = data->camera[0];
		data->camera[0] = data->camera[0] * cos(angle) - \
		data->camera[1] * sin(angle);
		data->camera[1] = oldplanex * sin(angle) + \
		data->camera[1] * cos(angle);
	}
	mlx_mouse_move(data->mlx.mlx, data->mlx.win, W_WIN / 2, H_WIN / 2);
	return (0);
}
