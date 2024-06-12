/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:18:03 by ohamadou          #+#    #+#             */
/*   Updated: 2024/06/12 19:21:42 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "./get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("map.cub.cub", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
	return (0);
}

// int main()
// {
// 	mmain();
// 	system("leaks a.out");
// }