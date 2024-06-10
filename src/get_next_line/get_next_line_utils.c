/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:32:46 by ohamadou          #+#    #+#             */
/*   Updated: 2023/03/31 02:10:29 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	foo_strlen(char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
		a++;
	return (a);
}

char	*foo_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *)(s + foo_strlen(s)));
	while (*s)
	{
		if ((char)c == *s)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*foo_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * ((foo_strlen(s1) + foo_strlen(s2)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[foo_strlen(s1) + foo_strlen(s2)] = '\0';
	free(s1);
	s1 = str;
	return (str);
}

//return a new string that containes the first line of the strng
char	*get_the_line(char *strng)
{
	char	*str;
	int		i;

	i = 0;
	if (!strng[i])
		return (NULL);
	while (strng[i] && strng[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (strng[i] && strng[i] != '\n')
	{
		str[i] = strng[i];
		i++;
	}
	if (strng[i] == '\n')
	{
		str[i] = strng[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	*foo_memcpy(void *dest, const void *src, size_t n)
{
	char	*des;
	char	*sr;
	size_t	i;

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
