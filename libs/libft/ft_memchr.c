/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:48:04 by ohamadou          #+#    #+#             */
/*   Updated: 2023/05/30 13:54:45 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	uc;

	str = (unsigned char *)s;
	uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (uc == str[i])
			return (str + i);
		i++;
	}
	return (NULL);
}

// int main()
// {
// 	const char str[] = "OmarHamadou";
// 	const char ch = 'm';
// 	char *ret;

// 	ret = ft_memchr(str, ch, ft_strlen(str));
// 	printf("String after |%c| is - |%s|\n", ch, ret);
// 	return (0);
// }
