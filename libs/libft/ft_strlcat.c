/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:44:31 by ohamadou          #+#    #+#             */
/*   Updated: 2023/05/30 13:56:00 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	lendst;
	size_t	lensrc;

	lendst = ft_strlen(dst);
	lensrc = ft_strlen((const char *)src);
	if (dstsize <= lendst)
		return (dstsize + lensrc);
	i = 0;
	j = lendst;
	while (src[i] && i < (dstsize - lendst - 1))
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	if (dstsize == 0)
		return (i);
	dst[j] = '\0';
	return (lendst + lensrc);
}

// int main()
// {
// 	char first[] = "This is ";
//     char last[] = "a potentially long string";
//     int r;
//     int size = 64;
//     char buffer[size];

//     strcpy(buffer,first);
//     r = ft_strlcat(buffer,last,size);

//     puts(buffer);
//     printf("Value returned: %d\n",r);
//     if( r > size )
//         puts("String truncated");
//     else
//         puts("String was fully copied");

//     return(0);
// }
