/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 05:39:31 by voszadcs          #+#    #+#             */
/*   Updated: 2024/06/10 05:40:41 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	map = parse(argc, argv);
	start_the_game(map);
	return (EXIT_SUCCESS);
}

// int main(int argc, char **argv)
// {
// 	mmain(argc, argv);
// 	system("leaks a.out");
// }