/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 04:27:18 by ohamadou          #+#    #+#             */
/*   Updated: 2024/05/16 12:28:15 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"

void game_loop(void *game_ptr) {
    t_game *game = (t_game *)game_ptr;
    mlx_delete_image(game->mlx, game->img); // Delete the image
    game->img = mlx_new_image(game->mlx, S_W, S_H); // Create new image
    hook(game, 0, 0); // Hook the player
    cast_rays(game); // Cast the rays
    mlx_image_to_window(game->mlx, game->img, 0, 0); // Put the image to the window
}

void start_the_game(t_map *map) {
    t_game game;
    game.g_map = map;
    game.g_player = malloc(sizeof(t_player)); // Init the player structure
    game.g_ray = calloc(1, sizeof(t_ray));
    game.mlx = mlx_init(S_W, S_H, "Cub3D", 0); // Init the mlx pointer
    // init_the_player(&game); // Init the player structure
    output_map(&game);
    mlx_loop_hook(game.mlx, &game_loop, &game); // Game loop
    // mlx_loop_hook(game.mlx, &ft_randomize, &game); // Game loop
    mlx_key_hook(game.mlx, &mlx_key, &game); // Key press and release
    mlx_loop(game.mlx); // Mlx loop
    ft_exit(&game); // Exit the game
}
