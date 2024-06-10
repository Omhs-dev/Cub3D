/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_description.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 05:29:33 by voszadcs          #+#    #+#             */
/*   Updated: 2024/06/10 05:29:50 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/cub3d.h"

static void	copy_rgb_value(int *n, char **values)
{
	n[0] = ft_atoi(values[0]);
	n[1] = ft_atoi(values[1]);
	n[2] = ft_atoi(values[2]);
}

static void	init_directions(char **input, t_map *map)
{
	char	**split;

	while (*input)
	{
		split = ft_split(*input, ' ');
		if (*input[0] == 'N')
			map->north = ft_strdup(split[1]);
		else if (*input[0] == 'S')
			map->south = ft_strdup(split[1]);
		else if (*input[0] == 'E')
			map->east = ft_strdup(split[1]);
		else if (*input[0] == 'W')
			map->west = ft_strdup(split[1]);
		free_double_char(split);
		input++;
	}
}

static void	init_rgb(char **input, t_map *map)
{
	char	**split;
	char	**values;

	while (*input)
	{
		values = NULL;
		split = ft_split(*input, ' ');
		if (*input[0] == 'F')
		{
			values = ft_split(split[1], ',');
			map->floor = malloc(sizeof(int) * 3);
			copy_rgb_value(map->floor, values);
		}
		else if (*input[0] == 'C')
		{
			values = ft_split(split[1], ',');
			map->ceiling = malloc(sizeof(int) * 3);
			copy_rgb_value(map->ceiling, values);
		}
		if (values)
			free_double_char(values);
		free_double_char(split);
		input++;
	}
}

static void	copy_description(char **in, char **out, t_map *map)
{
	char	**copy;
	int		i;

	copy = in;
	i = 0;
	while (*copy && i < 6)
	{
		if (*copy[0] != '\n')
		{
			out[i++] = ft_substr(*copy, 0, ft_strlen(*copy) - 1);
			copy++;
		}
		else
			copy++;
		if (!*copy && i < 5)
		{
			free_double_char(out);
			free_double_char(in);
			free(map);
			error(MAP_DESCRIPTION);
		}
	}
}

void	parse_description(t_map *map, char **input)
{
	char	**dscrptn;
	int		i;

	i = 0;
	dscrptn = malloc(sizeof(char *) * (6 + 1));
	while (i < 7)
		dscrptn[i++] = NULL;
	copy_description(input, dscrptn, map);
	if (!validate_descr(dscrptn))
	{
		free_double_char(input);
		free_double_char(dscrptn);
		free(map);
		error(MAP_DESCRIPTION);
	}
	init_directions(dscrptn, map);
	init_rgb(dscrptn, map);
	free_double_char(dscrptn);
}
