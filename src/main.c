// // #include "../includes/structs.h"
#include "../MLX42/include/MLX42/MLX42.h"
// #include <stdio.h>
// #include <unistd.h>
// #include <stdlib.h>
// #include <memory.h>
// #define WIDTH 512
// #define HEIGHT 512
// #define TILE_SIZE 30
// // int main(int argc, char **argv) {
// //     if (argc != 2) {
// //         fprintf(stderr, "Usage: %s <map_file>\n", argv[0]);
// //         return EXIT_FAILURE;
// //     }
// //     t_map *map = init_argument(argv[1]);
    
// //     start_the_game(map);
// //     return EXIT_SUCCESS;
// // }
// // -----------------------------------------------------------------------------
// // Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// // See README in the root project for more information.
// // -----------------------------------------------------------------------------

// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// // #include <MLX42/MLX42.h>
// // #include <stdlib.h>
// #include <string.h>

// // Bytes Per Pixel. Since each pixel is represented as an integer, it will be four bytes for four channels.
// #define BPP sizeof(int32_t)
// #define WIDTH 512
// #define HEIGHT 512

// typedef struct s_data 
// {
// 	int x;
// 	int y;
// 	int i;
// 	int j;
// 	int map_w;
// 	int map_h;
// 	char **map;
// 	mlx_t *mlx;
// 	mlx_image_t *p_image;
// 	mlx_image_t *wall;
// 	mlx_texture_t *wall_t;
// 	mlx_texture_t *p_renderimg;
// }   t_data;

// void	player_position(t_data *game)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (i < game->map_h)
// 	{
// 		j = 0;
// 		while (j < game->map_w)
// 		{
// 			if (game->map[i][j] == 'P')
// 			{
// 				// mlx_image_to_window(game->mlx, game->wall, j, i);
// 				game->x = j;
// 				game->y = i;
// 				return ;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void render_player(t_data *data) {
//     // Clear previous player image
//     mlx_delete_image(data->mlx, data->p_image);
//     // Load and place player image at the new position
//     data->p_image = mlx_texture_to_image(data->mlx, data->p_renderimg);
//     mlx_image_to_window(data->mlx, data->p_image, data->x * 30, data->y * 30);
// }

// void ft_hook(mlx_key_data_t key_game, void *param) {
//     t_data *game = (t_data *)param;
//     int new_x = game->x;
//     int new_y = game->y;

//     if (key_game.key == MLX_KEY_ESCAPE && (key_game.action == MLX_PRESS || key_game.action == MLX_REPEAT)) {
//         mlx_close_window(game->mlx);
//     }
//     else if (key_game.key == MLX_KEY_LEFT && (key_game.action == MLX_PRESS || key_game.action == MLX_REPEAT)) {
//         new_x = game->x - 1;
//     }
//     else if (key_game.key == MLX_KEY_RIGHT && (key_game.action == MLX_PRESS || key_game.action == MLX_REPEAT)) {
//         new_x = game->x + 1;
//     }
//     else if (key_game.key == MLX_KEY_UP && (key_game.action == MLX_PRESS || key_game.action == MLX_REPEAT)) {
//         new_y = game->y - 1;
//     }
//     else if (key_game.key == MLX_KEY_DOWN && (key_game.action == MLX_PRESS || key_game.action == MLX_REPEAT)) {
//         new_y = game->y + 1;
//     }

//     // Check boundaries and if the new position is not a wall
//     if (new_x >= 0 && new_x < game->map_w && new_y >= 0 && new_y < game->map_h && game->map[new_y][new_x] != '1') {
//         // Update player position
//         game->x = new_x;
//         game->y = new_y;
//         // Re-render player at new position
//         render_player(game);
//     }
// }


// t_data *init_argument() {
//     t_data *data = calloc(1, sizeof(t_data));
//     if (!data) return NULL;

//     data->map = calloc(10, sizeof(char *));
//     if (!data->map) {
//         free(data);
//         return NULL;
//     }

//     data->map[0] = strdup("1111111111111111111111111");
//     data->map[1] = strdup("1000000000000000000100001");
//     data->map[2] = strdup("1001000000000000000000001");
//     data->map[3] = strdup("1001000000000000001000001");
//     data->map[4] = strdup("1001000000000P00001000001");
//     data->map[5] = strdup("1001000000100000001000001");
//     data->map[6] = strdup("1001000000000000001000001");
//     data->map[7] = strdup("1001000000001000001000001");
//     data->map[8] = strdup("1111111111111111111111111");
//     data->map[9] = NULL;

//     // Find player position
//     for (int i = 0; i < 9; i++) {
//         char *p = strchr(data->map[i], 'P');
//         if (p) {
//             data->y = i;
//             data->x = p - data->map[i];
//             break;
//         }
//     }

//     data->map_w = 25; // map width
//     data->map_h = 9;  // map height
//     data->i = 0;
//     data->j = 0;

//     return data;
// }

// void output_map(t_data *data) {
//     int i, j;
//     mlx_image_t *wall_img = mlx_new_image(data->mlx, 30, 30);
//     memset(wall_img->pixels, 255, wall_img->width * wall_img->height * BPP);
//     // memset(wall_img->pixels, 255, wall_img->width * wall_img->height * BPP);

//     for (i = 0; i < data->map_h; i++) {
//         for (j = 0; j < data->map_w; j++) {
//             if (data->map[i][j] == '1') {
//                 mlx_image_to_window(data->mlx, wall_img, j * 30, i * 30);
//             }
//         }
//     }

//     data->p_renderimg = mlx_load_png("../assets/wall.png");
//     data->p_image = mlx_texture_to_image(data->mlx, data->p_renderimg); 
//     mlx_image_to_window(data->mlx, data->p_image, data->x * 30, data->y * 30);
//     render_player(data);
// }


// void start_the_game(t_data *data)
// {
// 	// data = calloc(1, sizeof(t_data));
// 	data->mlx = mlx_init(data->map_w * 30, data->map_h * 30, "So Long", true);
// 	output_map(data);
// 	// mlx_loop_hook(data->mlx, &ft_randomize, data);
// 	mlx_key_hook(data->mlx, &ft_hook, data);
// 	mlx_loop(data->mlx);
// 	mlx_delete_image(data->mlx, data->p_image);
// 	mlx_delete_texture(data->p_renderimg);
// 	mlx_terminate(data->mlx);
//     for (int i = 0; i < 9; i++) free(data->map[i]);
//     free(data->map);
//     free(data);
// }

// int main()
// {
// 	t_data *data = init_argument();
// 	// printf("%s\n", data->map[0]);
// 	start_the_game(data);
// 	return (0);
// }


#include <math.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// #include "mlx.h"

#define TILE_SIZE 64
#define FOV_ANGLE (60 * (M_PI / 180))
#define S_W 800
#define S_H 600
#define MLX_KEY_ESCAPE 65307
#define MLX_KEY_LEFT 65361
#define MLX_KEY_RIGHT 65363
#define MLX_KEY_UP 65362
#define MLX_KEY_DOWN 65364

typedef struct {
    float wall_hit_x;
    float wall_hit_y;
    float distance;
    int is_vertical_hit;
    float ray_ngl;
    int flag;
    int index;
    int horiz_x;
    int horiz_y;
    int vert_x;
    int vert_y;
} t_ray;

typedef struct {
    int x;
    int y;
    int map_w;
    int map_h;
    char **map;
    float ply_angle;
    float fov_rd;
    mlx_t *mlx;
    mlx_image_t *p_image;
    mlx_image_t *wall;
    mlx_texture_t *wall_t;
    mlx_texture_t *p_renderimg;
    t_ray rays[S_W];
} t_data;


typedef struct {
    float x;
    float y;
} t_point;

typedef struct {
    int x;
    int y;
} t_coord;

void my_mlx_pixel_put(t_data *data, int x, int y, int color) {
    if (x >= 0 && x < data->p_image->width && y >= 0 && y < data->p_image->height) {
        char *dst = data->p_image->pixels + (y * data->p_image->line_length + x * (data->p_image->bits_per_pixel / 8));
        *(unsigned int *)dst = color;
    }
}


int reverse_bytes(int color) {
    int r = (color & 0xFF0000) >> 16;
    int g = (color & 0x00FF00) >> 8;
    int b = (color & 0x0000FF);
    return (r | (g << 8) | (b << 16));
}

double nor_angle(double angle) {
    angle = fmod(angle, 2 * M_PI);
    if (angle < 0)
        angle += 2 * M_PI;
    return angle;
}

void draw_floor_ceiling(t_data *data, int ray, int t_pix, int b_pix) {
    int i;
    int c;

    // Draw floor
    i = b_pix;
    c = get_rgba(ft_atoi(data->ff[0]), ft_atoi(data->ff[1]), ft_atoi(data->ff[2]), 255);
    while (i < data->p_image->height) {
        my_mlx_pixel_put(data, ray, i++, c);
    }

    // Draw ceiling
    c = get_rgba(ft_atoi(data->cc[0]), ft_atoi(data->cc[1]), ft_atoi(data->cc[2]), 255);
    i = 0;
    while (i < t_pix) {
        my_mlx_pixel_put(data, ray, i++, c);
    }
}


mlx_texture_t *get_texture(t_data *data, int flag) {
    data->rays[data->current_ray].ray_ngl = nor_angle(data->rays[data->current_ray].ray_ngl);
    if (flag == 0) {
        if (data->rays[data->current_ray].ray_ngl > M_PI / 2 && data->rays[data->current_ray].ray_ngl < 3 * (M_PI / 2))
            return data->wall_t->ea;
        else
            return data->wall_t->we;
    } else {
        if (data->rays[data->current_ray].ray_ngl > 0 && data->rays[data->current_ray].ray_ngl < M_PI)
            return data->wall_t->so;
        else
            return data->wall_t->no;
    }
}

double get_x_o(mlx_texture_t *texture, t_data *data) {
    double x_o;
    if (data->rays[data->current_ray].flag == 1)
        x_o = fmod((data->rays[data->current_ray].horiz_x * (texture->width / TILE_SIZE)), texture->width);
    else
        x_o = fmod((data->rays[data->current_ray].vert_y * (texture->width / TILE_SIZE)), texture->width);
    return x_o;
}


double get_x_o(mlx_texture_t *texture, t_data *data) {
    double x_o;
    if (data->rays[data->rays->index].flag == 1)
        x_o = (int)fmodf((data->rays[data->rays->index].horiz_x * (texture->width / TILE_SIZE)), texture->width);
    else
        x_o = (int)fmodf((data->rays[data->rays->index].vert_y * (texture->width / TILE_SIZE)), texture->width);
    return x_o;
}

void draw_wall(t_data *data, int t_pix, int b_pix, double wall_h) {
    double x_o;
    double y_o;
    mlx_texture_t *texture;
    uint32_t *arr;
    double factor;

    texture = get_texture(data, data->rays[data->current_ray].flag);
    arr = (uint32_t *)texture->pixels;
    factor = (double)texture->height / wall_h;
    x_o = get_x_o(texture, data);
    y_o = (t_pix - (data->p_image->height / 2) + (wall_h / 2)) * factor;
    if (y_o < 0)
        y_o = 0;

    while (t_pix < b_pix) {
        if (t_pix >= 0 && t_pix < data->p_image->height) {
            my_mlx_pixel_put(data, data->current_ray, t_pix, reverse_bytes(arr[(int)y_o * texture->width + (int)x_o]));
        }
        y_o += factor;
        t_pix++;
    }
}


void render_player(t_data *data) {
    // Clear previous player image
    mlx_delete_image(data->mlx, data->p_image);
    // Load and place player image at the new position
    data->p_image = mlx_texture_to_image(data->mlx, data->p_renderimg);
    mlx_image_to_window(data->mlx, data->p_image, data->x * 30, data->y * 30);
}

void render_wall(t_data *data, int ray) {
    double wall_h;
    double b_pix;
    double t_pix;

    data->rays[ray].distance *= cos(nor_angle(data->rays[ray].ray_ngl - data->ply_angle));
    wall_h = (TILE_SIZE / data->rays[ray].distance) * ((data->p_image->width / 2) / tan(data->fov_rd / 2));
    b_pix = (data->p_image->height / 2) + (wall_h / 2);
    t_pix = (data->p_image->height / 2) - (wall_h / 2);
    if (b_pix > data->p_image->height)
        b_pix = data->p_image->height;
    if (t_pix < 0)
        t_pix = 0;
    data->current_ray = ray;
    draw_wall(data, t_pix, b_pix, wall_h);
    draw_floor_ceiling(data, ray, t_pix, b_pix);
}


//ray cast function
void cast_ray(float ray_angle, t_ray *ray, t_data *data) {
    ray_angle = nor_angle(ray_angle);

    bool is_ray_facing_down = ray_angle > 0 && ray_angle < M_PI;
    bool is_ray_facing_up = !is_ray_facing_down;
    bool is_ray_facing_right = ray_angle < (0.5 * M_PI) || ray_angle > (1.5 * M_PI);
    bool is_ray_facing_left = !is_ray_facing_right;

    float x_intercept, y_intercept;
    float x_step, y_step;

    // Horizontal ray-grid intersection
    bool found_horz_wall_hit = false;
    t_point horz_wall_hit = {0, 0};
    t_coord horz_wall_content = {0, 0};

    y_intercept = floor(data->y / TILE_SIZE) * TILE_SIZE;
    y_intercept += is_ray_facing_down ? TILE_SIZE : 0;

    x_intercept = data->x + (y_intercept - data->y) / tan(ray_angle);

    y_step = TILE_SIZE;
    y_step *= is_ray_facing_up ? -1 : 1;

    x_step = TILE_SIZE / tan(ray_angle);
    x_step *= (is_ray_facing_left && x_step > 0) ? -1 : 1;
    x_step *= (is_ray_facing_right && x_step < 0) ? -1 : 1;

    float next_horz_touch_x = x_intercept;
    float next_horz_touch_y = y_intercept;

    while (next_horz_touch_x >= 0 && next_horz_touch_x < data->map_w * TILE_SIZE &&
           next_horz_touch_y >= 0 && next_horz_touch_y < data->map_h * TILE_SIZE) {
        int wall_x = next_horz_touch_x / TILE_SIZE;
        int wall_y = (next_horz_touch_y / TILE_SIZE) - (is_ray_facing_up ? 1 : 0);

        if (wall_x >= 0 && wall_x < data->map_w && wall_y >= 0 && wall_y < data->map_h && 
            data->map[wall_y][wall_x] == '1') {
            found_horz_wall_hit = true;
            horz_wall_hit.x = next_horz_touch_x;
            horz_wall_hit.y = next_horz_touch_y;
            horz_wall_content.x = wall_x;
            horz_wall_content.y = wall_y;
            break;
        } else {
            next_horz_touch_x += x_step;
            next_horz_touch_y += y_step;
        }
    }

    // Vertical ray-grid intersection
    bool found_vert_wall_hit = false;
    t_point vert_wall_hit = {0, 0};
    t_coord vert_wall_content = {0, 0};

    x_intercept = floor(data->x / TILE_SIZE) * TILE_SIZE;
    x_intercept += is_ray_facing_right ? TILE_SIZE : 0;

    y_intercept = data->y + (x_intercept - data->x) * tan(ray_angle);

    x_step = TILE_SIZE;
    x_step *= is_ray_facing_left ? -1 : 1;

    y_step = TILE_SIZE * tan(ray_angle);
    y_step *= (is_ray_facing_up && y_step > 0) ? -1 : 1;
    y_step *= (is_ray_facing_down && y_step < 0) ? -1 : 1;

    float next_vert_touch_x = x_intercept;
    float next_vert_touch_y = y_intercept;

    while (next_vert_touch_x >= 0 && next_vert_touch_x < data->map_w * TILE_SIZE &&
           next_vert_touch_y >= 0 && next_vert_touch_y < data->map_h * TILE_SIZE) {
        int wall_x = (next_vert_touch_x / TILE_SIZE) - (is_ray_facing_left ? 1 : 0);
        int wall_y = next_vert_touch_y / TILE_SIZE;

        if (wall_x >= 0 && wall_x < data->map_w && wall_y >= 0 && wall_y < data->map_h && 
            data->map[wall_y][wall_x] == '1') {
            found_vert_wall_hit = true;
            vert_wall_hit.x = next_vert_touch_x;
            vert_wall_hit.y = next_vert_touch_y;
            vert_wall_content.x = wall_x;
            vert_wall_content.y = wall_y;
            break;
        } else {
            next_vert_touch_x += x_step;
            next_vert_touch_y += y_step;
        }
    }

    // Calculate distances
    float horz_hit_distance = found_horz_wall_hit
                                  ? sqrt((horz_wall_hit.x - data->x) * (horz_wall_hit.x - data->x) +
                                         (horz_wall_hit.y - data->y) * (horz_wall_hit.y - data->y))
                                  : __FLT_MAX__;

    float vert_hit_distance = found_vert_wall_hit
                                  ? sqrt((vert_wall_hit.x - data->x) * (vert_wall_hit.x - data->x) +
                                         (vert_wall_hit.y - data->y) * (vert_wall_hit.y - data->y))
                                  : __FLT_MAX__;

    if (vert_hit_distance < horz_hit_distance) {
        ray->distance = vert_hit_distance;
        ray->wall_hit_x = vert_wall_hit.x;
        ray->wall_hit_y = vert_wall_hit.y;
        ray->is_vertical_hit = true;
    } else {
        ray->distance = horz_hit_distance;
        ray->wall_hit_x = horz_wall_hit.x;
        ray->wall_hit_y = horz_wall_hit.y;
        ray->is_vertical_hit = false;
    }
}

// void cast_all_rays(t_data *data) {
//     float ray_angle = data->ply_angle - (FOV_ANGLE / 2);
//     for (int ray_id = 0; ray_id < S_W; ray_id++) {
//         cast_ray(ray_angle, &data->rays[ray_id], data);
//         ray_angle += FOV_ANGLE / S_W;
//     }
// }

// void game_loop(void *param) {
//     t_data *data = (t_data *)param;
//     cast_all_rays(data);
//     for (int ray = 0; ray < S_W; ray++) {
//         render_wall(data, ray);
//     }
// }

void cast_all_rays(t_data *data) {
    for (int i = 0; i < S_W; i++) {
        cast_ray(data, i);
        render_wall(data, i);
    }
}

int game_loop(void *param) {
    t_data *data = (t_data *)param;
    cast_all_rays(data);
    mlx_put_image_to_window(data->mlx, data->win, data->p_image, 0, 0);
    return (0);
}


void ft_hook(mlx_key_data_t key_game, void *param) {
    t_data *game = (t_data *)param;
    int new_x = game->x;
    int new_y = game->y;

    if (key_game.key == MLX_KEY_ESCAPE && (key_game.action == MLX_PRESS || key_game.action == MLX_REPEAT)) {
        mlx_close_window(game->mlx);
    } else if (key_game.key == MLX_KEY_LEFT && (key_game.action == MLX_PRESS || key_game.action == MLX_REPEAT)) {
        new_x = game->x - 1;
    } else if (key_game.key == MLX_KEY_RIGHT && (key_game.action == MLX_PRESS || key_game.action == MLX_REPEAT)) {
        new_x = game->x + 1;
    } else if (key_game.key == MLX_KEY_UP && (key_game.action == MLX_PRESS || key_game.action == MLX_REPEAT)) {
        new_y = game->y - 1;
    } else if (key_game.key == MLX_KEY_DOWN && (key_game.action == MLX_PRESS || key_game.action == MLX_REPEAT)) {
        new_y = game->y + 1;
    }

    if (new_x >= 0 && new_x < game->map_w && new_y >= 0 && new_y < game->map_h && game->map[new_y][new_x] != '1') {
        game->x = new_x;
        game->y = new_y;
        render_player(game);
    }
}

t_data *init_argument() {
    t_data *data = calloc(1, sizeof(t_data));
    if (!data) return NULL;

    data->map = calloc(10, sizeof(char *));
    if (!data->map) {
        free(data);
        return NULL;
    }

    data->map[0] = strdup("1111111111111111111111111");
    data->map[1] = strdup("1000000000000000000100001");
    data->map[2] = strdup("1001000000000000000000001");
    data->map[3] = strdup("1001000000000000001000001");
    data->map[4] = strdup("1001000000000P00001000001");
    data->map[5] = strdup("1001000000100000001000001");
    data->map[6] = strdup("1001000000000000001000001");
    data->map[7] = strdup("1001000000001000001000001");
    data->map[8] = strdup("1111111111111111111111111");
    data->map[9] = NULL;

    data->map_w = 25; // map width
    data->map_h = 9;  // map height
    data->fov_rd = FOV_ANGLE;
    data->ply_angle = M_PI / 2;

    return data;
}

void output_map(t_data *data) {
    int i, j;
    mlx_image_t *wall_img = mlx_new_image(data->mlx, 30, 30);
    memset(wall_img->pixels, 255, wall_img->width * wall_img->height * 4);

    for (i = 0; i < data->map_h; i++) {
        for (j = 0; j < data->map_w; j++) {
            if (data->map[i][j] == '1') {
                mlx_image_to_window(data->mlx, wall_img, j * 30, i * 30);
            }
        }
    }

    data->wall_t = mlx_load_png("../assets/wall.png");
    if (!data->wall_t) {
        printf("Failed to load wall texture\n");
        return;
    }

    data->p_image = mlx_texture_to_image(data->mlx, data->wall_t);
    mlx_image_to_window(data->mlx, data->p_image, data->x * 30, data->y * 30);
}

void start_the_game(t_data *data) {
    data->mlx = mlx_init(S_W, S_H, "Raycaster", true);
    output_map(data);
    mlx_loop_hook(data->mlx, game_loop, data);
    mlx_key_hook(data->mlx, ft_hook, data);
    mlx_loop(data->mlx);
    mlx_delete_image(data->mlx, data->p_image);
    mlx_delete_texture(data->wall_t);
    mlx_terminate(data->mlx);
    for (int i = 0; i < 9; i++) free(data->map[i]);
    free(data->map);
    free(data);
}

int main() {
    t_data *data = init_argument();
    if (!data) {
        printf("Failed to initialize data\n");
        return 1;
    }
    start_the_game(data);
    return 0;
}