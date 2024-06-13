/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voszadcs <voszadcs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 02:03:19 by voszadcs          #+#    #+#             */
/*   Updated: 2024/06/13 02:14:52 by voszadcs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*d;

	if (count != 0 && count * size / count != size)
		return (0);
	d = malloc(count * size);
	if (!d)
		return (NULL);
	ft_bzero(d, count * size);
	return (d);
}
