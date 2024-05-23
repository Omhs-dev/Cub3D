/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 04:05:35 by ohamadou          #+#    #+#             */
/*   Updated: 2024/05/21 14:18:18 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_the_player(t_game *game) {
    game->g_player->player_x = game->g_map->player_x * TILE_SIZE + TILE_SIZE / 2; // Player x position in pixels in the center of the tile
    game->g_player->player_y = game->g_map->player_y * TILE_SIZE + TILE_SIZE / 2; // Player y position in pixels in the center of the tile
    game->g_player->fov = (FOV * M_PI) / 180; // Field of view in radians
    game->g_player->p_angle = M_PI; // Player angle
    game->g_player->p_speed = PLAYER_SPEED; // Player speed
}


t_map *init_argument() // init the data structure
{
 t_map *dt = NULL; // init the data structure
 
 dt = calloc(1, sizeof(t_map));
 dt->map = calloc(10, sizeof(char *)); // init the map
 dt->map[0] = strdup("1111111111111111111111111"); //fill the map
 dt->map[1] = strdup("1000000000000000000100001");
 dt->map[2] = strdup("1001000000000000000000001");
 dt->map[3] = strdup("1001000000000000001000001");
 dt->map[4] = strdup("1001000000000000001000001");
 dt->map[5] = strdup("1001000000100000001000001");
 dt->map[6] = strdup("100100000000P000001000001");
 dt->map[7] = strdup("1001000000001000001000001");
 dt->map[8] = strdup("1111111111111111111111111");
 dt->map[9] = NULL;
 dt->player_y = 3; // player y position in the map
 dt->player_x = 14; // player x position in the map
 dt->map_w = 25; // map width
 dt->map_h = 9; // map height
 return (dt); // return the data structure
}

// t_game *init_argument() {
//     t_game *dt = calloc(1, sizeof(t_game)); // Correct allocation for t_game
//     if (!dt) {
//         perror("Failed to allocate memory for t_game");
//         exit(EXIT_FAILURE);
//     }

//     dt->g_map = calloc(1, sizeof(t_map)); // Allocate memory for t_map
//     if (!dt->g_map) {
//         perror("Failed to allocate memory for t_map");
//         free(dt);
//         exit(EXIT_FAILURE);
//     }

//     dt->g_map->map = calloc(10, sizeof(char *)); // Allocate memory for the map array
//     if (!dt->g_map->map) {
//         perror("Failed to allocate memory for map array");
//         free(dt->g_map);
//         free(dt);
//         exit(EXIT_FAILURE);
//     }

//     // Fill the map
//     dt->g_map->map[0] = strdup("1111111111111111111111111");
//     dt->g_map->map[1] = strdup("1000000000000000000100001");
//     dt->g_map->map[2] = strdup("1001000000000P00000000001");
//     dt->g_map->map[3] = strdup("1001000000000000001000001");
//     dt->g_map->map[4] = strdup("1001000000000000001000001");
//     dt->g_map->map[5] = strdup("1001000000100000001000001");
//     dt->g_map->map[6] = strdup("1001000000000000001000001");
//     dt->g_map->map[7] = strdup("1001000000001000001000001");
//     dt->g_map->map[8] = strdup("1111111111111111111111111");
//     dt->g_map->map[9] = NULL;

//     dt->g_map->map_w = 25; // Map width
//     dt->g_map->map_h = 9; // Map height

//     dt->g_player = calloc(1, sizeof(t_player)); // Allocate memory for player
//     if (!dt->g_player) {
//         perror("Failed to allocate memory for t_player");
//         for (int i = 0; dt->g_map->map[i]; i++) {
//             free(dt->g_map->map[i]);
//         }
//         free(dt->g_map->map);
//         free(dt->g_map);
//         free(dt);
//         exit(EXIT_FAILURE);
//     }

//     dt->g_player->player_y = 3; // Player y position
//     dt->g_player->player_x = 14; // Player x position

//     return dt;
// }