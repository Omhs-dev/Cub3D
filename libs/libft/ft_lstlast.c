/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 01:24:43 by ohamadou          #+#    #+#             */
/*   Updated: 2023/05/30 13:57:12 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current_elmt;

	current_elmt = lst;
	if (current_elmt == NULL)
		return (NULL);
	while (current_elmt -> next != NULL)
	{
		current_elmt = current_elmt -> next;
	}
	return (current_elmt);
}
