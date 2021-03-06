/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:52:04 by flwang            #+#    #+#             */
/*   Updated: 2021/03/06 16:29:28 by flwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_info(t_info *info)
{
	info->width = 0;
	info->prec = -1;
	info->zero = 0;
	info->minus = 0;
	info->negnum = 0;
}

void	width_neg_star(t_info *info)
{
	if (info->width < 0)
	{
		info->width *= -1;
		info->minus = 1;
		info->zero = 0;
	}
}

void	prec_star(t_info *info, va_list ap)
{
	info->prec = va_arg(ap, int);
	if (info->prec < -1)
		info->prec = -1;
}
