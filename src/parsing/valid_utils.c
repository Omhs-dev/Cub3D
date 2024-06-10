/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 05:35:28 by voszadcs          #+#    #+#             */
/*   Updated: 2024/06/10 05:35:30 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/cub3d.h"

int	is_rgb_value(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	if (i == 0 || i > 3)
		return (0);
	i = ft_atoi(str - i);
	if (i < 0 || i > 255)
		return (0);
	return (1);
}
