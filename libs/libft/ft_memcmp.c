/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:01:58 by ohamadou          #+#    #+#             */
/*   Updated: 2023/05/30 13:54:52 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
				i++;
	}
	return (0);
}

// int main () {
// 	char	str1[15];
// 	char	str2[15];
// 	int	ret;

// 	ft_memcpy(str1, "abcdef", 6);
// 	ft_memcpy(str2, "ABCDEF", 6);
// 	ret = ft_memcmp(str1, str2, 5);
// 	if (ret > 0)
// 		printf("str2 is less than str1");
// 	else if (ret < 0)
// 		printf("str1 is less than str2");
// 	else
// 		printf("str1 is equal to str2");
// 	return (0);
// }
