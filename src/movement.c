#include "../includes/structs.h"

static void key_press(mlx_key_data_t key_game, void *param)
{
	t_game *game;

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

static void key_release(mlx_key_data_t key_game, t_game *game)
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

void mlx_key(mlx_key_data_t key_game, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (key_game.action == MLX_PRESS)
	{
		// printf("key press\n");
		key_press(key_game, game);
	}
	else if (key_game.action == MLX_RELEASE)
		key_release(key_game, game);
}
