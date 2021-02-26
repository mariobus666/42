#include "ft_printf.h"

void	init_info(t_info *info)
{
	info->width = 0;
	info->prec = -1;
	info->zero = 0;
	info->minus = 0;
}

void	read_flags(const char **s, t_info *info)
{
	if (**s == '0')
	{
		info->zero = 1;
		(*s)++;
	}
	if (**s == '-')
	{
		info->minus = 1;
		info->zero = 0;
		(*s)++;
	}
}

void	read_precwidth(const char **s, va_list ap, t_info *info)
{
	if (**s == '*')
	{
		info->width = va_arg(ap, int);
		(*s)++;
	}
	if (ft_isdigit(**s))
		info->width = ft_atoi(*s);
	while (ft_isdigit(**s))
		(*s)++;
	if (**s == '.')
	{
		(*s)++;
		if (**s == '*')
		{
			info->prec = va_arg(ap, int);
			(*s)++;
		}
		else if (ft_isdigit(**s))
			info->prec = ft_atoi(*s);
		while (ft_isdigit(**s))
			(*s)++;
	}
}

int		read_type(const char s, t_info *info, va_list ap)
{
	int	count;

	count = 0;
	if (s == 'c')
		count += print_char(info, ap);
	if (s == 's')
		count += print_s(info, ap);
	if (s == 'p')
		count += print_p(ap);
	if (s == 'd')
		count += print_d(info, ap);
	return (count);
}

void	read_str(const char **s, va_list ap, int *res)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	while (**s)
	{
		if (**s == '%')
		{
			(*s)++;
			init_info(info);
			read_flags(s, info);
			read_precwidth(s, ap, info);
			*res += read_type(**s, info, ap);
			(*s)++;
		}
		else
		{
			write(1, *s, 1);
			(*s)++;
			(*res)++;
		}
	}
}

int	ft_printf(const char *s, ...)
{
	int		res;
	va_list	ap;

	res = 0;
	va_start(ap, s);
	read_str(&s, ap, &res);
	va_end(ap);
	return (res);
}

#include <stdio.h>
int main()
{
	char c[] = "ciao";
	
	printf("%d\n", ft_printf("%5.2p/n", c));
	printf("%d\n", printf("%5.2p/n", c));
}
