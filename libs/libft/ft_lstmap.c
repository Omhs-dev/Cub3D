/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:06:07 by ohamadou          #+#    #+#             */
/*   Updated: 2023/05/30 13:57:13 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*cntr;

	ptr = NULL;
	while (lst != NULL)
	{
		if (lst -> content == NULL)
			ft_lstclear(&ptr, del);
		cntr = ft_lstnew(f(lst -> content));
		ft_lstadd_back(&ptr, cntr);
		lst = lst -> next;
	}
	return (ptr);
}
