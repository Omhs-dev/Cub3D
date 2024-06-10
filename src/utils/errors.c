/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 05:38:59 by voszadcs          #+#    #+#             */
/*   Updated: 2024/06/10 05:48:40 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/cub3d.h"

static void	errors_1(int errnum)
{
	if (errnum == WRONG_ARGS_NUM)
	{
		printf("Error\n Wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}
	else if (errnum == NAME_LENGTH)
	{
		printf("Error\n filename too long or too short\n");
		exit(EXIT_FAILURE);
	}
	else if (errnum == WRONG_EXTENSION)
	{
		printf("Error\n Wrong extension (file must have .cub extension)\n");
		exit (EXIT_FAILURE);
	}
	else if (errnum == FILE_OPEN)
	{
		printf("Error\n %s", strerror(errno));
		exit(EXIT_FAILURE);
	}
}

static void	errors_2(int errnum)
{
	if (errnum == MAP_DESCRIPTION)
	{
		printf("Error\n Invalid map description\n");
		exit(EXIT_FAILURE);
	}
	else if (errnum == INVALID_MAP)
	{
		printf("Error\n Invalid map\n");
		exit(EXIT_FAILURE);
	}
	else if (errnum == LOAD_TEXTURES)
	{
		printf("Error\n Failed to load textures\n");
		exit(EXIT_FAILURE);
	}
}

int	error(int errnum)
{
	if (errnum <= 4)
		errors_1(errnum);
	else
		errors_2(errnum);
	return (0);
}
