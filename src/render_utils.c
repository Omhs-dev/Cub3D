/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:33:18 by ohamadou          #+#    #+#             */
/*   Updated: 2024/05/31 05:55:57 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"

float	nor_angle(float angle)	// normalize the angle
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

void ft_put_pixel(t_game *game, int x, int y, int c)
{
	if ((x >= 0 && x < S_W) && (y >= 0 && y < S_H))
		mlx_put_pixel(game->img, x, y, c);
}

uint32_t rgb_color(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a << 0);
}

int get_color(int c)
{
	unsigned int	b;

	b = 0;
	b |= (c & 0xFF) << 24;
	b |= (c & 0xFF00) << 8;
	b |= (c & 0xFF0000) >> 8;
	b |= (c & 0xFF000000) >> 24;
	return (b);
}

double get_x_offset(mlx_texture_t *tex, t_game *game)
{
	double x_o;
	
	if (game->ray->flag == 1)
		x_o = (int)fmodf((game->ray->hor_x * (tex->width / TILE_SIZE)), tex->width);
	else
		x_o = (int)fmodf((game->ray->hor_y * (tex->width / TILE_SIZE)), tex->width);
	return (x_o);
}
