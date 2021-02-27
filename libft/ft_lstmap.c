/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbus <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 17:22:08 by mbus              #+#    #+#             */
/*   Updated: 2021/01/22 17:51:03 by mbus             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *last;
	t_list *first;

	first = 0;
	while (lst)
	{
		if (!first)
		{
			last = ft_lstnew(f(lst->content));
			first = last;
		}
		else
		{
			last->next = ft_lstnew(f(lst->content));
			last = last->next;
			if (!last)
			{
				ft_lstclear(&first, del);
				return (0);
			}
		}
		lst = lst->next;
	}
	return (first);
}
