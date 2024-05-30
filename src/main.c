#include "../includes/structs.h"

//##############################################################################//
//############################## THE EXITING CODE ##############################//
//##############################################################################//

void	ft_exit(t_game *mlx) 		// exit the game
{
	int	i = 0;
	while (mlx->g_map->map[i])
		free(mlx->g_map->map[i++]); // free the map line by line
	free(mlx->g_map->map); // free the map
	free(mlx->g_map); // free the data structure
	free(mlx->ply); // free the player structure
	free(mlx->ray); // free the ray structure
	mlx_delete_image(mlx->mlx, mlx->img); // delete the image
	mlx_close_window(mlx->mlx); // close the window
	mlx_terminate(mlx->mlx); // terminate the mlx pointer
	printf("Game closed\n"); // print the message
	exit(0); // exit the game
}

//################################################################################################//
//############################## THE MAIN FUNCTION AND INIT THE MAP ##############################//
//################################################################################################//

void player_position(t_map *data)
{
	int i;
	int j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				printf("char: %c\n", data->map[i][j]);
				data->player_x = j;
				data->player_y = i;
				break ;
			}
			j++;
		}
		i++;
	}
}

t_map *init_argument()	// init the data structure
{
	t_map *dt = calloc(1, sizeof(t_map)); // init the data structure
	dt->map = calloc(10, sizeof(char *)); // init the map
	dt->map[0] = strdup("1111111111111111111111111"); //fill the map
	dt->map[1] = strdup("1000000000000000000100001");
	dt->map[2] = strdup("1001000000000000000000001");
	dt->map[3] = strdup("1001000000000000001000001");
	dt->map[4] = strdup("1001000000000000001000001");
	dt->map[5] = strdup("1001000000100000001000001");
	dt->map[6] = strdup("1001000000000000001000001");
	dt->map[7] = strdup("1001000000001000001000P01");
	dt->map[8] = strdup("1111111111111111111111111");
	dt->map[9] = NULL;
	
	
	// dt->player_y = 3; // player y position in the map
	// dt->player_x = 14; // player x position in the map
	dt->map_w = 25; // map width
	dt->map_h = 9; // map height
	player_position(dt);
	return (dt); // return the data structure
}

int main(int argc, char **argv)	// main function
{
	t_map	*data;

	data = parse(argc, argv);
	start_the_game(data);
	return (0);
}
