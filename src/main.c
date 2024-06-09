#include "../includes/structs.h"

// int main(int argc, char **argv) {
//     t_map *game;
// 	// char **input;
	
// 	// game = (t_map *)calloc(1, sizeof(t_map));
// 	// if (argc < 2)
// 	// 	return (1);
//     game = parse(argc, argv);
//     // input = read_file(argv[1]);
//     // parse_description(game, input);
//     // printf("map: %s\n", game->map[0]);
//     // printf("direction: %s\n", game.g_map->map[1]);
//     start_the_game(game);

//     return (0);
// }

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <map_file>\n", argv[0]);
        return 1;
    }

    t_map *map = parse_map1(argv[1]);
    if (!map) {
        fprintf(stderr, "Failed to parse the map.\n");
        return 1;
    }
	
	start_the_game(map);
    // t_game mlx;
    // mlx.ply = (t_player *)calloc(1, sizeof(t_player));
    // mlx.ray = (t_ray *)calloc(1, sizeof(t_ray));
    // mlx.tex = (t_texture *)calloc(1, sizeof(t_texture));
    // mlx.g_map = map;
    // mlx.mlx = mlx_init(S_W, S_H, "Cub3D", 0);
    // if (!mlx.mlx) {
    //     fprintf(stderr, "Failed to initialize MLX.\n");
    //     return 1;
    // }

    // if (load_texture(mlx) == 1) {
    //     fprintf(stderr, "Failed to load textures.\n");
    //     return 1;
    // }

    // init_the_player(mlx);

    // mlx_loop_hook(mlx.mlx, &game_loop, &mlx);
    // mlx_loop(mlx.mlx);
    // mlx_close_window(mlx.mlx);

    return 0;
}