/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 20:23:06 by ohamadou          #+#    #+#             */
/*   Updated: 2024/05/31 05:29:34 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./includes/libft.h"

char	count_words(char const *str, char dlm)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != dlm)
		{
			count++;
			while (str[i] != dlm && str[i + 1])
				i++;
		}
		i++;
	}
	return (count);
}

static char	*get_words(char const *str, char dlm)
{
	int		i;
	char	*mem;
	int		j;

	i = 0;
	while (str[i] != dlm && str[i])
		i++;
	mem = (char *)malloc(sizeof(char) * (i + 1));
	if (!mem)
		return (NULL);
	j = 0;
	while (str[j] != dlm && str[j])
	{
		mem[j] = str[j];
		j++;
	}
	mem[j] = '\0';
	return (mem);
}

static char	**free_mem(char **str, int dlm)
{
	while (str)
	{
		free(str[dlm]);
		dlm--;
	}
	free(str);
	return (NULL);
}

static char	**mem_fill(char const *str, char d)
{
	char	**mem;

	if (!str)
		return (NULL);
	mem = (char **)malloc(sizeof(char *) * (count_words(str, d) + 1));
	if (!mem)
		return (NULL);
	return (mem);
}

char	**ft_split(char const *s, char c)
{
	char	**memm;
	int		j;

	memm = mem_fill(s, c);
	if (!memm)
		return (NULL);
	while (*s && *s == c)
		s++;
	j = 0;
	while (*s)
	{
		memm[j] = get_words(&*s, c);
		if (!memm[j])
		{
			free_mem(memm, j);
			return (NULL);
		}
		j++;
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	memm[j] = NULL;
	return (memm);
}
