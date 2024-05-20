/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 03:36:39 by ohamadou          #+#    #+#             */
/*   Updated: 2024/05/17 02:36:43 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

# include "cub3d.h"
# define S_W 1900 // screen width
# define S_H 1000 // screen height
# define TILE_SIZE 30 // tile size
# define FOV 60 // field of view
# define ROTATION_SPEED 0.045 // rotation speed
# define PLAYER_SPEED 4 // player speed

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

typedef struct s_ray {
    double ray_ngl; // Ray angle
    double distance; // Distance to the wall
    int flag; // Flag for the wall
} t_ray;

typedef struct s_game {
	int i;
	int j;
	char *name;
    mlx_t *mlx; // The mlx pointer
    mlx_image_t *img; // The image
    t_map *g_map; // The map structure
    t_ray *g_ray; // The map structure
    t_player *g_player; // The player structure
} t_game;

// Function Prototypes
void ft_exit(t_game *game);
void read_map(t_map *p);
void init_the_player(t_game *game);
int unit_circle(float angle, char c);
int inter_check(float angle, float *inter, float *step, int is_horizon);
void mlx_key(mlx_key_data_t keydata, void *game);
void game_loop(void *game);
// t_map *init_argument(const char *map_path);
t_map *init_argument();
void start_the_game(t_map *g_map);
void move_player(t_game *game, double move_x, double move_y);
void rotate_player(t_game *game, int i);
void hook(t_game *game, double move_x, double move_y);
void cast_rays(t_game *game);
void render_wall(t_game *game, int ray);
void draw_wall(t_game *game, int ray, int t_pix, int b_pix);
void draw_floor_ceiling(t_game *game, int ray, int t_pix, int b_pix);
float get_h_inter(t_game *game, float angl);
float get_v_inter(t_game *game, float angl);
float nor_angle(float angle);
int wall_hit(float x, float y, t_game *game);
void my_mlx_pixel_put(t_game *game, int x, int y, int color);
void	player_position(t_game *game);
void	output_map(t_game *game);
void ft_randomize(void* param);

#endif