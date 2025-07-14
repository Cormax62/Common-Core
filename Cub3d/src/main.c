/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:29:16 by edraccan          #+#    #+#             */
/*   Updated: 2025/07/02 15:09:45 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	print_matrix(char **m)
{
	int	i;

	i = 0;
	while (m && m[i])
	{
		printf("%s\n", m[i]);
		i++;
	}
}

void	print_textures(t_data *data)
{
	printf("nord:\t|%s|\n", data->texture[NO]);
	printf("sud:\t|%s|\n", data->texture[SO]);
	printf("ovest:\t|%s|\n", data->texture[WE]);
	printf("est:\t|%s|\n\n", data->texture[EA]);
	if (data->color[F] != NULL)
		printf("F RGB: |%d, %d, %d|\n", data->color[F][0], \
		data->color[F][1], data->color[F][2]);
	if (data->color[C] != NULL)
		printf("C RGB: |%d, %d, %d|\n", data->color[C][0], \
		data->color[C][1], data->color[C][2]);
	printf("\n");
	print_matrix(data->map);
}

int	main(int ac, char **av)
{
	t_data	data;

	data = (t_data){0};
	if (ac != 2)
		return (printf(T_RED"Wrong arguments number\n"T_WHITE), 1);
	if (!parse_all(av, &data))
		return (free_all(&data), 1);
	data.ray = malloc(sizeof(t_ray));
	if (!init_engine(&data))
		return (free_all(&data), 1);
	mlx_hook(data.mlx.win, 02, 1L << 0, key_handle, &data);
	mlx_hook(data.mlx.win, 03, 1L << 1, key_release, &data);
	mlx_hook(data.mlx.win, 17, 1L << 0, cross_close, &data);
	mlx_loop_hook(data.mlx.mlx, loop, &data);
	mlx_loop(data.mlx.mlx);
	free_all(&data);
	return (0);
}
