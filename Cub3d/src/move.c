/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 23:11:14 by edraccan          #+#    #+#             */
/*   Updated: 2025/07/02 10:43:31 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_handle(int key, t_data *data)
{
	if (key == XK_Escape)
		cross_close(data);
	if (key == XK_w)
		data->movingno = true;
	if (key == XK_s)
		data->movingso = true;
	if (key == XK_d)
		data->movingea = true;
	if (key == XK_a)
		data->movingwe = true;
	if (key == XK_Left)
		data->movingl = true;
	if (key == XK_Right)
		data->movingr = true;
	return (0);
}

int	key_release(int key, t_data *data)
{
	if (key == XK_w)
		data->movingno = false;
	if (key == XK_s)
		data->movingso = false;
	if (key == XK_d)
		data->movingea = false;
	if (key == XK_a)
		data->movingwe = false;
	if (key == XK_Left)
		data->movingl = false;
	if (key == XK_Right)
		data->movingr = false;
	return (0);
}

void	moving(t_data *data, float moveX, float moveY)
{
	float	offsetx;
	float	offsety;

	offsetx = 0;
	if (moveX * STEP < 0)
		offsetx = -0.15;
	else if (moveX * STEP > 0)
		offsetx = 0.15;
	offsety = 0;
	if (moveY * STEP < 0)
		offsety = -0.15;
	else if (moveY * STEP > 0)
		offsety = 0.15;
	if (data->map[(int)(data->player[1])] \
	[(int)(data->player[0] + moveX + offsetx)] != '1')
		data->player[0] += moveX * STEP;
	if (data->map[(int)(data->player[1] + moveY + offsety)] \
	[(int)(data->player[0])] != '1')
		data->player[1] += moveY * STEP;
}

void	rotate(t_data *data)
{
	float	angle;
	float	olddirx;
	float	oldplanex;

	angle = 0;
	if (data->movingl)
		angle = -ROT_SPEED;
	else if (data->movingr)
		angle = ROT_SPEED;
	olddirx = data->direction[0];
	data->direction[0] = data->direction[0] * cos(angle) - \
	data->direction[1] * sin(angle);
	data->direction[1] = olddirx * sin(angle) + data->direction[1] * cos(angle);
	oldplanex = data->camera[0];
	data->camera[0] = data->camera[0] * cos(angle) - \
	data->camera[1] * sin(angle);
	data->camera[1] = oldplanex * sin(angle) + data->camera[1] * cos(angle);
}

int	key_input(t_data *data)
{
	if (data->movingno == true)
		moving(data, data->direction[0] * STEP, data->direction[1] * STEP);
	if (data->movingso == true)
		moving(data, -data->direction[0] * STEP, -data->direction[1] * STEP);
	if (data->movingea == true)
		moving(data, -data->direction[1] * STEP, data->direction[0] * STEP);
	if (data->movingwe == true)
		moving(data, data->direction[1] * STEP, -data->direction[0] * STEP);
	if (data->movingl == true || data->movingr == true)
		rotate(data);
	return (0);
}
