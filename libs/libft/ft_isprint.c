/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:40:56 by ohamadou          #+#    #+#             */
/*   Updated: 2023/05/30 13:52:54 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_isprint(int pr)
{
	if (pr <= 31 || pr >= 127)
		return (0);
	else
		return (1);
}

// int main(void)
// {
// 	int as;

// 	as = '#';
// 	if (ft_isprint(as))
// 		write(1, "print", 5);
// 	else
// 		write(1, "not", 3);
// }