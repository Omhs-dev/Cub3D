/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 23:40:14 by ohamadou          #+#    #+#             */
/*   Updated: 2023/05/30 13:50:03 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
// typedef struct s_ft_printf
// {
// 	int print_len;
// 	int width;
// }   t_p;

static int	print(va_list args, const char format)
{
	int	print_len;

	print_len = 0;
	if (format == 'c')
		print_len += ft_printchar(va_arg(args, int));
	else if (format == 's')
		print_len += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		print_len += ft_printptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		print_len += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		print_len += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x')
		print_len += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == 'X')
		print_len += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		print_len += ft_printpercent();
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	int		print_len;
	int		i;
	va_list	args;

	va_start(args, str);
	print_len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (!str[i])
				break ;
			print_len += print(args, str[i]);
		}
		else
			print_len += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (print_len);
}
