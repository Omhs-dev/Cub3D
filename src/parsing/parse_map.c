/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 05:30:11 by voszadcs          #+#    #+#             */
/*   Updated: 2024/06/10 05:32:32 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/cub3d.h"

static int	count_lines(char **input)
{
	int		i;
	char	*pool;

	pool = ft_strdup("NSEWFC\n");
	i = 0;
	while (*input && ft_strchr(pool, *input[0]) != 0)
		input++;
	free(pool);
	while (*input)
	{
		if (*input[0] == '\n')
			return (0);
		i++;
		input++;
	}
	if (i > 2 && (*(*(input - 1) + ft_strlen(*(input - 1)) - 1)) == '\n')
		return (0);
	return (i);
}

static void	copy_map(char **map, char **input)
{
	char	*pool;

	pool = ft_strdup("NSEWFC\n");
	while (*input && ft_strchr(pool, *input[0]) != 0)
		input++;
	free(pool);
	while (*input)
	{
		if (input + 1 != NULL)
			*map = ft_substr(*input, 0, ft_strlen(*input) - 1);
		else
			*map = ft_strdup(*input);
		map++;
		input++;
	}
}

int	map_width(char **map)
{
	int		current;
	int		prev;
	char	*temp;

	current = 0;
	prev = 0;
	while (*map)
	{
		temp = *map;
		while (*temp)
		{
			temp++;
			current++;
		}
		if (current > prev)
			prev = current;
		current = 0;
		map++;
	}
	return (prev);
}

static void	find_player_position(t_map *data)
{
	int	x;
	int	y;

	y = 0;
	while (++y < data->map_h)
	{
		x = 0;
		while (++x < data->map_w)
		{
			if (data->map2d[y][x] == 'N' || data->map2d[y][x] == 'S' ||
				data->map2d[y][x] == 'E' || data->map2d[y][x] == 'W')
			{
				data->player_x = x;
				data->player_y = y;
				data->map2d[y][x] = '0';
				return ;
			}
		}
	}
	data->player_x = -1;
	data->player_y = -1;
}

void	parse_map(t_map *map, char **input)
{
	int		i;
	char	**map2d;

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
	map->map2d = map2d;
	map->map_h = i;
	map->map_w = map_width(map2d);
	printf("MAP POS: %d %d\n", map->map_h, map->map_w);
	free_double_char(input);
	if (!valid_map(map2d))
	{
		free_map_struct(map);
		error(INVALID_MAP);
	}
	find_player_position(map);
}
