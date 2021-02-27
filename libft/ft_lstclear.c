/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbus <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:18:45 by mbus              #+#    #+#             */
/*   Updated: 2021/01/22 16:46:12 by mbus             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *pos;
	t_list *clone;

	pos = *lst;
	if ((*lst) == 0)
		return ;
	while (pos)
	{
		clone = pos;
		pos = pos->next;
		ft_lstdelone(clone, del);
	}
	*lst = 0;
}
