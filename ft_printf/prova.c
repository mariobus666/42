#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>
void prova(t_info *info)
{
	info->width = 0;
}

int main()
{
	char a = 'a';

	char *p = &a;
	char *ptr = p;
	//printf("%u\n", &a);
	printf("%p\n", &a);
	printf("%zu", &a);
}

