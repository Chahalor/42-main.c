#include "ft_printf.h"

#include <stdarg.h>
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = vprintf(format, args);
	va_end(args);
	return (count);
}