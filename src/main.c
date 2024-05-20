// #include "../includes/structs.h"
#include "../MLX42/include/MLX42/MLX42.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>
#define WIDTH 512
#define HEIGHT 512
// int main(int argc, char **argv) {
//     if (argc != 2) {
//         fprintf(stderr, "Usage: %s <map_file>\n", argv[0]);
//         return EXIT_FAILURE;
//     }
//     t_map *map = init_argument(argv[1]);
    
//     start_the_game(map);
//     return EXIT_SUCCESS;
// }
// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// #include <MLX42/MLX42.h>

#define WIDTH 512
#define HEIGHT 512

typedef struct s_data 
{
	mlx_t *mlx;
	mlx_image_t *image;
	mlx_texture_t *renderimg;
}   t_data;

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void ft_hook(void* param)
{
	t_data *data = param;

	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
		data->image->instances[0].y -= 5;
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
		data->image->instances[0].y += 5;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		data->image->instances[0].x -= 5;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		data->image->instances[0].x += 5;
}


int main()
{
	t_data *data;
	data = malloc(sizeof(t_data));
	if (!data)
		error();
	
	data->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	
	
	data->renderimg = mlx_load_png("../assets/wall6.png");
	
	data->image = mlx_new_image(data->mlx, 180, 180);
	
	data->image = mlx_texture_to_image(data->mlx, data->renderimg);
	
	mlx_image_to_window(data->mlx, data->image, 0, 0);
	
	mlx_loop(data->mlx);
	mlx_loop_hook(data->mlx, ft_hook, data->mlx);
	
	mlx_delete_image(data->mlx, data->image);
	mlx_delete_texture(data->renderimg);
	mlx_terminate(data->mlx);
	return (0);
}
