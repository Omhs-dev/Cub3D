#include "../includes/structs.h"

//#####################################################################################//
//############################## THE WALL RENDERING CODE ##############################//
//#####################################################################################//

static void	my_mlx_pixel_put(t_game *mlx, int x, int y, int color)
{
	if (x < 0) // check the x position
		return ;
	else if (x >= S_W)
		return ;
	if (y < 0) // check the y position
		return ;
	else if (y >= S_H)
		return ;
	mlx_put_pixel(mlx->img, x, y, color); // put the pixel
}

float	nor_angle(float angle)	// normalize the angle
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

void	draw_floor_ceiling(t_game *mlx, int ray, int t_pix, int b_pix)	// draw the floor and the ceiling
{
	int		i;
	// int		c;

	i = b_pix;
	while (i < S_H)
		my_mlx_pixel_put(mlx, ray, i++, 0xB99470FF); // floor
	i = 0;
	while (i < t_pix)
		my_mlx_pixel_put(mlx, ray, i++, 0x89CFF3FF); // ceiling
}

mlx_texture_t	*get_color(t_game *mlx, double flag)	// get the color of the wall
{
	mlx_texture_t *return_tex;
	
	return_tex = NULL;
	mlx->ray->ray_ngl = nor_angle(mlx->ray->ray_ngl); // normalize the angle
	if (flag == 0)
	{
		if (mlx->ray->ray_ngl > M_PI / 2 && mlx->ray->ray_ngl < 3 * (M_PI / 2))
			return_tex = mlx->g_map->direction_img[WEST]; // west wall
		else
			return_tex = mlx->g_map->direction_img[EAST]; // west wall
	}
	else
	{
		if (mlx->ray->ray_ngl > 0 && mlx->ray->ray_ngl < M_PI)
			return_tex = mlx->g_map->direction_img[SOUTH];  // south wall
		else
			return_tex = mlx->g_map->direction_img[NORTH];  // north wall
	}
	return (return_tex);
}

void	draw_wall(t_game *mlx, int ray, int t_pix, int b_pix)	// draw the wall
{
	int color;

	color = get_color(mlx, mlx->ray->flag);
	while (t_pix < b_pix)
		my_mlx_pixel_put(mlx, ray, t_pix++, color);
}

void	render_wall(t_game *mlx, int ray)	// render the wall
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
	draw_floor_ceiling(mlx, ray, t_pix, b_pix); // draw the floor and the ceiling
}
