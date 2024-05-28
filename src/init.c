/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 04:05:35 by ohamadou          #+#    #+#             */
/*   Updated: 2024/05/24 19:51:44 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

	// Find player position
	for (int i = 0; i < 9; i++) {
		char *p = strchr(data->map[i], 'P');
		if (p) {
			data->y = i;
			data->x = p - data->map[i];
			break;
		}
	}

	data->map_w = 25; // map width
	data->map_h = 9;  // map height
	data->i = 0;
	data->j = 0;

	return data;
}