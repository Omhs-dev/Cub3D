/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 05:33:10 by voszadcs          #+#    #+#             */
/*   Updated: 2024/06/10 05:34:14 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/cub3d.h"

static int	check_chars(char **map)
{
	char	*temp;
	char	*pool;
	int		flag;

	flag = 0;
	pool = ft_strdup("01NSEW");
	while (*map)
	{
		temp = *map;
		while (*temp)
		{
			if (*temp == ' ')
				*temp = '1';
			if (*temp == 'N' || *temp == 'S'
				|| *temp == 'E' || *temp == 'W')
				flag++;
			if (!ft_strchr(pool, *temp) || flag > 1)
				return (free(pool), 0);
			temp++;
		}
		map++;
	}
	return (free(pool), flag);
}


static int	check_walls(char **map)
{
	char	*line;

	line = *map;
	while (*line)
	{
		if (*line != '1')
			return (0);
		line++;
	}
	while (*map)
	{
		line = *map;
		if (line[0] != '1' || line[ft_strlen(line) - 1] != '1')
			return (0);
		if (*(map + 1) == NULL)
		{
			while (*line)
			{
				if (*line != '1')
					return (0);
				line++;
			}
		}
		map++;
	}
	return (1);
}

int	valid_map(char **map)
{
	if (!check_chars(map) || !check_walls(map))
		return (0);
	return (1);
}