#include "ft_printf.h"

void	putstr(char *tmp2, int *count)
{
	while (*tmp2)
	{
		write(1, tmp2, 1);
		(*count)++;
		tmp2++;
	}
}

int	print_d(t_info *info, va_list ap)
{
	int 			count;
	int 			tmp;
	char 			*tmp2;
	int 			len;

	count = 0;
	tmp = va_arg(ap, int);
	tmp2 = ft_itoa(tmp);
	len = ft_strlen(tmp2);
	if (tmp == 0 && info->prec == 0)
		zero_noprec(info, &count);
	else if (tmp == 0 && info->prec != 0)
		zero_with_prec(info, &count);
	else
	{
		count = neg_int(tmp, &tmp2, &len, info);
		if(info->minus == 0)
		{
			num_nominus(info, &count, len, tmp);
			putstr(tmp2, &count);
		}
		else
			num_minus(info, &count, len, tmp2);
	}
	return (count);
}
