/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 05:35:28 by voszadcs          #+#    #+#             */
/*   Updated: 2024/06/12 03:29:21 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_first_line(char *line)
{
	while (*line)
	{
		if (*line != '1')
			return (0);
		line++;
	}
	return (1);
}

int	is_rgb_value(char **str)
{
	int		i;
	char	*temp;

	i = 0;
	while (*str)
	{
		temp = *str;
		while (*temp)
		{
			i++;
			if (!ft_isdigit(*temp))
				return (0);
			temp++;
		}
		if (i == 0 || i > 3)
			return (printf("i = 0 or i > 3: %d\n", i), 0);
		i = ft_atoi(temp - i);
		if (i < 0 || i > 255)
			return (printf("value out of range %d\n", i), 0);
		i = 0;
		str++;
	}
	return (1);
}
