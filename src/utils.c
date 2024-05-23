#include "../includes/structs.h"

void my_mlx_pixel_put(t_game *game, int x, int y, int color) // put the pixel
{
 if (x < 0) // check the x position
  return ;
 else if (x >= S_W)
  return ;
 if (y < 0) // check the y position
  return ;
 else if (y >= S_H)
  return ;
 mlx_put_pixel(game->img, x, y, color); // put the pixel
}

float get_h_inter(t_game *game, float angl) // get the horizontal intersection
{
 float h_x;
 float h_y;
 float x_step;
 float y_step;
 int  pixel;

 y_step = TILE_SIZE;
 x_step = TILE_SIZE / tan(angl);
 h_y = floor(game->g_player->player_y / TILE_SIZE) * TILE_SIZE;
 pixel = inter_check(angl, &h_y, &y_step, 1);
 h_x = game->g_player->player_x + (h_y - game->g_player->player_y) / tan(angl);
 if ((unit_circle(angl, 'y') && x_step > 0) || (!unit_circle(angl, 'y') && x_step < 0)) // check x_step value
  x_step *= -1;
 while (wall_hit(h_x, h_y - pixel, game)) // check the wall hit whit the pixel value
 {
  h_x += x_step;
  h_y += y_step;
 }
 return (sqrt(pow(h_x - game->g_player->player_x, 2) + pow(h_y - game->g_player->player_y, 2))); // get the distance
}

float get_v_inter(t_game *game, float angl) // get the vertical intersection
{
 float v_x;
 float v_y;
 float x_step;
 float y_step;
 int  pixel;

 x_step = TILE_SIZE; 
 y_step = TILE_SIZE * tan(angl);
 v_x = floor(game->g_player->player_x / TILE_SIZE) * TILE_SIZE;
 pixel = inter_check(angl, &v_x, &x_step, 0); // check the intersection and get the pixel value
 v_y = game->g_player->player_y + (v_x - game->g_player->player_x) * tan(angl);
 if ((unit_circle(angl, 'x') && y_step < 0) || (!unit_circle(angl, 'x') && y_step > 0)) // check y_step value
  y_step *= -1;
 while (wall_hit(v_x - pixel, v_y, game)) // check the wall hit whit the pixel value
 {
  v_x += x_step;
  v_y += y_step;
 }
 return (sqrt(pow(v_x - game->g_player->player_x, 2) + pow(v_y - game->g_player->player_y, 2))); // get the distance
}

float nor_angle(float angle) {
    angle = fmod(angle, 2 * M_PI);
    if (angle < 0)
        angle += 2 * M_PI;
    return angle;
}

int wall_hit(float x, float y, t_game *game) {
    int grid_x = x / TILE_SIZE;
    int grid_y = y / TILE_SIZE;
    if (grid_x >= 0 && grid_x < game->g_map->map_w && grid_y >= 0 && grid_y < game->g_map->map_h)
        return game->g_map->map[grid_y][grid_x] == '1';
    return 1;
}

void ft_exit(t_game *game) {
    mlx_terminate(game->mlx);
    free(game->g_player);
    free(game->g_ray);
    for (int i = 0; i < game->g_map->map_h; i++)
        free(game->g_map->map[i]);
    free(game->g_map->map);
    free(game->g_map);
    exit(EXIT_SUCCESS);
}
