/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:49:23 by mbiagi            #+#    #+#             */
/*   Updated: 2025/01/23 10:43:30 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//sed -i 's/\r$//' maps/map.ber

void	print_map3(t_imma *imma, int i, int j)
{
	char	*nmoves;

	if (imma->map[j][i] == '1')
		mlx_put_image_to_window(imma->mlx_ptr, imma->win_ptr, \
		imma->sprite.tree, (i * 32), (j * 32));
	mlx_put_image_to_window(imma->mlx_ptr, imma->win_ptr, \
	imma->sprite.darkness, (0), (0));
	mlx_string_put(imma->mlx_ptr, imma->win_ptr, 11, 11, 0xFFFFFF, "MOVES: ");
	nmoves = ft_itoa(imma->moves);
	mlx_string_put(imma->mlx_ptr, imma->win_ptr, 55, 11, 0xFFFFFF, nmoves);
	free(nmoves);
}

int	input_control(int keysym, t_imma *imma)
{
	if (keysym == XK_Escape)
	{
		destroy_immag (imma);
		mlx_destroy_window (imma->mlx_ptr, imma->win_ptr);
		mlx_destroy_display (imma->mlx_ptr);
		free (imma->mlx_ptr);
		ft_free (imma->map);
		exit(0);
	}
	else if (keysym == XK_w)
		imma->sprite.direction = 1;
	else if (keysym == XK_a)
		imma->sprite.direction = 2;
	else if (keysym == XK_s)
		imma->sprite.direction = 3;
	else if (keysym == XK_d)
		imma->sprite.direction = 4;
	else
		return (0);
	move_map(imma);
	imma->moves += 1;
	return (0);
}

int	game_loop(t_imma *imma)
{
	if (!imma->map)
	{
		ft_printf("Grazie per aver giocato!!!");
		destroy(imma);
		mlx_loop_end(imma->mlx_ptr);
	}
	print_map(imma);
	return (0);
}

void	x_loop(t_imma imma)
{
	mlx_key_hook (imma.win_ptr, input_control, &imma);
	mlx_hook (imma.win_ptr, 17, 1L << 0, input_mouse_control, &imma);
	mlx_loop_hook(imma.mlx_ptr, game_loop, &imma);
	mlx_loop (imma.mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_imma	imma;

	(void)argc;
	if (check_file_valid(argv[1]) == 0)
		return (0);
	imma.mlx_ptr = mlx_init();
	imma.sprite.look_to = 0;
	imma.map = get_map(&imma, argv[1]);
	if ((imma.mlx_ptr == NULL) || (imma.map == NULL))
	{
		mlx_destroy_display (imma.mlx_ptr);
		free (imma.mlx_ptr);
		return (0);
	}
	imma.win_ptr = mlx_new_window (imma.mlx_ptr, (\
	(ft_strlen(imma.map[0]) - 1) * 32), (count_lines(argv[1]) * 32), "TloZ");
	if (imma.win_ptr == NULL)
	{
		mlx_destroy_display (imma.mlx_ptr);
		free (imma.mlx_ptr);
		return (0);
	}
	take_immag(&imma);
	x_loop(imma);
	return (0);
}
