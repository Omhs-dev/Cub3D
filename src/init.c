/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 04:05:35 by ohamadou          #+#    #+#             */
/*   Updated: 2024/06/08 18:33:32 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void free_split(char **split)
{
	if (!split) return;
	for (int i = 0; split[i]; i++) free(split[i]);
	free(split);
}

int parse_colors(char *line, int **colors) {
	char **split = ft_split(line, ',');
	if (!split) return -1;
	*colors = (int *)malloc(3 * sizeof(int));
	if (!(*colors)) {
		free_split(split);
		return -1;
	}
	(*colors)[0] = atoi(split[0]);
	(*colors)[1] = atoi(split[1]);
	(*colors)[2] = atoi(split[2]);
	free_split(split);
	return 0;
}

t_map *parse_map1(const char *file_path)
{
	t_map *map_data = (t_map *)calloc(1, sizeof(t_map));
	if (!map_data) return NULL;

	FILE *file = fopen(file_path, "r");
	if (!file) {
		free(map_data);
		return NULL;
	}

	char line[BUFFER_SIZE];
	int map_started = 0;
	char **map_lines = NULL;
	int map_lines_count = 0;

	while (fgets(line, sizeof(line), file)) {
		// Remove newline
		line[strcspn(line, "\n")] = '\0';

		if (strncmp(line, "NO ", 3) == 0)
			map_data->north = strdup(line + 3);
		else if (strncmp(line, "SO ", 3) == 0)
			map_data->south = strdup(line + 3);
		else if (strncmp(line, "EA ", 3) == 0)
			map_data->east = strdup(line + 3);
		else if (strncmp(line, "WE ", 3) == 0)
			map_data->west = strdup(line + 3);
		else if (strncmp(line, "F ", 2) == 0) {
			map_data->ff = ft_split(line + 2, ',');
			parse_colors(line + 2, &map_data->floor);
		}
		else if (strncmp(line, "C ", 2) == 0) {
			map_data->cc = ft_split(line + 2, ',');
			parse_colors(line + 2, &map_data->ceiling);
		}
		else if (map_started || (line[0] == ' ' || line[0] == '1')) {
			map_started = 1;
			map_lines = (char **)realloc(map_lines, sizeof(char *) * (map_lines_count + 1));
			map_lines[map_lines_count++] = strdup(line);
		}
	}

	fclose(file);

	if (map_lines_count > 0) {
		map_data->map = map_lines;
		map_data->map_h = map_lines_count;
		map_data->map_w = strlen(map_lines[0]);
		// Finding player start position
		for (int y = 0; y < map_lines_count; y++) {
			for (int x = 0; x < ft_strlen(map_lines[y]); x++) {
				if (map_lines[y][x] == 'N' || map_lines[y][x] == 'S' || 
					map_lines[y][x] == 'E' || map_lines[y][x] == 'W') {
					map_data->player_x = x;
					map_data->player_y = y;
					map_lines[y][x] = '0';
					break;
				}
			}
		}
	} else {
		free(map_data);
		return NULL;
	}

	return map_data;
}