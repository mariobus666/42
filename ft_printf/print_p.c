/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbus <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 12:16:34 by mbus              #+#    #+#             */
/*   Updated: 2021/03/05 18:42:45 by mbus             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char *size_to_hex(size_t to_conv, char *base)
{
	char *tmp;
	int i;

	i = 0;
	tmp = malloc(13);
	while (to_conv > 0) 
	{
		tmp[i] = base[to_conv % 16];
		i++;
		to_conv = to_conv / 16;
	}
	tmp[i] = 0;
	return (tmp);
}

int	print_p(va_list ap)
{
	size_t	to_conv;
	int		count;
	char	*tmp;
	int		size;

	to_conv = (size_t)(va_arg(ap, void *));
	write(1, "0x", 2);
	count = 2;
	
	tmp = size_to_hex(to_conv, "0123456789abcdef");
	size = 11;
	while (size >= 0)
	{
		write(1, &tmp[size], 1);
		count++;
		size--;
	}
	return (count);
}D
