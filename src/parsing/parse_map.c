#include "../../includes/structs.h"

static int  count_lines(char **input)
{
    int i;
    char    *pool;

    pool = ft_strdup("NSEWFC\n");
    i = 0;
    while (*input && ft_strchr(pool, *input[0]) != 0)
        input++;
    free(pool);
    while (*input)
    {   
        i++;
        input++;
    }
    return (i);
}

static void copy_map(char **map, char **input)
{
    char    *pool;

    pool = ft_strdup("NSEWFC\n");
    while (*input && ft_strchr(pool, *input[0]) != 0)
        input++;
    free(pool);
    while (*input)
    {
        *map = ft_strdup(*input);
        map++;
        input++;
    }
}

void    parse_map(t_map *map, char **input)
{
    int i;
    char    **map2d;

    i = count_lines(input);
    if (i < 3)
    {
        free_double_char(input);
        free_map_struct(map);
        error(INVALID_MAP);
    }
    map2d = malloc(sizeof(char *) * (i + 1));
    map2d[i] = NULL;
    copy_map(map2d, input);
    while (*map2d)
    {    
        printf("%s", *map2d);
        map2d++;
    }
}
