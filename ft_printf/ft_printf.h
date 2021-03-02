/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbus <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:19:21 by mbus              #+#    #+#             */
/*   Updated: 2021/03/02 18:58:11 by mbus             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "./libft/libft.h"

typedef	struct	s_info
{
	int			width;
	int			prec;
	int			zero;
	int			minus;
}				t_info;

int				print_char(t_info *info, va_list ap);
int				print_s(t_info *info, va_list ap);
int				print_p(va_list ap);
int				print_d(t_info *info, va_list ap);
int				print_x(t_info *info, va_list ap);
int				print_upx(t_info *info, va_list ap);
int				print_u(t_info *info, va_list ap);
int				print_perc(t_info *info);
void			zero_with_prec(t_info *info, int *count);
void			zero_noprec(t_info *info, int *count);
int				neg_int(int tmp, char **tmp2, int *len, t_info *info);
void			num_nominus(t_info *info, int *count, int len, int tmp);
void			num_minus(t_info *info, int *count, int len, char *tmp2);
char			*ft_utoa(size_t n, char *base);
void			putstr(char *tmp2, int *count);
#endif
