/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:48:40 by ohamadou          #+#    #+#             */
/*   Updated: 2023/05/30 13:50:08 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

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
