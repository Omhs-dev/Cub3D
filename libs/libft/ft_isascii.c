/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:03:04 by ohamadou          #+#    #+#             */
/*   Updated: 2023/05/30 13:52:32 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_isascii(int as)
{
	if (as >= 0 && as <= 127)
		return (1);
	else
		return (0);
}

// int main()
// {
//     int as;

//     as = '\t';
//     if (ft_isascii(as))
//         write(1, "ascii", 5);
//     else
//         write(1, "not", 3);
//     return(0);
// }
