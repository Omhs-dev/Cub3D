/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:33:44 by ohamadou          #+#    #+#             */
/*   Updated: 2024/06/04 22:51:23 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"

mlx_texture_t	*wall_texture(t_game *mlx, int flag)
{
	mlx->ray->ray_ngl = nor_angle(mlx->ray->ray_ngl);
	if (flag == 0)
	{
		if (mlx->ray->ray_ngl > M_PI / 2 && mlx->ray->ray_ngl < 3 * (M_PI / 2))
			return (mlx->tex->east);
		else
			return (mlx->tex->south);
	}
	else
	{
		if (mlx->ray->ray_ngl > 0 && mlx->ray->ray_ngl < M_PI)
			return (mlx->tex->west);
		else
			return (mlx->tex->north);
	}
}

// mlx_texture_t* wall_texture(t_game *mlx, int is_vertical) {
//     if (is_vertical) {
//         if (unit_circle(mlx->ray->ray_ngl, 'y')) {
//             return mlx->tex->west;
//         } else {
//             return mlx->tex->east;
//         }
//     } else {
//         if (unit_circle(mlx->ray->ray_ngl, 'x')) {
//             return mlx->tex->north;
//         } else {
//             return mlx->tex->south;
//         }
//     }
// }

void draw_wall(t_game *mlx, int t_pix, int b_pix, double wall_h)
{
	double x_o;
	double y_o;
	double factr;
	mlx_texture_t *texture;
	uint32_t *arr;

	texture = wall_texture(mlx, mlx->ray->flag);
	if (!texture)
		return ;
	arr = (uint32_t *)texture->pixels;
	factr = (double)texture->height / wall_h;
	x_o = get_x_offset(texture, mlx);
	y_o = (t_pix - (S_H / 2) + (wall_h / 2)) * factr;
	if (y_o < 0)
		y_o = 0.1;
	while (t_pix < b_pix)
	{
		y_o = fmax(0.1, y_o);
		mlx->temp->id = (int)y_o * texture->width + (int)x_o;
		if (mlx->temp->id < (int)(texture->height * texture->width))
			ft_put_pixel(mlx, mlx->ray->ray_i, t_pix,
				get_color(arr[mlx->temp->id]));
		y_o += factr;
		t_pix++;
	}
}

void	draw_ceiling_floor(t_game *mlx, int ray, int t_pix, int b_pix)
{
	int		i;
	int		c;

	i = b_pix;
	// printf("ff: %s\n", mlx->g_map->ff[0]);
	c = rgb_color((mlx->g_map->floor[0]), (mlx->g_map->floor[1]), \
		(mlx->g_map->floor[2]), 255);
	while (i < S_H)
		ft_put_pixel(mlx, ray, i++, c);
	c = rgb_color((mlx->g_map->ceiling[0]), (mlx->g_map->ceiling[1]), \
		(mlx->g_map->ceiling[2]), 255);
	i = 0;
	while (i < t_pix)
		ft_put_pixel(mlx, ray, i++, c);
}

void	render_wall(t_game *mlx, int ray)
{
	double	wall_h;
	double	b_pix;
	double	t_pix;

	mlx->ray->distance *= cos(nor_angle(mlx->ray->ray_ngl - mlx->ply->p_angle));
	wall_h = (TILE_SIZE / mlx->ray->distance)
		* ((S_W / 2) / tan(mlx->ply->fov / 2));
	b_pix = (S_H / 2) + (wall_h / 2);
	t_pix = (S_H / 2) - (wall_h / 2);
	if (b_pix > S_H)
		b_pix = S_H;
	if (t_pix < 0)
		t_pix = 0;
	// mlx->ray->ray_i = ray;
	draw_wall(mlx, ray, t_pix, b_pix);
	draw_ceiling_floor(mlx, ray, t_pix, b_pix);
}
