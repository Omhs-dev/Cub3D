#include "../includes/structs.h"

int main(int argc, char **argv) {
    t_map *game;
	// char **input;
	
	// game = (t_map *)calloc(1, sizeof(t_map));
	// if (argc < 2)
	// 	return (1);
    game = parse(argc, argv);
    // input = read_file(argv[1]);
    // parse_description(game, input);
    // parse_map(game, input);
    // find_player_position(game);
    // printf("map: %s\n", game->map[0]);
    // printf("direction: %s\n", game.g_map->map[1]);
    start_the_game(game);

    return (0);
}

// int main(int argc, char **argv) {
//     if (argc != 2) {
//         fprintf(stderr, "Usage: %s <map_file>\n", argv[0]);
//         return 1;
//     }

//     t_map *map = parse_map1(argv[1]);
//     if (!map) {
//         fprintf(stderr, "Failed to parse the map.\n");
//         return 1;
//     }

// 	start_the_game(map);

//     return 0;
// }