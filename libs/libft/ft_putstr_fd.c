/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:56:21 by ohamadou          #+#    #+#             */
/*   Updated: 2022/11/25 15:56:21 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
	if (!s)
		return ;
}

// int main () {
//     char str1[15];
//     char str2[15];

//     ft_putstr_fd("one\n", 2);
//     ft_putstr_fd("two\n", 1);
//     return (0);
// }