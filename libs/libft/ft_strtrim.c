/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 19:42:01 by ohamadou          #+#    #+#             */
/*   Updated: 2023/05/30 13:56:34 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static int	char_in(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dst;
	size_t	i;
	size_t	start;
	size_t	end;

	start = 0;
	while (s1[start] && char_in(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && char_in(s1[end - 1], set))
		end--;
	dst = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (start < end)
		dst[i++] = s1[start++];
	dst[i] = 0;
	return (dst);
}

// int main(int argc, char const *argv[]) {
// 	if (argc > 1) {
// 		for (int i = 1; i < argc; i += 1)
// 		{
// 			printf("[%d] \"%s\"\n", i, ft_strtrim(argv[i], " hdhd"));
// 		}
// 	}
// 	return (0);
// }