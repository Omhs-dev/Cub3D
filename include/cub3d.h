/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 07:37:54 by ohamadou          #+#    #+#             */
/*   Updated: 2024/06/10 09:02:15 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// ERROR CODES
# define WRONG_ARGS_NUM 1
# define NAME_LENGTH 2
# define WRONG_EXTENSION 3
# define FILE_OPEN 4
# define MAP_DESCRIPTION 5
# define INVALID_MAP 6
# define LOAD_TEXTURES 7
// misc
# define S_W 1900
# define S_H 1000
# define TILE_SIZE 16
# define FOV 60
# define ROTATION_SPEED 0.045
# define PLAYER_SPEED 1
# define M_PI 3.14159265358979323846
//color
# define RED 0
# define GREEN 1
# define BLUE 2
//includes
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include "../lib/libft/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../src/get_next_line/get_next_line.h"

typedef struct s_map
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		*floor;
	int		*ceiling;
	char	**map2d;
    int		map_w;
    int		map_h;
    int		player_x;
    int		player_y;
}	t_map;

typedef struct s_player
{
    int		player_x;
    int		player_y;
    int		direc_x;
    int		direc_y;
    int		rotation;
    float	fov;
    double	p_angle;
    double	p_speed;
}	t_player;

typedef struct s_texture
{
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*west;
	mlx_texture_t	*east;
}	t_texture;

typedef struct s_ray
{
	int			ray_i;
	double		hor_x;
	double		hor_y;
	double		ray_ngl;
	double		distance;
	int			flag;
	int			hit_x;
    int			hit_y;
    int			is_vertical;
    t_texture	*hit_tex;
}	t_ray;

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_ray			*ray;
	t_map			*g_map;
	t_player		*ply;
	t_texture		*tex;
}	t_game;

//parsing
char	    *get_next_line(int fd);
t_map		*parse(int argc, char **argv);
void        parse_description(t_map *map, char **input);
int         validate_descr(char **input);
int         is_rgb_value(char *str);
void        parse_map(t_map *map, char **input);
int         valid_map(char **map);
//general utils
int			error(int errnum);
void        free_double_char(char **array);
void        free_map_struct(t_map *map);
void        free_game_struct(t_game *game);
void        free_text_struct(t_texture *text);
//game
void        start_the_game(t_map *map);
void 		mlx_key(mlx_key_data_t key_game, void *param);
void 		move_hook(t_game *game, double move_x, double move_y);
void		render_wall(t_game *mlx, int ray);
void		ray_casting(t_game *game);
float		nor_angle(float angle);
int	check_u_circle(float angle, char c);
void 		ft_put_pixel(t_game *game, int x, int y, int c);
uint32_t 	rgb_color(int r, int g, int b, int a);
unsigned int get_color(int c);
double		get_x_offset(mlx_texture_t *texture, t_game *data);

#endif