/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 03:36:39 by ohamadou          #+#    #+#             */
/*   Updated: 2024/06/09 05:50:11 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
// include the mlx library

# define S_W 1900 // screen width
# define S_H 1000 // screen height
# define TILE_SIZE 30 // tile size
# define FOV 60 // field of view
# define ROTATION_SPEED 0.045 // rotation speed
# define PLAYER_SPEED 8	// player speed

///////////////////////parsing////////////////////
# define PLAYER_WID 64
# define PLAYER_HEI 64
# define PLAYER_STEP 32

// ERROR CODES
# define WRONG_ARGS_NUM 1
# define NAME_LENGTH 2
# define WRONG_EXTENSION 3
# define FILE_OPEN 4
# define MAP_DESCRIPTION 5
# define INVALID_MAP 6
//color
# define RED 0
# define GREEN 1
# define BLUE 2

# include "cub3d.h"
#include "../MLX42/include/MLX42/MLX42.h"

#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define WIDTH 512
#define HEIGHT 512
#define BPP sizeof(int32_t)

typedef struct s_player {
    int player_x; // Player x position in pixels
    int player_y; // Player y position in pixels
    int direc_x;
    int direc_y;
    int rotation;
    double p_angle; // Player angle
    double p_speed; // Player speed
    float fov; // Field of view
} t_player;

typedef struct s_texture
{
	mlx_texture_t *north;
	mlx_texture_t *south;
	mlx_texture_t *west;
	mlx_texture_t *east;
} t_texture;

typedef struct s_tmp
{
	int id;
}	t_tmp;

typedef struct s_map {
    char **map; // The map
    char **sec_map;
	char *north;
	char *south;
	char *east;
	char *west;
	char	**ff;
	char	**cc;
	int *floor;
	int *ceiling;
    int map_w; // Map width
    int map_h; // Map height
    int player_x;
    int player_y;
    // t_txtr *texx;
} t_map;

typedef struct s_ray	//the ray structure
{   
	int ray_i;
	double hor_x;
	double hor_y;
	double	ray_ngl;	// ray angle
	double	distance;	// distance to the wall
	int		flag;		// flag for the wall
	int hit_x;  // X-coordinate of the hit on the wall
    int hit_y;
    int is_vertical;
    t_texture *hit_tex;
}	t_ray;

typedef struct s_game	//the mlx structure
{
	mlx_t			*mlx;	// the mlx pointer
	mlx_image_t		*img;	// the image
	t_ray			*ray;	// the ray structure
	t_map			*g_map;	// the data structure
	t_player		*ply;	// the player structure
	t_texture       *tex;
	t_tmp           *temp;
}	t_game;

// typedef struct s_direction
// {
// 	char *north;
// 	char *south;
// 	char *east;
// 	char *weast;
// } t_direction;
char *get_next_lines(int fd);
char **read_files(const char *file_path);
void free_split(char **split);
int parse_colors(char *line, int **colors);
t_map *parse_map1(const char *file_path);
//parsing
char **read_file(const char *file);
char	    *get_next_line(int fd);
t_map		*parse(int argc, char **argv);
void        parse_description(t_map *map, char **input);
int         validate_descr(char **input);
int         is_rgb_value(char *str);
void        parse_map(t_map *map, char **input);
//general utils
int			error(int errnum);
void        free_double_char(char **array);
void        free_map_struct(t_map *map);
//redering
void ft_put_pixel(t_game *game, int x, int y, int c);
uint32_t rgb_color(int r, int g, int b, int a);
// int get_color(int c);
unsigned int get_color(int c);
// double get_x_offset(mlx_texture_t *tex, t_game *game);
double	get_x_offset(mlx_texture_t *texture, t_game *data);
// void mlx_key(mlx_key_data_t key_game, void *param);
void mlx_key(mlx_key_data_t key_game, void *param);
void	move_player(t_game *game, double move_x, double move_y);
// start game
int load_texture(t_game game);
// int load_texture(t_texture *tex, t_map *game);
void	ft_exit(t_game *mlx);
//floor
// void	draw_ceiling_floor(t_game *mlx, int ray, int t_pix, int b_pix);
// void draw_ceiling_floor(t_game *mlx);
void	draw_ceiling_floor(t_game *mlx, int ray, int t_pix, int b_pix);
void	draw_wall(t_game *mlx, int t_pix, int b_pix, double wall_h);
// void	render_wall(t_game *mlx, int ray);
float	nor_angle(float angle);
int	unit_circle(float angle, char c);
int	inter_check(float angle, float *inter, float *step, int is_horizon);
int	wall_hit(float x, float y, t_game *mlx);
float	get_h_inter(t_game *mlx, float angl);
float	get_v_inter(t_game *mlx, float angl);
void	cast_rays(t_game *mlx);
void	game_loop(void *ml);
void init_the_player(t_game mlx);	// init the player structure
int start_the_game(t_map *dt);
// int	load_textures(t_game *cub3d);
char **ft_splittt(char *s, char c);
void move_hook(t_game *game, double move_x, double move_y);
void	get_angle(t_game *mlx);
void	render_wall(t_game *mlx, int ray);
void render_walls(t_game *mlx);
// mlx_texture_t	*wall_texture(t_game *mlx, double flag);
mlx_texture_t	*wall_texture(t_game *mlx, int flag);
// int	load_texture(t_texture *tex, t_txtr *l_ture);
void	move_player(t_game *data, double move_x, double move_y);
void mlx_key(mlx_key_data_t key_game, void *param);

#endif