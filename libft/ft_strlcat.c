/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbus <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:24:30 by mbus              #+#    #+#             */
/*   Updated: 2021/01/19 16:09:54 by mbus             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t len;

	i = 0;
	len = ft_strlen(dst);
	while (dstsize && *(src + i) && i + len < dstsize - 1)
	{
		*(dst + len + i) = *(src + i);
		i++;
	}
	if (len < dstsize)
		*(dst + len + i) = 0;
	if (len >= dstsize)
		return (ft_strlen(src) + dstsize);
	return (ft_strlen(src) + len);
}
