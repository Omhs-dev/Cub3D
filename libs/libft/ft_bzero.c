/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:58:30 by ohamadou          #+#    #+#             */
/*   Updated: 2022/11/11 20:58:30 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*src;

	src = (char *)s;
	i = 0;
	while (i < n)
	{
		src[i] = '\0';
		i++;
	}
	return ;
}
