/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:56:32 by ohamadou          #+#    #+#             */
/*   Updated: 2022/11/25 15:56:32 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strdup(const char *s)
{
	char	*newsr;
	int		n;

	n = ft_strlen(s) + 1;
	newsr = (char *)malloc(n * sizeof(char));
	if (!newsr)
		return (NULL);
	ft_strlcpy(newsr, s, n);
	return (newsr);
}
