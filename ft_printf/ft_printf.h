/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbus <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:19:21 by mbus              #+#    #+#             */
/*   Updated: 2021/02/26 15:20:07 by mbus             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include "./libft/libft.h"

typedef	struct	s_info
{
	int	width;
	int	prec;
	int	zero;
	int	minus;
}				t_info;

int				print_char(t_info *info, va_list ap);
int				print_s(t_info *info, va_list ap);
int				print_p(va_list ap);
#endif
