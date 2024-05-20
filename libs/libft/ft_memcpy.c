/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:33:26 by ohamadou          #+#    #+#             */
/*   Updated: 2022/11/11 20:33:26 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*des;
	char	*sr;

	des = (char *)dest;
	sr = (char *)src;
	i = 0;
	if (!des && !sr)
		return (NULL);
	while (i < n)
	{
		des[i] = sr[i];
		i++;
	}
	return (dest);
}
