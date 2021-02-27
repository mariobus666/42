/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbus <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 12:20:51 by mbus              #+#    #+#             */
/*   Updated: 2021/02/27 14:30:00 by mbus             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int		len(size_t nb)
{
	int		lenght;

	lenght = 0;
	if (nb == 0)
		lenght++;
	while (nb > 0)
	{
		nb = nb / 16;
		lenght++;
	}
	return (lenght);
}

char			*ft_itoa_hex(size_t n, char *base)
{
	char	*str;
	size_t	nb;
	int		i;

	nb = n;
	i = len(n);
	if (!(str = malloc(i + 1)))
		return (NULL);
	str[i--] = '\0';
	if (nb == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (nb > 0)
	{
		str[i--] = base[nb % 16];
		nb /= 16;
	}
	return (str);
}

int				print_x(t_info *info, va_list ap)
{
	size_t	to_conv;
	int		count;
	char	*tmp;
	int		len;

	count = 0;	
	to_conv = (size_t)(va_arg(ap, unsigned int));
	tmp = ft_itoa_hex(to_conv, "0123456789abcdef");
	len = ft_strlen(tmp);

	if(info->minus == 0)


	while (*tmp)
	{
		write(1, tmp, 1);
		count++;
		tmp++;
	}
	return (count);
}

int				print_upx(t_info *info, va_list ap)
{
	size_t	to_conv;
	int		count;
	char	*tmp;

	count = 0;	
	to_conv = (size_t)(va_arg(ap, unsigned int));
	tmp = ft_itoa_hex(to_conv, "0123456789ABCDEF");

	while (*tmp)
	{
		write(1, tmp, 1);
		count++;
		tmp++;
	}
	return (count);
}
