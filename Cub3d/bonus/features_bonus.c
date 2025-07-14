/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   features_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:09:28 by mbiagi            #+#    #+#             */
/*   Updated: 2025/07/10 15:53:27 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	punk_feature(int key, t_data *data)
{
	if (key == XK_q && data->animation == false)
	{
		if (data->sober != 3)
			data->animation = true;
		data->pre_sober = data->sober;
		data->sober = fmin(3, data->sober + 0.5);
	}
	if (key == XK_r && data->animation == false)
	{
		if (data->sober != 1)
			data->animation = true;
		data->pre_sober = data->sober;
		data->sober = fmax(1, data->sober - 0.5);
	}
	if (key == XK_z && data->animation == false)
	{
		if (data->sober != 1)
			data->animation = true;
		data->pre_sober = data->sober;
		data->sober = 1;
	}
}

void	nod(int key, t_data *data)
{
	if (key == XK_Shift_L)
	{
		if (data->open == false)
		{
			data->open = true;
			data->offset = 100;
		}
		else if (data->open == true)
		{
			data->open = false;
			data->offset = 0;
		}
	}
}
