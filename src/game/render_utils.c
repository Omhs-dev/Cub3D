/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:33:18 by ohamadou          #+#    #+#             */
/*   Updated: 2024/06/10 08:18:26 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

float	nor_angle(float angle)
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

int	check_u_circle(float angle, char c)
{
	if (c == 'x')
	{
		if (angle > 0 && angle < M_PI)
			return (1);
	}
	else if (c == 'y')
	{
		if (angle > (M_PI / 2) && angle < (3 * M_PI) / 2)
			return (1);
	}
	return (0);
}

void	ft_put_pixel(t_game *game, int x, int y, int c)
{
	if ((x >= 0 && x < S_W) && (y >= 0 && y < S_H))
		mlx_put_pixel(game->img, x, y, c);
}

uint32_t	rgb_color(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a << 0);
}

unsigned int	get_color(int c)
{
	return (((c & 0x000000FF) << 24) | ((c & 0x0000FF00) << 8)
		| ((c & 0x00FF0000) >> 8) | ((c & 0xFF000000) >> 24));
}

double	get_x_offset(mlx_texture_t *texture, t_game *data)
{
	double	x_o;
	double	wall_hit_x;
	double	wall_hit_y;
	double	dist_to_wall;

	dist_to_wall = data->ray->distance;
	if (data->ray->flag == 1)
	{
		wall_hit_x = data->ply->player_x + (dist_to_wall
				* cos(data->ray->ray_ngl));
		x_o = fmod(wall_hit_x, TILE_SIZE) / TILE_SIZE * texture->width;
	}
	else
	{
		wall_hit_y = data->ply->player_y + (dist_to_wall
				* sin(data->ray->ray_ngl));
		x_o = fmod(wall_hit_y, TILE_SIZE) / TILE_SIZE * texture->width;
	}
	return (x_o);
}
