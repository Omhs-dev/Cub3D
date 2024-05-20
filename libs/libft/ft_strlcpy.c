/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 01:15:07 by ohamadou          #+#    #+#             */
/*   Updated: 2023/05/30 13:56:04 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int		srclen;
	size_t	i;

	srclen = ft_strlen(src);
	i = 0;
	while (src[i] && i < (dstsize - 1))
	{
		if (dstsize > 0)
			dst[i] = src[i];
		i++;
	}
	if (dstsize == 0)
		return (i);
	dst[i] = '\0';
	return (srclen);
}

// int main()
// {
// 	char *string;
// 	char buffer[19];
// 	int r;

// 	string = "Hello there, Venus";
// 	r = ft_strlcpy(buffer, string, 10);
// 	printf("Copied '%s' into '%s', length %d\n", string, buffer, r);
// 	return (0);
// }
