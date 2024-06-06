#include "../includes/structs.h"

int main(int argc, char **argv) {
    t_map game;
	// char **input;
	
	game = (t_map){};
	if (argc < 2)
		return (1);
    // game = parse(argc, argv);
    // input = read_file(argv[1]);
    parse_description(&game, read_file(argv[1]));
    // game =malloc(sizeof(t_map));
    parse_map(&game, read_file(argv[1]));
    // game.g_map = (t_map *)calloc(1, sizeof(t_map));
    // printf("map: %s\n", game->map[0]);
    // printf("direction: %s\n", game.g_map->map[1]);
    start_the_game(&game);

    return (0);
}
