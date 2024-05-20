/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:05:26 by ohamadou          #+#    #+#             */
/*   Updated: 2023/05/30 13:52:27 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static int	blanks(const char c)
{
	if (c == ' ' || c == '\n' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	opr;
	int	sign;

	i = 0;
	while (blanks(str[i]))
		i++;
	if ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
			i++;
	}
	opr = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		opr = opr * 10 + (str[i] - '0');
		i++;
	}
	return (opr * sign);
}

// int	main()
// {
//     char str[] = "er584526";
//     char str1[] = "584526";
//     int val = ft_atoi(str);
//     int val1 = ft_atoi(str1);
//     printf("%d\n", val);
//     printf("%d\n", val1);
//     return 0;
// }
