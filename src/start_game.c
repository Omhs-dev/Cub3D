/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 04:27:18 by ohamadou          #+#    #+#             */
/*   Updated: 2024/06/08 19:27:35 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"

void	game_loop(void *ml)
{
	t_game	*mlx;

	mlx = ml;
	mlx_delete_image(mlx->mlx, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx, S_W, S_H);
	move_hook(mlx, 0, 0);
	// draw_ceiling_floor(mlx);
	cast_rays(mlx);
	mlx_image_to_window(mlx->mlx, mlx->img, 0, 0);
}

void init_the_player(t_game mlx)
{
	mlx.ply->player_x = (mlx.g_map->player_x * TILE_SIZE) + TILE_SIZE / 2;
	mlx.ply->player_y = (mlx.g_map->player_y * TILE_SIZE) + TILE_SIZE / 2;
	mlx.ply->fov = (FOV * M_PI / 180);
	mlx.ply->p_angle = M_PI;
	printf("map pos %d\n", mlx.g_map->player_x);
	printf("player pos %d\n", mlx.ply->player_x);
}

int load_texture(t_game game)
{
	printf("load texture\n");
	game.tex->east = mlx_load_png(game.g_map->east);
	game.tex->south = mlx_load_png(game.g_map->south);
	game.tex->north = mlx_load_png(game.g_map->north);
	game.tex->west = mlx_load_png(game.g_map->west);
	if (!game.tex->east || !game.tex->south
		|| !game.tex->north || !game.tex->west)
		return (printf("Failed to load textures\n"), 1);
	return (0);
}

int start_the_game(t_map *dt)
{
	t_game mlx;

	mlx.ply = (t_player *)calloc(1, sizeof(t_player));
	// if (!mlx.ply)
	//     return (1);
	mlx.ray = (t_ray *)calloc(1, sizeof(t_ray));
	mlx.tex = (t_texture *)calloc(1, sizeof(t_texture));
	// if (!mlx.ray)
	//     return (1);
	mlx.g_map = dt;
	mlx.mlx = mlx_init(S_W, S_H, "Cub3D", 0);
	if (load_texture(mlx) == 1)
		return (1);
	// if (!mlx.mlx)
	//     return (1);
	printf("here\n");
	printf("direction: %s\n", mlx.g_map->east);
	init_the_player(mlx);
	mlx_loop_hook(mlx.mlx, &game_loop, &mlx);
	mlx_key_hook(mlx.mlx, &mlx_key, &mlx);
	mlx_loop(mlx.mlx);
	mlx_close_window(mlx.mlx);
	
	for (int i = 0; i < dt->map_h; i++)
        free(dt->map[i]);
    free(dt->map);
    free(dt->north);
    free(dt->south);
    free(dt->east);
    free(dt->west);
    free(dt->floor);
    free(dt->ceiling);
    free(dt);
    free(mlx.ply);
    free(mlx.ray);
    free(mlx.tex);
	
	return (0);
}
