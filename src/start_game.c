/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 04:27:18 by ohamadou          #+#    #+#             */
/*   Updated: 2024/05/30 04:09:38 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"

//##############################################################################################//
//############################## START THE GAME AND THE GAME LOOP ##############################//
//##############################################################################################//

void	game_loop(void *ml)	// game loop
{
	t_game	*mlx;

	mlx = ml;	// cast to the mlx structure
	mlx_delete_image(mlx->mlx, mlx->img);	// delete the image
	mlx->img = mlx_new_image(mlx->mlx, S_W, S_H);	// create new image
	// hook(mlx, 0, 0); // hook the player
	cast_rays(mlx);	// cast the rays
	mlx_image_to_window(mlx->mlx, mlx->img, 0, 0); // put the image to the window
}

void init_the_player(t_game mlx)	// init the player structure
{
	mlx.ply->player_x = mlx.g_map->player_x * TILE_SIZE + TILE_SIZE / 2; // player x position in pixels in the center of the tile
	mlx.ply-> player_y= mlx.g_map->player_y * TILE_SIZE + TILE_SIZE / 2; // player y position in pixels in the center of the tile
	mlx.ply->fov = (FOV * M_PI) / 180; // field of view in radians
	mlx.ply->p_angle = M_PI; // player angle
	//the rest of the variables are initialized to zero by calloc
}

void	start_the_game(t_map *dt)	// start the game
{
	t_game	mlx;

	mlx.g_map = dt;	// init the mlx structure
	mlx.ply = calloc(1, sizeof(t_player));	// init the player structure i'm using calloc to initialize the variables to zero
	mlx.ray = calloc(1, sizeof(t_ray));	// init the ray structure
	mlx.mlx = mlx_init(S_W, S_H, "Cub3D", 0);	// init the mlx pointer
	init_the_player(mlx);	// init the player structure
	mlx_loop_hook(mlx.mlx, &game_loop, &mlx);	// game loop
	mlx_key_hook(mlx.mlx, &mlx_key, &mlx);	// key press and release
	mlx_loop(mlx.mlx);	// mlx loop
}
