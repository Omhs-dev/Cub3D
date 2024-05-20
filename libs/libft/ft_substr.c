/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 22:37:31 by ohamadou          #+#    #+#             */
/*   Updated: 2022/11/26 22:37:31 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	n;

	if (!s)
		return (NULL);
	n = len;
	if (ft_strlen(s) - start < len)
		n = ft_strlen(s) + 1;
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	dest = (char *)malloc(sizeof(*s) * (n + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i + start] && ((i + start) < (len + start)))
	{
		dest[i] = s[i + start];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// int main()
// {
//     char *src;
//     int m = 7;
//     int n = 12;
//     src = "substr function Implementation";
//     char* dest = ft_substr(src, m, n);
//     printf("%s\n", dest);
//     return 0;
// }