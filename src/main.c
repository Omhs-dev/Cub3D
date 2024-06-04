#include "../includes/structs.h"

int main(int argc, char **argv) {
    t_game game;
	
	game = (t_game){};
    game.g_map = parse(argc, argv);
    // game.g_map = (t_map *)calloc(1, sizeof(t_map));
    // printf("map: %s\n", game.g_map->map[1]);
    start_the_game(game.g_map);

    return (0);
}
