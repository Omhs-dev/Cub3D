/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:21:04 by ohamadou          #+#    #+#             */
/*   Updated: 2023/05/30 13:56:29 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)s + len);
	while (len--)
	{
		if ((char)c == s[len])
			return ((char *)s + len);
	}
	return (NULL);
}

// int main () {
//    const char str[] = "mamouth";
//    const char ch = 'm';
//    char *ret;

//    ret = ft_strchr(str, ch);

//    printf("String after |%c| is - |%s|\n", ch, ret);
//    return(0);
// }
