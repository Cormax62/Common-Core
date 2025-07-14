/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:12:22 by edraccan          #+#    #+#             */
/*   Updated: 2025/07/10 18:57:14 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static void	minimap_on_window(t_data *data, char pos, int x, int y)
{
	if (pos == '1')
		put_color(data->mlx.mini_wall_color, data->mlx.pixel, \
		get_coordinates(x * W_IMG + SHIFT, y * H_IMG + SHIFT), \
		get_coordinates((x + 1) * W_IMG + SHIFT, (y + 1) * H_IMG + SHIFT));
	else if (pos == '0')
		put_color(data->mlx.mini_floor_color, data->mlx.pixel, \
		get_coordinates(x * W_IMG + SHIFT, y * H_IMG + SHIFT), \
		get_coordinates((x + 1) * W_IMG + SHIFT, (y + 1) * H_IMG + SHIFT));
	else if (pos == 'C')
		put_color(create_trgb(1, 97, 93, 86), data->mlx.pixel, \
		get_coordinates(x * W_IMG + SHIFT, y * H_IMG + SHIFT), \
		get_coordinates((x + 1) * W_IMG + SHIFT, (y + 1) * H_IMG + SHIFT));
	else if (pos == 'O')
		put_color(create_trgb(1, 118, 135, 90), data->mlx.pixel, \
		get_coordinates(x * W_IMG + SHIFT, y * H_IMG + SHIFT), \
		get_coordinates((x + 1) * W_IMG + SHIFT, (y + 1) * H_IMG + SHIFT));
	else
		put_color(data->mlx.mini_empty_color, data->mlx.pixel, \
		get_coordinates(x * W_IMG + SHIFT, y * H_IMG + SHIFT), \
		get_coordinates((x + 1) * W_IMG + SHIFT, (y + 1) * H_IMG + SHIFT));
}

void	display_minimap(t_data *data, int origin)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = approx(data->player[1]) - OFFSET;
	while (i < (OFFSET * 2) + 1)
	{
		j = 0;
		x = origin;
		while (j < (OFFSET * 2) + 1)
		{
			minimap_on_window(data, get_char(data, x, y), j, i);
			j++;
			x++;
		}
		i++;
		y++;
	}
}

void	print_grid_minimap(t_data *data)
{
	int	i;

	i = 0;
	while (i <= (OFFSET * 2 + 1))
	{
		put_line(data, create_trgb(1, 218, 215, 205), \
		get_coordinates(i * W_IMG + SHIFT, SHIFT), \
		get_coordinates(i * W_IMG + SHIFT, (OFFSET * 2 + 1) * H_IMG + SHIFT));
		put_line(data, create_trgb(1, 218, 215, 205), \
		get_coordinates(SHIFT, i * W_IMG + SHIFT), \
		get_coordinates((OFFSET * 2 + 1) * H_IMG + SHIFT, i * W_IMG + SHIFT));
		i++;
	}
}

void	print_border_minimap(t_data *data)
{
	put_color(create_trgb(1, 218, 215, 205), data->mlx.pixel, \
		get_coordinates(SHIFT / 2, SHIFT / 2), \
		get_coordinates(SHIFT / 2 + W_IMG * (OFFSET * 2 + 1) + SHIFT, SHIFT));
	put_color(create_trgb(1, 218, 215, 205), data->mlx.pixel, \
		get_coordinates(SHIFT / 2, SHIFT / 2 + W_IMG * \
		(OFFSET * 2 + 1) + SHIFT / 2), get_coordinates(SHIFT / 2 + W_IMG * \
		(OFFSET * 2 + 1) + SHIFT, SHIFT / 2 + W_IMG * \
		(OFFSET * 2 + 1) + SHIFT));
	put_color(create_trgb(1, 218, 215, 205), data->mlx.pixel, \
		get_coordinates(SHIFT / 2, SHIFT / 2), \
		get_coordinates(SHIFT, SHIFT / 2 + W_IMG * (OFFSET * 2 + 1) + SHIFT));
	put_color(create_trgb(1, 218, 215, 205), data->mlx.pixel,
		get_coordinates(SHIFT / 2 + W_IMG * (OFFSET * 2 + 1) + \
		SHIFT / 2, SHIFT / 2), get_coordinates(SHIFT / 2 + W_IMG * \
		(OFFSET * 2 + 1) + SHIFT, \
		SHIFT / 2 + W_IMG * (OFFSET * 2 + 1) + SHIFT));
}

void	put_img_minimap(t_data *data)
{
	display_minimap(data, approx(data->player[0]) - OFFSET);
	print_grid_minimap(data);
	print_border_minimap(data);
	put_color(data->mlx.mini_player_color, data->mlx.pixel, \
	get_coordinates((OFFSET) * W_IMG + (W_IMG / 2) - (W_PLA / 2) + SHIFT, \
	(OFFSET) * H_IMG + (H_IMG / 2) - (H_PLA / 2) + SHIFT), \
	get_coordinates((OFFSET) * W_IMG + (W_IMG / 2) - (W_PLA / 2) + H_PLA + \
	SHIFT, (OFFSET) * H_IMG + (H_IMG / 2) - (H_PLA / 2) + H_PLA + SHIFT));
}
