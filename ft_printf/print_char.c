/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbus <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 12:06:52 by mbus              #+#    #+#             */
/*   Updated: 2021/02/26 12:16:27 by mbus             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>
int print_char(t_info *info, va_list ap)
{
	char	w;
	char	c;
	int		count;

	count = 0;
	c = va_arg(ap, int);
	if (info->zero == 0)
		w = ' ';
	else
		w = '0';
	if (info->minus == 0)
		while (count++ < info->width - 1)
			write(1, &w, 1);
	if (info->prec != 0)
		write(1, &c, 1);
	if (info->minus == 1)
		while (count++ < info->width - 1)
			write(1, &w, 1);
	return (count);
}

int	print_s(t_info *info, va_list ap)
{
	char	*tmp;
	char	w;
	int		len;
	int		count;

	count = 0;
	tmp = va_arg(ap, char *);
	len = ft_strlen(tmp);
	if (info -> prec > len)
		info->prec = len;
	if (info->zero == 0)
		w = ' ';
	else
		w = '0';
	if (info->minus == 0)
	{
		if (info->prec != -1)
			while (count++ < info->width - info->prec)
				write(1, &w, 1);
		else
			while (count++ < info->width - len - 1)
				write(1, &w, 1);
		write(1, tmp, info->prec);
		count += info->prec;
	}
	if (info->minus == 1)
	{
		if (info->prec != -1)
		{
			write(1, tmp, info->prec);
			count += info->prec;
		}
		else
		{
			write(1,tmp, len - 1);
			count += len - 1;
		}
		while (count++ < info->width)
			write(1, &w, 1);
	}
	free(tmp);
	return (count - 1);
}
