/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:14:53 by edraccan          #+#    #+#             */
/*   Updated: 2025/07/14 11:26:02 by edraccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx_int.h"
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <sys/time.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <X11/X.h>
# include <X11/keysym.h>

// COLORS
# define T_RED "\033[1;31m"
# define T_GREEN "\033[32m"
# define T_YELLOW "\033[1;33m"
# define T_BLUE "\033[34m"
# define T_WHITE "\033[0m"
# define B_RED "\033[41m"
# define B_GREEN "\033[42m"
# define B_BLUE "\033[43m"

// WINDOW 
# define W_WIN 1920 //1440
# define H_WIN 1080 //900

// GAME
# define W_IMG 32
# define H_IMG 32
# define W_TEXT 64
# define H_TEXT 64
# define H_PLA 16
# define W_PLA 16
# define STEP 0.2
# define ROT_SPEED 0.05
# define BORDER 5
# define FPS 60

// ARRAYS
# define COORD 4
# define COLORS 2

// ENUMS
enum e_colors
{
	F,
	C	
};

enum e_texture
{
	NO,
	EA,
	SO,
	WE
};

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
	void			*imgs[COORD];
	void			*game;
	int				*pixel_img[COORD];
	int				*pixel;
	unsigned int	c_color;
	unsigned int	f_color;
	unsigned int	mini_wall_color;
	unsigned int	mini_floor_color;
	unsigned int	mini_player_color;
	unsigned int	mini_empty_color;
	int				wimg;
	int				himg;
	int				bpp; // bit per pixel, used for creating images
	int				size_line; // same as above
	int				endian; // same as above
}			t_mlx;

typedef struct s_ray
{
	float			camx;
	float			raydirx;
	float			raydiry;
	float			deltadistx;
	float			deltadisty;
	int				mapx;
	int				mapy;
	int				stepx;
	int				stepy;
	float			sidedistx;
	float			sidedisty;
	float			perpwalldist;
	int				hitwall;
	int				side;
	int				lineh;
	int				drawstart;
	int				drawend;
	float			wallx;
	float			step;
	int				texturex;
	int				texturey;
	float			textpos;
	unsigned int	color;
}			t_ray;

typedef struct s_data
{
	t_mlx			mlx;
	t_ray			*ray;
	char			**map; //map
	int				map_lines;
	float			*player; //player's position
	float			direction[2];
	float			camera[2];
	char			p_char; //player's char
	int				*color[COLORS]; //rgb
	char			*texture[COORD]; // texture path
	int				count_text;
	int				count_col;
	int				movingno;
	int				movingso;
	int				movingwe;
	int				movingea;
	int				movingl;
	int				movingr;
	struct timeval	oldtime;
	struct timeval	newtime;
}			t_data;

int				key_input(t_data *data);

// colors.c
void			put_color(unsigned int color, int *pixel, int *start, int *end);
size_t			create_trgb(size_t t, size_t r, size_t g, size_t b);
void			init_colors(t_data *data);
int				valid_rgb(char *rgb);

// free.c
void			free_textures(t_data *data, char **t);
void			free_all(t_data *data);
int				cross_close(t_data *data);

// init_all.c
void			init_data(char *line, t_data *data);
void			init_map(t_data *data, char *file);

// init_engine.c
void			init_rotation(t_data *data);
int				init_mlx(t_data *data);
int				init_engine(t_data *data);

// move.c
int				key_handle(int key, t_data *data);
int				key_release(int key, t_data *data);
void			moving(t_data *data, float moveX, float moveY);
void			rotate(t_data *data);
int				key_input(t_data *data);

// parse_file.c
int				parse_all(char **av, t_data *data);
int				parse_map(t_data *data);
int				parse_file(char *file, t_data *data, int fd);
int				parse_map_content(t_data *data);

// engine.c
unsigned int	set_color(int side, int stepX, int stepY);
void			raycasting_2d(t_data *data);
int				loop(t_data *data);
int				init_engine(t_data *data);
int				*get_coordinates(int x, int y);

// raycasting_2d.c
void			put_line(t_data *data, unsigned int color, int *star, int *end);
void			raycasting_2d(t_data *data);

// raycasting_2d_2.c
void			perform_dda(t_data *data);
void			calc_perp_distance(t_data *data);
void			calc_texture_info(t_data *data);
void			draw_wall_slice(t_data *data, int x);

// utils.c
char			*find_texture(char *line);
int				empty_line(char *line);
int				check_file_valid(char *file);
int				check_params(t_data *data);
int				is_map(char	*line);

// utils2.c
int				is_player(char c);
float			*player_pos(t_data *data);
int				*get_coordinates(int x, int y);

#endif