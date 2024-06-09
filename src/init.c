/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 04:05:35 by ohamadou          #+#    #+#             */
/*   Updated: 2024/06/09 06:55:32 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>



// Function prototypes
// Helper function to free a split array
void free_split(char **split)
{
    if (!split) return;
    for (int i = 0; split[i]; i++) free(split[i]);
    free(split);
}

static void find_player_position(t_map *map_data)
{
    for (int y = 0; y < map_data->map_h; y++) {
        for (int x = 0; x < ft_strlen(map_data->map[y]); x++) {
            if (map_data->map[y][x] == 'N' || map_data->map[y][x] == 'S' ||
                map_data->map[y][x] == 'E' || map_data->map[y][x] == 'W') {
                map_data->player_x = x;
                map_data->player_y = y;
                map_data->map[y][x] = '0'; // Replace player character with '0'
                return;
            }
        }
    }
    // If no player position is found, set to -1
    map_data->player_x = -1;
    map_data->player_y = -1;
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

// Helper function to add a line to the map
static int add_map_line(char ***m_line, int *line_count, char *line)
{
    char **new_lines = (char **)realloc(*m_line, sizeof(char *) * (*line_count + 1 + 1));
    if (!new_lines) return -1;

    *m_line = new_lines;
    (*m_line)[*line_count] = strdup(line);
    if (!(*m_line)[*line_count]) return -1;

    (*line_count)++;
    (*m_line)[*line_count] = NULL; // Ensure NULL termination

    return 0;
}

// Function to parse a line and update map_data accordingly
static int parse_line(char *line, t_map *map_data)
{
    if (strncmp(line, "NO ", 3) == 0) {
        map_data->north = strdup(line + 3);
        return 0;
    }
    if (strncmp(line, "SO ", 3) == 0) {
        map_data->south = strdup(line + 3);
        return 0;
    }
    if (strncmp(line, "EA ", 3) == 0) {
        map_data->east = strdup(line + 3);
        return 0;
    }
    if (strncmp(line, "WE ", 3) == 0) {
        map_data->west = strdup(line + 3);
        return 0;
    }
    if (strncmp(line, "F ", 2) == 0) {
        parse_colors(line + 2, &map_data->floor);
        return 0;
    }
    if (strncmp(line, "C ", 2) == 0) {
        parse_colors(line + 2, &map_data->ceiling);
        return 0;
    }
    return 1; // Return 1 if the line is part of the map
}

// Main function to process the map lines from the input
static int process_map_lines(t_map *map_data, char **input)
{
    char **map_lines = NULL;
    int map_lines_count = 0;
    int map_started = 0;

    while (*input)
    {
        if (parse_line(*input, map_data) == 1) {
            if (map_started || (**input == ' ' || **input == '1')) {
                map_started = 1;
                if (add_map_line(&map_lines, &map_lines_count, *input) != 0) {
                    free_split(map_lines);
                    return -1;
                }
            }
        }
        input++;
    }
    map_data->map = map_lines;
    map_data->map_h = map_lines_count;
    map_data->map_w = map_lines_count > 0 ? strlen(map_lines[0]) : 0;
    return 0;
}

char *get_next_lines(int fd) {
    static char buffer[BUFFER_SIZE];
    static int index = 0;
    static int length = 0;
    char *line = NULL;
    size_t line_length = 0;

    while (index < length || (length = read(fd, buffer, BUFFER_SIZE)) > 0) {
        if (index >= length) {
            index = 0;
            continue;
        }

        char *newline = strchr(buffer + index, '\n');
      size_t chunk_length;
		if (newline) {
		    chunk_length = (size_t)(newline - (buffer + index));
		} else {
		    chunk_length = (size_t)(length - index);
		}


        char *new_line = realloc(line, line_length + chunk_length + 1);
        if (!new_line) {
            free(line);
            return NULL;
        }

        ft_memcpy(new_line + line_length, buffer + index, chunk_length);
        line_length += chunk_length;
        index += chunk_length + (newline ? 1 : 0);
        new_line[line_length] = '\0';
        line = new_line;

        if (newline) break;
    }

    if (line_length == 0 && length <= 0) {
        free(line);
        return NULL;
    }

    return line;
}

char **read_files(const char *file_path)
{
    int fd = open(file_path, O_RDONLY);
    if (fd < 0) error(MAP_DESCRIPTION); // Replace with your error handling

    char **lines = NULL;
    char *line = NULL;
    int line_count = 0;

    while ((line = get_next_lines(fd)) != NULL) {
        if (add_map_line(&lines, &line_count, line) != 0) {
            free(line);
            free_split(lines);
            close(fd);
            return NULL;
        }
        free(line);
    }

    close(fd);
    return lines;
}

// The main parsing function to read the file and parse map
t_map *parse_map1(const char *file_path)
{
    t_map *map_data = (t_map *)calloc(1, sizeof(t_map));
    if (!map_data) return NULL;

    char **input = read_files(file_path);
    if (!input) {
        free(map_data);
        return NULL;
    }

    if (process_map_lines(map_data, input) != 0) {
        free_split(input);
        free_map_struct(map_data);
        return NULL;
    }
	find_player_position(map_data);
    // Output map for debugging
    for (int i = 0; i < map_data->map_h; i++) {
        printf("%s\n", map_data->map[i]);
    }

    free_split(input);
    return map_data;
}







// int parse_colors(char *line, int **colors) {
// 	char **split = ft_split(line, ',');
// 	if (!split) return -1;
// 	*colors = (int *)malloc(3 * sizeof(int));
// 	if (!(*colors)) {
// 		free_split(split);
// 		return -1;
// 	}
// 	(*colors)[0] = atoi(split[0]);
// 	(*colors)[1] = atoi(split[1]);
// 	(*colors)[2] = atoi(split[2]);
// 	free_split(split);
// 	return 0;
// }

// t_map *parse_map1(const char *file_path)
// {
// 	t_map *map_data = (t_map *)calloc(1, sizeof(t_map));
// 	if (!map_data) return NULL;

// 	FILE *file = fopen(file_path, "r");
// 	if (!file) {
// 		free(map_data);
// 		return NULL;
// 	}

// 	char line[BUFFER_SIZE];
// 	int map_started = 0;
// 	char **map_lines = NULL;
// 	int map_lines_count = 0;

// 	while (fgets(line, sizeof(line), file)) {
// 		// Remove newline
// 		line[strcspn(line, "\n")] = '\0';

// 		if (strncmp(line, "NO ", 3) == 0)
// 			map_data->north = strdup(line + 3);
// 		else if (strncmp(line, "SO ", 3) == 0)
// 			map_data->south = strdup(line + 3);
// 		else if (strncmp(line, "EA ", 3) == 0)
// 			map_data->east = strdup(line + 3);
// 		else if (strncmp(line, "WE ", 3) == 0)
// 			map_data->west = strdup(line + 3);
// 		else if (strncmp(line, "F ", 2) == 0) {
// 			map_data->ff = ft_split(line + 2, ',');
// 			parse_colors(line + 2, &map_data->floor);
// 		}
// 		else if (strncmp(line, "C ", 2) == 0) {
// 			map_data->cc = ft_split(line + 2, ',');
// 			parse_colors(line + 2, &map_data->ceiling);
// 		}
// 		else if (map_started || (line[0] == ' ' || line[0] == '1')) {
// 			map_started = 1;
// 			map_lines = (char **)realloc(map_lines, sizeof(char *) * (map_lines_count + 1));
// 			map_lines[map_lines_count++] = strdup(line);
// 		}
// 	}

// 	fclose(file);

// 	if (map_lines_count > 0) {
// 		map_data->map = map_lines;
// 		map_data->map_h = map_lines_count;
// 		map_data->map_w = strlen(map_lines[0]);
// 		// Finding player start position
// 		for (int y = 0; y < map_lines_count; y++) {
// 			for (int x = 0; x < ft_strlen(map_lines[y]); x++) {
// 				if (map_lines[y][x] == 'N' || map_lines[y][x] == 'S' || 
// 					map_lines[y][x] == 'E' || map_lines[y][x] == 'W') {
// 					map_data->player_x = x;
// 					map_data->player_y = y;
// 					map_lines[y][x] = '0';
// 					break;
// 				}
// 			}
// 		}
// 	} else {
// 		free(map_data);
// 		return NULL;
// 	}

// 	return map_data;
// }