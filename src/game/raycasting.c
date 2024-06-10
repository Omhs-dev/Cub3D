/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 07:29:14 by ohamadou          #+#    #+#             */
/*   Updated: 2024/06/10 08:50:38 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_inter(float angle, float *inter, float *step, int horiz)
{
	if (!horiz)
	{
		if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2))
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (angle > 0 && angle < M_PI)
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

int	wall_hit(float x, float y, t_game *game)
{
	int	x_m;
	int	y_m;

	if (x < 0 || y < 0)
		return (0);
	x_m = floor(x / TILE_SIZE);
	y_m = floor(y / TILE_SIZE);
	if ((y_m >= game->g_map->map_h || x_m >= game->g_map->map_w))
		return (0);
	if (game->g_map->map2d[y_m] && x_m
		<= (int)ft_strlen(game->g_map->map2d[y_m]))
	{
		if (game->g_map->map2d[y_m][x_m] == '1')
			return (0);
		else
			return (1);
	}
	return (1);
}

float	hor_inter(t_game *game, float angl)
{
	int		pix;
	float	h_x;
	float	h_y;
	float	x_step;
	float	y_step;

	y_step = TILE_SIZE;
	x_step = TILE_SIZE / tan(angl);
	h_y = floor(game->ply->player_y / TILE_SIZE) * TILE_SIZE;
	pix = check_inter(angl, &h_y, &y_step, 1);
	h_x = game->ply->player_x + (h_y - game->ply->player_y) / tan(angl);
	if ((check_u_circle(angl, 'y') && x_step > 0) || \
		(!check_u_circle(angl, 'y') && x_step < 0))
		x_step *= -1;
	while (wall_hit(h_x, h_y - pix, game))
	{
		h_x += x_step;
		h_y += y_step;
	}
	game->ray->hor_x = h_x;
	game->ray->hor_y = h_y;
	return (sqrt(pow(h_x - game->ply->player_x, 2)
			+ pow(h_y - game->ply->player_y, 2)) + 0.0001);
}

float	vert_inter(t_game *game, float angl)
{
	int		pix;
	float	v_x;
	float	v_y;
	float	x_step;
	float	y_step;

	x_step = TILE_SIZE;
	y_step = TILE_SIZE * tan(angl);
	v_x = floor(game->ply->player_x / TILE_SIZE) * TILE_SIZE;
	pix = check_inter(angl, &v_x, &x_step, 0);
	v_y = game->ply->player_y + (v_x - game->ply->player_x) * tan(angl);
	if ((check_u_circle(angl, 'x') && y_step < 0) || \
	(!check_u_circle(angl, 'x') && y_step > 0))
		y_step *= -1;
	while (wall_hit(v_x - pix, v_y, game))
	{
		v_x += x_step;
		v_y += y_step;
	}
	game->ray->hor_x = v_x;
	game->ray->hor_y = v_y;
	return (sqrt(pow(v_x - game->ply->player_x, 2)
			+ pow(v_y - game->ply->player_y, 2)));
}

void	ray_casting(t_game *game)
{
	int		ray;
	double	h_inter;
	double	v_inter;

	ray = 0;
	game->ray->ray_ngl = game->ply->p_angle - (game->ply->fov / 2);
	while (ray <= S_W)
	{
		game->ray->flag = 0;
		h_inter = hor_inter(game, nor_angle(game->ray->ray_ngl));
		v_inter = vert_inter(game, nor_angle(game->ray->ray_ngl));
		if (v_inter <= h_inter)
			game->ray->distance = v_inter;
		else
		{
			game->ray->distance = h_inter;
			game->ray->flag = 1;
		}
		render_wall(game, ray);
		ray++;
		game->ray->ray_ngl += (game->ply->fov / S_W);
	}
}
