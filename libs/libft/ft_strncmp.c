/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:14:59 by ohamadou          #+#    #+#             */
/*   Updated: 2023/05/30 13:56:19 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				len1;
	int				len2;
	size_t			i;

	if (n == 0)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (str1[i] == str2[i] && (str1[i] != '\0'
			&& str2[i] != '\0') && i < n - 1)
	{
			len1++;
			len2++;
			i++;
	}
	return ((str1[i]) - (str2[i]));
	return (0);
}

// int main()
// {
// 	char str1[15];
// 	char str2[15];
// 	int ret;

// 	strcpy(str1, "abcdef");
// 	strcpy(str2, "ABCDEF");
// 	ret = ft_strncmp(str1, str2, 4);
// 	if (ret < 0) {
// 		printf("str1 is less than str2");
// 	} else if(ret > 0) {
// 		printf("str2 is less than str1");
// 	} else {
// 		printf("str1 is equal to str2");
// 	}
// 	return (0);
// }
