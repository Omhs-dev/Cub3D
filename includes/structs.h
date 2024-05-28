/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 03:36:39 by ohamadou          #+#    #+#             */
/*   Updated: 2024/05/28 19:48:29 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
// include the mlx library

# define S_W 1900 // screen width
# define S_H 1000 // screen height
# define TILE_SIZE 30 // tile size
# define FOV 60 // field of view
# define ROTATION_SPEED 0.090 // rotation speed
# define PLAYER_SPEED 8	// player speed

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
    double fov; // Field of view
} t_player;

typedef struct s_map {
    char **map; // The map
    int map_w; // Map width
    int map_h; // Map height
    int player_x;
    int player_y;
} t_map;

typedef struct s_ray	//the ray structure
{
	double	ray_ngl;	// ray angle
	double	distance;	// distance to the wall
	int		flag;		// flag for the wall
}	t_ray;

typedef struct s_game	//the mlx structure
{
	mlx_t			*mlx;	// the mlx pointer
	mlx_image_t		*img;	// the image
	t_ray			*ray;	// the ray structure
	t_map			*g_map;	// the data structure
	t_player		*ply;	// the player structure
}	t_game;

// Function Prototypes
// void ft_hook(mlx_key_data_t key_game, void *param);
// t_data *init_argument();
// void start_the_game(t_data *data);
// void render_player(t_data *data);
// void output_map(t_data *dat);
// void mlx_key(mlx_key_data_t keydata, void *ml);
void mlx_key(mlx_key_data_t key_game, void *param);
void	move_player(t_game *game, double move_x, double move_y);
void	hook(t_game *mlx, double move_x, double move_y);
void	ft_exit(t_game *mlx);
void	draw_floor_ceiling(t_game *mlx, int ray, int t_pix, int b_pix);
int	get_color(t_game *mlx, int flag);
void	draw_wall(t_game *mlx, int ray, int t_pix, int b_pix);
void	render_wall(t_game *mlx, int ray);
float	nor_angle(float angle);
int	unit_circle(float angle, char c);
int	inter_check(float angle, float *inter, float *step, int is_horizon);
int	wall_hit(float x, float y, t_game *mlx);
float	get_h_inter(t_game *mlx, float angl);
float	get_v_inter(t_game *mlx, float angl);
void	cast_rays(t_game *mlx);
void	game_loop(void *ml);
void init_the_player(t_game mlx);	// init the player structure
void	start_the_game(t_map *dt);	// start the game

#endif