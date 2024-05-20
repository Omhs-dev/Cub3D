/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 01:32:14 by ohamadou          #+#    #+#             */
/*   Updated: 2022/11/29 01:32:14 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static int	int_count(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int				lenn;
	unsigned int	nb;
	char			*mem;

	lenn = int_count(n);
	mem = (char *)malloc((lenn + 1) * sizeof(char));
	if (!mem)
		return (NULL);
	mem[lenn--] = '\0';
	if (n < 0)
		nb = -n;
	else
		nb = n;
	while (lenn >= 0)
	{
		mem[lenn] = (nb % 10) + 48;
		lenn--;
		nb /= 10;
	}
	if (n < 0)
		mem[0] = '-';
	return (mem);
}
