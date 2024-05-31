#include "../../includes/structs.h"

void    free_double_char(char **array)
{
    char    **copy;

    copy = array;
    while (*copy)
    {
        free(*copy);
        copy++;
    }
    free(array);
}

void    free_map_struct(t_map *map)
{
    free(map->north);
    free(map->south);
    free(map->west);
    free(map->east);
    free(map->ceiling);
    free(map->floor);
    if (map->map)
        free_double_char(map->map);
    free(map);
}

void	free_resources(t_game *mlx)
{
	if (mlx->ply)
		free(mlx->ply);
	if (mlx->ray)
		free(mlx->ray);
	if (mlx->mlx)
		mlx_terminate(mlx->mlx);
}