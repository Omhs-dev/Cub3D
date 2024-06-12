/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 05:33:10 by voszadcs          #+#    #+#             */
/*   Updated: 2024/06/12 03:00:53 by voszadcs         ###   ########.fr       */
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

static int	closed_diff_len_walls(char *str1, char *str2)
{
	int	len1;
	int	len2;

	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	if (len1 > len2)
	{
		while (str1[len2] != '\0')
		{
			if (str1[len2] == '0' || str1[len2 - 1] == '0')
				return (0);
			len2++;
		}
	}
	else if (len2 > len1)
	{
		while (str2[len1] != '\0')
		{
			if (str2[len1] == '0' || str2[len1 - 1] == '0')
				return (0);
			len1++;
		}
	}
	return (1);
}

static int	check_walls(char **map)
{
	char	*line;

	line = *map;
	if (!check_first_line(line))
		return (0);
	while (*map)
	{
		line = *map;
		if (*(map + 1) != NULL && (line[0] != '1'
				|| line[ft_strlen(line) - 1] != '1'
				|| !closed_diff_len_walls(*map, *(map + 1))))
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
