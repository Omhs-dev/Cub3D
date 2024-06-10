/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_descr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 05:35:49 by voszadcs          #+#    #+#             */
/*   Updated: 2024/06/10 05:48:13 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/cub3d.h"

static int	check_rgb(char **input)
{
	char	**str;
	char	**rgb;
	char	**temp;

	while (*input)
	{
		if (*input[0] == 'C' || *input[0] == 'F')
		{
			str = ft_split(*input, ' ');
			input++;
			if (!str[1] || str[2])
				return (free_double_char(str), 0);
			rgb = ft_split(str[1], ',');
			temp = rgb;
			free_double_char(str);
			if (rgb[3])
				return (free_double_char(rgb), 0);
			while (*temp)
			{
				if (!is_rgb_value(*temp))
					return (free_double_char(rgb), 0);
				temp++;
			}
		}
		else
			input++;
	}
	return (1);
}

static int	check_path(char **input)
{
	int		fd;
	char	**path;
	int		i;

	i = 0;
	while (input[i])
	{
		if ((input[i][0] == 'N' || input[i][0] == 'S' ||
			input[i][0] == 'W' || input[i][0] == 'E'))
		{
			path = ft_split(input[i++], ' ');
			fd = open(path[1], O_RDONLY);
			if (fd < 0 || path[2])
				return (free_double_char(path), 0);
			close(fd);
			free_double_char(path);
		}
		else
			i++;
	}
	return (1);
}

static int	compare(char *str)
{
	if (ft_strncmp(str, "NO ", 3) == 0)
		return (1);
	if (ft_strncmp(str, "SO ", 3) == 0)
		return (2);
	if (ft_strncmp(str, "EA ", 3) == 0)
		return (4);
	if (ft_strncmp(str, "WE ", 3) == 0)
		return (8);
	if (ft_strncmp(str, "F ", 2) == 0)
		return (16);
	if (ft_strncmp(str, "C ", 2) == 0)
		return (32);
	return (0);
}

static int	check_types(char **input)
{
	char	**temp;
	int		uniq_count;

	uniq_count = 0;
	temp = input;
	while (*temp)
	{
		uniq_count += compare(*temp);
		temp++;
	}
	if (uniq_count == 63)
		return (1);
	return (0);
}

int	validate_descr(char **input)
{
	if (!check_types(input) || !check_path(input) || !check_rgb(input))
		return (0);
	return (1);
}
