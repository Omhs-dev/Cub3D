/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 08:52:16 by ohamadou          #+#    #+#             */
/*   Updated: 2024/06/12 04:40:10 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	key_press(mlx_key_data_t key_game, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (key_game.key == MLX_KEY_ESCAPE && (key_game.action == MLX_PRESS))
		mlx_close_window(game->mlx);
	else if (key_game.key == MLX_KEY_D && (key_game.action == MLX_PRESS))
		game->ply->direc_x = 1;
	else if (key_game.key == MLX_KEY_A && (key_game.action == MLX_PRESS))
		game->ply->direc_x = -1;
	else if (key_game.key == MLX_KEY_W && (key_game.action == MLX_PRESS))
		game->ply->direc_y = 1;
	else if (key_game.key == MLX_KEY_S && (key_game.action == MLX_PRESS))
		game->ply->direc_y = -1;
	else if (key_game.key == MLX_KEY_RIGHT && (key_game.action == MLX_PRESS))
		game->ply->rotation = 1;
	else if (key_game.key == MLX_KEY_LEFT && (key_game.action == MLX_PRESS))
		game->ply->rotation = -1;
}

void	key_release(mlx_key_data_t key_game, t_game *game)
{
	if (key_game.key == MLX_KEY_D && key_game.action == MLX_RELEASE)
		game->ply->direc_x = 0;
	else if (key_game.key == MLX_KEY_A && key_game.action == MLX_RELEASE)
		game->ply->direc_x = 0;
	else if (key_game.key == MLX_KEY_S && key_game.action == MLX_RELEASE)
		game->ply->direc_y = 0;
	else if (key_game.key == MLX_KEY_W && key_game.action == MLX_RELEASE)
		game->ply->direc_y = 0;
	else if (key_game.key == MLX_KEY_LEFT && key_game.action == MLX_RELEASE)
		game->ply->rotation = 0;
	else if (key_game.key == MLX_KEY_RIGHT && key_game.action == MLX_RELEASE)
		game->ply->rotation = 0;
}

void	mlx_key(mlx_key_data_t key_game, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (key_game.action == MLX_PRESS)
		key_press(key_game, game);
	else if (key_game.action == MLX_RELEASE)
		key_release(key_game, game);
}
