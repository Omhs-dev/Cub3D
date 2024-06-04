/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 04:27:18 by ohamadou          #+#    #+#             */
/*   Updated: 2024/06/04 06:13:32 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"

void	game_loop(void *ml)
{
	t_game	*mlx;

	mlx = ml;
	mlx_delete_image(mlx->mlx, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx, S_W, S_H);
	hook(mlx, 0, 0);
    // draw_ceiling_floor(mlx);
    cast_rays(mlx);
	mlx_image_to_window(mlx->mlx, mlx->img, 0, 0);
}

void init_the_player(t_game mlx)
{
	mlx.ply->player_x = mlx.g_map->player_x * TILE_SIZE + TILE_SIZE / 2;
	mlx.ply-> player_y= mlx.g_map->player_y * TILE_SIZE + TILE_SIZE / 2;
	mlx.ply->fov = (FOV * M_PI) / 180;
	mlx.ply->p_angle = M_PI;
}

int load_texture(t_texture *tex, t_map *game)
{
	// game->tex = (t_texture *)calloc(1, sizeof(t_texture));
	// if (!game->tex)
	// 	return (-1);
	printf("load texture\n");
	tex->east = mlx_load_png(game->east);
	tex->south = mlx_load_png(game->south);
	tex->north = mlx_load_png(game->north);
	tex->west = mlx_load_png(game->west);
	if (!tex->east || !tex->south || !tex->north || !tex->west)
        return (-1);
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
    // if (!mlx.mlx)
    //     return (1);
    if (load_texture(mlx.tex, mlx.g_map) == -1)
        return (1);
    init_the_player(mlx);
    mlx_loop_hook(mlx.mlx, &game_loop, &mlx);
    mlx_key_hook(mlx.mlx, &mlx_key, &mlx);
    mlx_loop(mlx.mlx);
    return (0);
}
