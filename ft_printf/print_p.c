/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbus <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 12:16:34 by mbus              #+#    #+#             */
/*   Updated: 2021/02/27 14:29:42 by mbus             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	tmp = va_arg(ap, int);
	tmp2 = ft_itoa(tmp);
	len = ft_strlen(tmp2);
	if (tmp == 0 && info->prec == 0)
	{
		while (count++ < info->width)
			write(1, " ", 1);
		count--;
	}
	else if (tmp == 0 && info->prec != 0)
	{
		if (info->prec == -1)
			info->prec = 0;
		if(info->minus == 0)
		{
			while (count++ < info->width - info->prec)
				write(1, " ", 1);
			while (info->prec--)
			{
					write(1, "0", 1);
					count++;
			}
			count--;
		}
		else 
		{
			while (count++ < info->prec)
				write(1, "0", 1);
			count--;
			while (count++ < info->width)
				write(1, " ", 1);
			count--;
		}
	}
	else
	{
		if(info->minus == 0)
		{
			if(info->prec > len)
			{
				if (tmp < 0)
				{
					count++;
					tmp2++;
					len--;
				}
				while (count++ < info->width - info->prec)
					write(1, " ", 1);
				count--;
				if (tmp < 0)
					write(1, "-", 1);
				while (info->prec > len++)
				{
					write(1, "0", 1);
					count++;
				}
			}
			else 
				while (info->width > len++)
				{
					write(1, " ", 1);
					count++;
				}
			while (*tmp2)
			{
				write(1, tmp2, 1);
				count++;
				tmp2++;
			}
		}
		else 
		{
			if (tmp < 0)
			{
				write(1, "-", 1);
				count++;
				tmp2++;
				len--;
			}
			if(info->prec > len)
			{
				while (info->prec > len++)
				{
					write(1, "0", 1);
					count++;
				}
			}
			while (*tmp2)
			{
				write(1, tmp2, 1);
				count++;
				tmp2++;
			}
			while (info->width > count++)
				write(1, " ", 1);
			count--;
		}
	}
	return (count);
}


