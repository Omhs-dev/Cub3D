/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 07:29:14 by ohamadou          #+#    #+#             */
/*   Updated: 2024/06/10 10:15:59 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	process_ray(t_game *game, int ray)
{
	double	h_inter;
	double	v_inter;

	h_inter = hor_inter(game, nor_angle(game->ray->ray_ngl));
	v_inter = vert_inter(game, nor_angle(game->ray->ray_ngl));
	game->ray->flag = 0;
	if (v_inter <= h_inter)
		game->ray->distance = v_inter;
	else
	{
		game->ray->distance = h_inter;
		game->ray->flag = 1;
	}
	render_wall(game, ray);
}

void	ray_casting(t_game *game)
{
	int	ray;

	ray = 0;
	game->ray->ray_ngl = game->ply->p_angle - (game->ply->fov / 2);
	while (ray <= S_W)
	{
		process_ray(game, ray);
		ray++;
		game->ray->ray_ngl += (game->ply->fov / S_W);
	}
}
