/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbus <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 10:23:38 by mbus              #+#    #+#             */
/*   Updated: 2021/01/18 18:36:08 by mbus             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		isinboth(char a, char const *set)
{
	while (*set)
	{
		if (a == *set)
			return (1);
		set++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t		len;
	size_t		i;
	size_t		j;
	char		*copy;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (0);
	len = ft_strlen(s1);
	while (isinboth(s1[i], set) && s1[i])
		i++;
	while (isinboth(s1[len - 1], set) && i < len)
		len--;
	if (!(copy = malloc(len - i + 1)))
		return (0);
	while (i < len)
		copy[j++] = s1[i++];
	copy[j] = 0;
	return (copy);
}
