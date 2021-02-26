/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbus <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 12:16:34 by mbus              #+#    #+#             */
/*   Updated: 2021/02/26 16:18:19 by mbus             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <unistd.h>

char *size_to_hex(size_t to_conv, char *base)
{
	char *tmp;
	int i;

	i = 0;
	tmp = malloc(sizeof(13));
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
}

int	print_d(t_info *info, va_list ap)
{
	int count;
	int tmp;
	char *tmp2;
	int len;

	count = 0;
	i = 0;
	tmp = va_arg(ap, int);
	tmp2 = ft_itoa(tmp);
	len = ft_strlen(tmp2);

	if (tmp == 0 && info->prec == 0)
	{
		write(1, ' ', info->width);
		count += info->width;
	}
	else if (tmp == 0 && info->prec != 0)
	{
		if(info->minus == 0)
		{
			if(info->prec - info->width > 0)
			{
				write(1, ' ', info->prec - info->width);
				count+= info->prec - info->width;
			}
			else
			{
				write(1, '0', info->prec);
				count += info->prec;
			}
		}
	}
	else
	{
		if(info->minus == 1)
	}
}


