/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:14:53 by edraccan          #+#    #+#             */
/*   Updated: 2025/07/14 09:58:12 by edraccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "../minilibx-linux/mlx_int.h"
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <stdio.h>
# include <sys/time.h>
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
# define W_WIN 1920 //800 
# define H_WIN 1080 //780 

// GAME
# define W_IMG 32
# define H_IMG 32
# define W_TEXT 64
# define H_TEXT 64
# define H_PLA 16
# define W_PLA 16
# define OFFSET	4
# define STEP 0.3
# define ROT_SPEED 0.05
# define MOUSE_SPEED 0.05
# define SHIFT 10
# define BORDER 5
# define FPS 60
# define DIV 20
# define B1 "textures/bottle_1.xpm"
# define B2 "textures/bottle_2.xpm"
# define B3 "textures/bottle_3.xpm"
# define B4 "textures/bottle_4.xpm"
# define B5 "textures/bottle_5.xpm"
# define B6 "textures/bottle_6.xpm"
# define CIGA1 "textures/sig_1.xpm"
# define CIGA2 "textures/sig_2.xpm"
# define CIGA3 "textures/sig_3.xpm"
# define CIGA4 "textures/sig_4.xpm"
# define CIGA5 "textures/sig_5.xpm"
# define CIGA6 "textures/sig_6.xpm"
# define PAC1 "textures/package_1.xpm"
# define PAC2 "textures/package_2.xpm"
# define PAC3 "textures/package_3.xpm"
# define PAC4 "textures/package_4.xpm"
# define PAC5 "textures/package_5.xpm"
# define PAC6 "textures/package_6.xpm"

// ARRAYS
# define COORD 5
# define COLORS 2
# define SPRITES 6

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
	WE,
	DO
};

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
	void			*game;
	int				*pixel;
	void			*imgs[COORD];
	int				*pixel_img[COORD];
	void			*cig_ani[SPRITES];
	int				*pixel_cig[SPRITES];
	void			*beer_anim[SPRITES];
	int				*pixel_beer[SPRITES];
	void			*pack_anim[SPRITES];
	int				*pixel_pack[SPRITES];
	unsigned int	c_color;
	unsigned int	f_color;
	unsigned int	mini_wall_color;
	unsigned int	mini_floor_color;
	unsigned int	mini_player_color;
	unsigned int	mini_empty_color; // 51, 51, 51
	int				wimg;
	int				himg;
	int				bpp; // bit per pixel, used for creating images
	int				size_line; // same as above
	int				endian; // same as above
}					t_mlx;

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
	int				temp_h;
	int				drawstart;
	int				drawend;
	float			wallx;
	float			step;
	int				texturex;
	int				texturey;
	float			textpos;
	unsigned int	color;
	int				posz;
}			t_ray;

typedef struct s_data
{
	t_mlx			mlx;
	t_ray			*ray;
	int				n_player;
	int				doors;
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
	int				animation;
	int				open;
	float			sober;
	float			pre_sober;
	int				info;
	long			t_animation;
	float			offset;
	long			fps;
	struct timeval	oldtime;
	struct timeval	newtime;
}					t_data;

// color_bonus.c
void			init_color(t_data *data);
size_t			create_trgb(size_t t, size_t r, size_t g, size_t b);
unsigned int	set_color(int side, int stepX, int stepY);
void			put_background(t_data *data, int *pixel);
void			print_vision_minimap(t_data *data);

// engine_bonus.c
int				*get_coordinates(int x, int y);
int				loop(t_data *data);

// free_bonus.c
void			free_textures(t_data *data, char **t);
void			free_all(t_data *data);
int				cross_close(t_data *data);

// init_all_bonus.c
void			init_data(char *line, t_data *data);
void			init_map_loop(t_data *data, char **line, int fd);
void			init_map(t_data *data, char *file);

// init_engine_bonus.c
int				init_mlx(t_data *data);
void			init_rotation(t_data *data);
int				init_engine(t_data *data);

// minimap_bonus.c
int				approx(float n);
void			display_minimap(t_data *data, int origin);
void			put_img_minimap(t_data *data);

// mouse_bonus.c
void			rotate(t_data *data);
int				mouse_control(int x, int y, t_data *data);

// move_bonus.c
int				key_handle(int key, t_data *data);
int				key_release(int key, t_data *data);
void			moving(t_data *data, float moveX, float moveY);
int				key_input(t_data *data);

// raycasting_2d_bonus.c
void			put_line(t_data *data, unsigned int color, int *star, int *end);
void			raycasting_2d(t_data *data);

// raycasting_2d_2_bonus.c
void			perform_dda(t_data *data);
void			calc_perp_distance(t_data *data);
void			calc_texture_info(t_data *data);
void			draw_wall_slice(t_data *data, int x);

// parse_file_bonus.c
int				parse_all(char **av, t_data *data);

// utils_bonus.c
char			*find_texture(char *line);
int				valid_rgb(char *rgb);
int				empty_line(char *line);
int				check_file_valid(char *file);
int				check_params(t_data *data);

// utils2_bonus.c
int				is_player(char c);
float			*player_pos(t_data *data);
void			put_color(unsigned int color, int *pixel, int *start, int *end);
int				is_map(char	*line);
char			get_char(t_data *data, int x, int y);

// action_bonus.c
void			open_door(t_data *data);

// init_sprites_bonus.c
void			init_beer(t_data *data, int w, int h);
void			init_cig(t_data *data, int w, int h);
void			init_pack(t_data *data, int w, int h);

// features_bonus.c
void			punk_feature(int key, t_data *data);
void			nod(int key, t_data *data);

// sprite_bonus.c
void			print_beer_animation(t_data *data, int *wh);
void			print_cig_animation(t_data *data, int *wh);
void			print_pack_animation(t_data *data, int *wh);

#endif