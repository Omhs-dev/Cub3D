/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:33:44 by ohamadou          #+#    #+#             */
/*   Updated: 2024/06/10 08:10:37 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

mlx_texture_t	*wall_texture(t_game *game, int flag)
{
	game->ray->ray_ngl = nor_angle(game->ray->ray_ngl);
	if (flag == 0)
	{
		if (game->ray->ray_ngl > M_PI / 2
			&& game->ray->ray_ngl < 3 * (M_PI / 2))
			return (game->tex->east);
		else
			return (game->tex->west);
	}
	else
	{
		if (game->ray->ray_ngl > 0 && game->ray->ray_ngl < M_PI)
			return (game->tex->south);
		else
			return (game->tex->north);
	}
}

void	draw_ceiling_floor(t_game *game, int ray, int t_pix, int b_pix)
{
	int		i;
	int		c;

	i = b_pix;
	c = rgb_color((game->g_map->floor[RED]), (game->g_map->floor[GREEN]), \
		(game->g_map->floor[BLUE]), 255);
	while (i < S_H)
		ft_put_pixel(game, ray, i++, c);
	c = rgb_color((game->g_map->ceiling[0]), (game->g_map->ceiling[GREEN]), \
		(game->g_map->ceiling[BLUE]), 255);
	i = 0;
	while (i < t_pix)
		ft_put_pixel(game, ray, i++, c);
}

void	draw_wall(t_game *game, int t_pix, int b_pix, double wall_h)
{
	double			x_o;
	double			y_o;
	double			factr;
	uint32_t		*arr;
	mlx_texture_t	*texture;

	texture = wall_texture(game, game->ray->flag);
	arr = (uint32_t *)texture->pixels;
	factr = (double)texture->height / wall_h;
	x_o = get_x_offset(texture, game);
	y_o = (t_pix - (S_H / 2) + (wall_h / 2)) * factr;
	if (y_o < 0)
		y_o = 0.0;
	while (t_pix < b_pix)
	{
		ft_put_pixel(game, game->ray->ray_i, t_pix,
			get_color(arr[(int)y_o * texture->width + (int)x_o]));
		y_o += factr;
		t_pix++;
	}
}

void	render_wall(t_game *game, int ray)
{
	double	wall_h;
	double	b_pix;
	double	t_pix;

	game->ray->distance *= cos(nor_angle
			(game->ray->ray_ngl - game->ply->p_angle));
	wall_h = (TILE_SIZE / game->ray->distance)
		* ((S_W / 2) / tan(game->ply->fov / 2));
	b_pix = (S_H / 2) + (wall_h / 2);
	t_pix = (S_H / 2) - (wall_h / 2);
	if (b_pix > S_H)
		b_pix = S_H;
	if (t_pix < 0)
		t_pix = 0;
	game->ray->ray_i = ray;
	draw_wall(game, t_pix, b_pix, wall_h);
	draw_ceiling_floor(game, ray, t_pix, b_pix);
}
