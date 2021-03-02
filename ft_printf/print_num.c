#include "ft_printf.h"

void	zero_with_prec(t_info *info, int *count)
{
	if (info->prec == -1)
		info->prec = 1;
	if(info->minus == 0)
	{
		while ((*count)++ < info->width - info->prec)
			write(1, " ", 1);
		while (info->prec-- > 0)
		{
				write(1, "0", 1);
				(*count)++;
		}
		(*count)--;
	}
	else 
	{
		while ((*count)++ < info->prec)
			write(1, "0", 1);
		(*count)--;
		while ((*count)++ < info->width)
			write(1, " ", 1);
		(*count)--;
	}
}

void	zero_noprec(t_info *info, int *count)
{
	while ((*count)++ < info->width)
		write(1, " ", 1);
	(*count)--;
}

int	neg_int(int tmp, char **tmp2, int *len, t_info *info)
{
	if (tmp < 0)
	{
		if (info->minus == 1 || (info->width == 0 && info->prec != -1) || (info->zero == 1 && info->width > info->prec))
		{
			write(1, "-", 1);
			(*tmp2)++;
			(*len)--;
			return (1);
		}
	}
	return (0);
}

void	num_nominus(t_info *info, int *count, int len, int tmp)
{
	char	w;
	
	w = (info->zero == 1 && info->prec == -1) ? '0' : ' ';
	if(info->prec > len)
	{	
		while ((*count)++ < info->width - info->prec)
			write(1, &w, 1);
		(*count)--;
		while (info->prec > len++)
		{
			write(1, "0", 1);
			(*count)++;
		}
	}
	else 
		while (info->width > len++)
		{
			write(1, &w, 1);
			(*count)++;
		}
}

void	num_minus(t_info *info, int *count, int len, char *tmp2)
{

	char	w;
	
	w = (info->zero == 1 && info->prec == -1) ? '0' : ' ';
	if(info->prec > len)
	{
		while (info->prec > len++)
		{
			write(1, "0", 1);
			(*count)++;
		}
	}
	while (*tmp2)
	{
		write(1, tmp2, 1);
		(*count)++;
		tmp2++;
	}
	while (info->width > (*count)++)
		write(1, &w, 1);
	(*count)--;
}
