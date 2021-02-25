#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>
void prova(t_info *info)
{
	info->width = 0;
}

int main()
{
	printf("%5.2s", "ciao");
}
