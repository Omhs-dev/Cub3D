/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:25:07 by ohamadou          #+#    #+#             */
/*   Updated: 2023/05/30 13:57:37 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;

	ptr = NULL;
	if (*lst == NULL)
		return ;
	while (*lst != NULL)
	{
		ptr = *lst;
		(*lst) = (*lst)-> next;
		del(ptr-> content);
		free(ptr);
	}
}
