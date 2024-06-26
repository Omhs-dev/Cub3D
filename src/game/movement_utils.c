/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 19:40:07 by ohamadou          #+#    #+#             */
/*   Updated: 2024/06/12 20:43:09 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	rotate_player(t_game *mlx)
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

int	is_position_valid(t_game *game, double new_x, double new_y)
{
	double	buffer;
	int		n_grid_x;
	int		n_grid_y;

	buffer = 1.0;
	n_grid_x = (int)(new_x / TILE_SIZE);
	n_grid_y = (int)(new_y / TILE_SIZE);
	if (
		n_grid_x >= 0 && n_grid_x < game->g_map->map_w
		&& n_grid_y >= 0 && n_grid_y < game->g_map->map_h
		&& game->g_map->map2d[n_grid_y][n_grid_x] != '1'
		&& game->g_map->map2d[(int)((new_y + buffer)
		/ TILE_SIZE)][n_grid_x] != '1' &&
		game->g_map->map2d[(int)((new_y - buffer)
		/ TILE_SIZE)][n_grid_x] != '1' &&
		game->g_map->map2d[n_grid_y][(int)((new_x + buffer)
		/ TILE_SIZE)] != '1' &&
		game->g_map->map2d[n_grid_y][(int)((new_x - buffer)
		/ TILE_SIZE)] != '1'
		)
		return (1);
	return (0);
}

void	move_player(t_game *game, double move_x, double move_y)
{
	double	new_x;
	double	new_y;

	new_x = roundf(game->ply->player_x + move_x);
	new_y = roundf(game->ply->player_y + move_y);
	if (is_position_valid(game, new_x, new_y))
	{
		game->ply->player_x = new_x;
		game->ply->player_y = new_y;
	}
}

void	move_hook(t_game *game, double move_x, double move_y)
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
