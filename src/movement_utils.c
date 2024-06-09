/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:40:07 by ohamadou          #+#    #+#             */
/*   Updated: 2024/06/09 07:20:05 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"

static void	rotate_player(t_game *mlx)
{
	if (mlx->ply->rotation == 1)
	{
		mlx->ply->p_angle += ROTATION_SPEED;
		if (mlx->ply->p_angle > 2 * M_PI)
			mlx->ply->p_angle -= 2 * M_PI;
	}
	else if (mlx->ply->rotation == -1)
	{
		mlx->ply->p_angle -= ROTATION_SPEED;
		if (mlx->ply->p_angle < 0)
			mlx->ply->p_angle += 2 * M_PI;
	}
}

void	move_player(t_game *game, double move_x, double move_y)
{
	int		map_grid_y;
	int		map_grid_x;
	int		new_x;
	int		new_y;

	new_x = roundf(game->ply->player_x + move_x);
	new_y = roundf(game->ply->player_y + move_y);
	map_grid_x = (new_x / TILE_SIZE);
	map_grid_y = (new_y / TILE_SIZE);
	// if (map_grid_x >= 0 && map_grid_x < game->g_map->map_w
	// 	&& map_grid_y >= 0 && map_grid_y < game->g_map->map_h
	// 	&& game->g_map->map[map_grid_y][map_grid_x] != '1')
	// {
		game->ply->player_x = new_x;
		game->ply->player_y = new_y;
	// }
}

void move_hook(t_game *game, double move_x, double move_y)
{
	rotate_player(game);
	if (game->ply->direc_x == 1)
	{
		move_x = (-sin(game->ply->p_angle) * PLAYER_SPEED);
		move_y = (cos(game->ply->p_angle) * PLAYER_SPEED);
	}
	if (game->ply->direc_x == -1)
	{
		move_x = sin(game->ply->p_angle) * PLAYER_SPEED;
		move_y = -cos(game->ply->p_angle) * PLAYER_SPEED;
	}
	if (game->ply->direc_y == 1)
	{
		move_x = cos(game->ply->p_angle) * PLAYER_SPEED;
		move_y = sin(game->ply->p_angle) * PLAYER_SPEED;
	}
	if (game->ply->direc_y == -1)
	{
		move_x = -cos(game->ply->p_angle) * PLAYER_SPEED;
		move_y = -sin(game->ply->p_angle) * PLAYER_SPEED;
	}
	move_player(game, move_x, move_y);
}
