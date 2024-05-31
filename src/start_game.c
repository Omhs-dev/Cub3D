/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 04:27:18 by ohamadou          #+#    #+#             */
/*   Updated: 2024/05/31 07:07:01 by ohamadou         ###   ########.fr       */
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

int load_texture(t_texture *tex, t_map *game)
{
	// game->tex = (t_texture *)calloc(1, sizeof(t_texture));
	// if (!game->tex)
	// 	return (-1);
	tex->east = mlx_load_png(game->east);
	tex->south = mlx_load_png(game->south);
	tex->north = mlx_load_png(game->north);
	tex->west = mlx_load_png(game->west);
	if (!tex->east || !tex->south || !tex->north || !tex->west)
        return (-1);
	return (0);
}

// void	start_the_game(t_map *dt)	// start the game
// {
// 	t_game	mlx;

// 	mlx.g_map = dt;	// init the mlx structure
// 	mlx.ply = calloc(1, sizeof(t_player));	// init the player structure i'm using calloc to initialize the variables to zero
// 	mlx.ray = calloc(1, sizeof(t_ray));	// init the ray structure
// 	mlx.mlx = mlx_init(S_W, S_H, "Cub3D", 0);	// init the mlx pointer
// 	load_texture(dt);
// 	init_the_player(mlx);	// init the player structure
// 	mlx_loop_hook(mlx.mlx, &game_loop, &mlx);	// game loop
// 	mlx_key_hook(mlx.mlx, &mlx_key, &mlx);	// key press and release
// 	mlx_loop(mlx.mlx);	// mlx loop
// }

int start_the_game(t_map *dt)
{
    t_game mlx;

    mlx.g_map = dt;
    mlx.ply = (t_player *)calloc(1, sizeof(t_player));
    if (!mlx.ply)
        return (1);
    mlx.ray = (t_ray *)calloc(1, sizeof(t_ray));
    mlx.tex = (t_texture *)calloc(1, sizeof(t_texture));
    if (!mlx.ray)
        return (1);
    mlx.mlx = mlx_init(S_W, S_H, "Cub3D", 0);
    if (!mlx.mlx)
        return (1);
    if (!load_texture(mlx.tex, mlx.g_map))
    {
        return (-1);
        printf("not possible\n");
    }
    init_the_player(mlx);
    mlx_loop_hook(mlx.mlx, &game_loop, &mlx); 
    mlx_key_hook(mlx.mlx, &mlx_key, &mlx);
    mlx_loop(mlx.mlx);
    return (0);
}
