#include "../includes/structs.h"

void ft_reles(mlx_key_data_t keydata, t_game *game) {
    if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
        game->g_player->direc_x = 0;
    else if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
        game->g_player->direc_y = 0;
    else if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
        game->g_player->direc_y = 0;
    else if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
        game->g_player->direc_x = 0;
    else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
        game->g_player->rotation = 0;
    else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
        game->g_player->rotation = 0;
}

void mlx_key(mlx_key_data_t keydata, void *game_ptr) {
    t_game *game = (t_game *)game_ptr;
    if (keydata.key == MLX_KEY_ESCAPE && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
        ft_exit(game);
    else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
        game->g_player->direc_x = -1;
    else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
        game->g_player->direc_x = 1;
    else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
        game->g_player->direc_y = -1;
    else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
        game->g_player->direc_y = 1;
    else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
        game->g_player->rotation = -1;
    else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
        game->g_player->rotation = 1;
    else if (keydata.key == MLX_KEY_LEFT_SHIFT && keydata.action == MLX_PRESS)
        game->g_player->p_speed = 20;
    else if (keydata.key == MLX_KEY_LEFT_SHIFT && keydata.action == MLX_RELEASE)
        game->g_player->p_speed = PLAYER_SPEED;

    ft_reles(keydata, game);
}

void move_player(t_game *game, double move_x, double move_y) {
    if (!wall_hit(game->g_player->player_x + move_x, game->g_player->player_y, game))
        game->g_player->player_x += move_x;
    if (!wall_hit(game->g_player->player_x, game->g_player->player_y + move_y, game))
        game->g_player->player_y += move_y;
}

void rotate_player(t_game *game, int i) {
    game->g_player->p_angle += i * ROTATION_SPEED;
    game->g_player->p_angle = nor_angle(game->g_player->p_angle);
}

void hook(t_game *game, double move_x, double move_y) {
    if (game->g_player->rotation != 0)
        rotate_player(game, game->g_player->rotation);
    if (game->g_player->direc_x != 0) {
        move_x = cos(nor_angle(game->g_player->p_angle + (90 * M_PI) / 180)) * game->g_player->p_speed;
        move_y = sin(nor_angle(game->g_player->p_angle + (90 * M_PI) / 180)) * game->g_player->p_speed;
        move_player(game, move_x * game->g_player->direc_x, move_y * game->g_player->direc_x);
    }
    if (game->g_player->direc_y != 0) {
        move_x = cos(game->g_player->p_angle) * game->g_player->p_speed;
        move_y = sin(game->g_player->p_angle) * game->g_player->p_speed;
        move_player(game, move_x * game->g_player->direc_y, move_y * game->g_player->direc_y);
    }
}
