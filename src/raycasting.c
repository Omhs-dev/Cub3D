#include "../includes/structs.h"

int unit_circle(float angle, char c) // check the unit circle
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

int inter_check(float angle, float *inter, float *step, int is_horizon) // check the intersection
{
 if (is_horizon)
 {
  if (angle > 0 && angle < M_PI)
  {
   *inter += TILE_SIZE;
   return (-1);
  }
  *step *= -1;
 }
 else
 {
  if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2)) 
  {
   *inter += TILE_SIZE;
   return (-1);
  }
  *step *= -1;
 }
 return (1);
}


void cast_rays(t_game *game) // cast the rays
{
 double h_inter;
 double v_inter;
 int  ray;

 ray = 0;
 game->g_ray->ray_ngl = game->g_player->p_angle - (game->g_player->fov / 2); // the start angle
 while (ray < S_W) // loop for the rays
 {
  game->g_ray->flag = 0; // flag for the wall
  h_inter = get_h_inter(game, nor_angle(game->g_ray->ray_ngl)); // get the horizontal intersection
  v_inter = get_v_inter(game, nor_angle(game->g_ray->ray_ngl)); // get the vertical intersection
  if (v_inter <= h_inter) // check the distance
   game->g_ray->distance = v_inter; // get the distance
  else
  {
   game->g_ray->distance = h_inter; // get the distance
   game->g_ray->flag = 1; // flag for the wall
  }
  render_wall(game, ray); // render the wall
  ray++; // next ray
  game->g_ray->ray_ngl += (game->g_player->fov / S_W); // next angle
 }
}

void render_wall(t_game *game, int ray) {
    int wall_height = (TILE_SIZE / game->g_ray->distance) * 600;
    int top_pixel = (S_H / 2) - (wall_height / 2);
    int bottom_pixel = (S_H / 2) + (wall_height / 2);
    draw_wall(game, ray, top_pixel, bottom_pixel); // Draw the wall
    draw_floor_ceiling(game, ray, top_pixel, bottom_pixel); // Draw the floor and ceiling
}

void draw_wall(t_game *game, int ray, int top_pixel, int bottom_pixel) {
	
    while (top_pixel < bottom_pixel)
        my_mlx_pixel_put(game, ray, top_pixel++, 0xFFFFFF); // White color for wall
}

void draw_floor_ceiling(t_game *game, int ray, int top_pixel, int bottom_pixel) {
    for (int y = 0; y < top_pixel; y++)
        my_mlx_pixel_put(game, ray, y, 0x87CEEB); // Light blue color for ceiling
    for (int y = bottom_pixel; y < S_H; y++)
        my_mlx_pixel_put(game, ray, y, 0x008000); // Green color for floor
}
