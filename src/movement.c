#include "../includes/structs.h"

// void mlx_key(mlx_key_data_t key_game, void *param)
// {
// 	t_game *game;
// 	double move_x = 0;
// 	double move_y = 0;

// 	game = (t_game *)param;
// 	if (key_game.key == MLX_KEY_ESCAPE && (key_game.action == MLX_PRESS
// 			|| key_game.action == MLX_REPEAT))
// 		mlx_close_window(game->mlx);
// 	else if (key_game.key == MLX_KEY_A && (key_game.action == MLX_PRESS
// 			|| key_game.action == MLX_REPEAT))
// 	{
// 		printf("press a\n");
// 		move_x = sin(game->ply->p_angle) * PLAYER_SPEED;
// 		move_y = -cos(game->ply->p_angle) * PLAYER_SPEED;
// 		move_player(game, move_x, move_y);
// 	}
// 	else if (key_game.key == MLX_KEY_D && (key_game.action == MLX_PRESS
// 			|| key_game.action == MLX_REPEAT))
// 	{
// 		move_x = -sin(game->ply->p_angle) * PLAYER_SPEED;
// 		move_y = cos(game->ply->p_angle) * PLAYER_SPEED;
// 		move_player(game, move_x, move_y);
// 	}
// 	else if (key_game.key == MLX_KEY_W && (key_game.action == MLX_PRESS
// 			|| key_game.action == MLX_REPEAT))
// 	{
// 		move_x = cos(game->ply->p_angle) * PLAYER_SPEED;
// 		move_y = sin(game->ply->p_angle) * PLAYER_SPEED;
// 		move_player(game, move_x, move_y);
// 	}
// 	else if (key_game.key == MLX_KEY_S && (key_game.action == MLX_PRESS
// 			|| key_game.action == MLX_REPEAT))
// 	{
// 		move_x = -cos(game->ply->p_angle) * PLAYER_SPEED;
// 		move_y = -sin(game->ply->p_angle) * PLAYER_SPEED;
// 		move_player(game, move_x, move_y);
// 	}
// 	else if (key_game.key == MLX_KEY_LEFT && (key_game.action == MLX_PRESS
// 			|| key_game.action == MLX_REPEAT))
// 	{
// 		game->ply->p_angle -= ROTATION_SPEED;
// 		if (game->ply->p_angle < 0)
// 			game->ply->p_angle += 2 * M_PI;
// 	}
// 	else if (key_game.key == MLX_KEY_RIGHT && (key_game.action == MLX_PRESS
// 			|| key_game.action == MLX_REPEAT))
// 	{
// 		game->ply->p_angle += ROTATION_SPEED;
// 		if (game->ply->p_angle > 2 * M_PI)
// 			game->ply->p_angle -= 2 * M_PI;
// 	}
// }

void ft_reles(mlx_key_data_t keydata, t_game *game) {
    if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
        game->ply->direc_x = 0;
    else if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
        game->ply->direc_y = 0;
    else if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
        game->ply->direc_y = 0;
    else if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
        game->ply->direc_x = 0;
    else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
        game->ply->rotation = 0;
    else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
        game->ply->rotation = 0;
}

void mlx_key(mlx_key_data_t keydata, void *game_ptr) {
    t_game *game = (t_game *)game_ptr;
    if (keydata.key == MLX_KEY_ESCAPE && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
        mlx_close_window(game->mlx);
    else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
    {
        printf("pos %d\n", game->ply->player_x);
        printf("dir %d\n", game->ply->direc_x);
        game->ply->direc_x = -1;
    }
    else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
        game->ply->direc_x = 1;
    else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
        game->ply->direc_y = -1;
        // game->ply->player_x = game->ply->player_x * game->ply->direc_x * game->ply->p_speed;
    else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
    {
        printf("posy %d\n", game->ply->player_y);
        printf("posx %d\n", game->ply->player_x);
        game->ply->direc_y = 1;
    }
    else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
        game->ply->rotation = -1;
    else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
        game->ply->rotation = 1;
    else if (keydata.key == MLX_KEY_LEFT_SHIFT && keydata.action == MLX_PRESS)
        game->ply->p_speed = PLAYER_SPEED;
    else if (keydata.key == MLX_KEY_LEFT_SHIFT && keydata.action == MLX_RELEASE)
        game->ply->p_speed = PLAYER_SPEED;

    ft_reles(keydata, game);
}

void	rotate_player(t_game *mlx, int i)	// rotate the player
{
	if (i == 1)
	{
		mlx->ply->p_angle += ROTATION_SPEED; // rotate right
		if (mlx->ply->p_angle > 2 * M_PI)
			mlx->ply->p_angle -= 2 * M_PI;
	}
	else
	{
		mlx->ply->p_angle -= ROTATION_SPEED; // rotate left
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
	if (map_grid_x >= 0 && map_grid_x < game->g_map->map_w
		&& map_grid_y >= 0 && map_grid_y < game->g_map->map_h
		&& game->g_map->map[map_grid_y][map_grid_x] != '1')
	{
		game->ply->player_x = new_x;
		game->ply->player_y = new_y;
	}
}

void hook(t_game *mlx, double move_x, double move_y) // hook the player
{
	if (mlx->ply->rotation == 1) //rotate right
		rotate_player(mlx, 1);
	if (mlx->ply->rotation == -1) //rotate left
		rotate_player(mlx, 0);
	if (mlx->ply->direc_x == 1) //move right
	{
		move_x = (-sin(mlx->ply->p_angle) * PLAYER_SPEED);
		move_y = (cos(mlx->ply->p_angle) * PLAYER_SPEED);
	}
	if (mlx->ply->direc_x == -1) //move left
	{
		move_x = sin(mlx->ply->p_angle) * PLAYER_SPEED;
		move_y = -cos(mlx->ply->p_angle) * PLAYER_SPEED;
	}
	if (mlx->ply->direc_y == 1) //move up
	{
		move_x = cos(mlx->ply->p_angle) * PLAYER_SPEED;
		move_y = sin(mlx->ply->p_angle) * PLAYER_SPEED;
	}
	if (mlx->ply->direc_y == -1) //move down
	{
		move_x = -cos(mlx->ply->p_angle) * PLAYER_SPEED;
		move_y = -sin(mlx->ply->p_angle) * PLAYER_SPEED;
	}
	move_player(mlx, move_x, move_y); // move the player
}
