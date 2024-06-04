/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:33:44 by ohamadou          #+#    #+#             */
/*   Updated: 2024/06/04 06:13:19 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"

// void draw_ceiling_floor(t_game *mlx)
// {
// 	int ray;
// 	int i;
// 	int j;

// 	ray = 0;
// 	while (ray < S_W)
// 	{
// 		i = S_H / 2;
// 		while (i < S_H)
// 			ft_put_pixel(mlx, ray, i++, 0xB99470FF);
// 		ray++;
// 	}
// 	ray = 0;
// 	while (ray < S_W)
// 	{
// 		j = 0;
// 		while (j < S_H / 2)
// 			ft_put_pixel(mlx, ray, j++, 0x89CFF3FF);
// 		ray++;
// 	}
// }

mlx_texture_t	*wall_texture(t_game *mlx, double flag)
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

void	draw_wall(t_game *mlx, int t_pix, int b_pix, double wall_h)	// draw the wall
{
	double x_o;
	double y_o;
	double factr;
	mlx_texture_t *texture;
	uint32_t *arr;

	texture = wall_texture(mlx, mlx->ray->flag);
	arr = (uint32_t *)texture->pixels;
	factr = (double)texture->height / wall_h;
	x_o = get_x_offset(texture, mlx);
	y_o = (t_pix - (S_H / 2) + (wall_h / 2)) * factr;
	if (y_o < 0)
		y_o = 0;
	while (t_pix < b_pix)
	{
		ft_put_pixel(mlx, mlx->ray->ray_i, t_pix, get_color \
		(arr[(int)y_o * texture->width + (int)x_o]));
		y_o += factr;
		t_pix++;
	}
}

void	draw_ceiling_floor(t_game *mlx, int ray, int t_pix, int b_pix)	// draw the floor and the ceiling
{
	int		i;
	// int		c;

	i = b_pix;
	while (i < S_H)
		ft_put_pixel(mlx, ray, i++, 0xB99470FF); // floor
	i = 0;
	while (i < t_pix)
		ft_put_pixel(mlx, ray, i++, 0x89CFF3FF); // ceiling
}

void	render_wall(t_game *mlx, int ray)
{
	double	wall_h;
	double	b_pix;
	double	t_pix;

	mlx->ray->distance *= cos(nor_angle(mlx->ray->ray_ngl - mlx->ply->p_angle)); // fix the fisheye
	wall_h = (TILE_SIZE / mlx->ray->distance) * ((S_W / 2) / tan(mlx->ply->fov / 2)); // get the wall height
	b_pix = (S_H / 2) + (wall_h / 2); // get the bottom pixel
	t_pix = (S_H / 2) - (wall_h / 2); // get the top pixel
	if (b_pix > S_H) // check the bottom pixel
		b_pix = S_H;
	if (t_pix < 0) // check the top pixel
		t_pix = 0;
	draw_wall(mlx, ray, t_pix, b_pix); // draw the wall
	draw_ceiling_floor(mlx, ray, t_pix, b_pix); // draw the floor and the ceiling
}
