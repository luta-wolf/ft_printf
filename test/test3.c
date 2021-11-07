#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int ft_printf(const char *str, ...)
{
	int		count;
	int		s;
	va_list	ap;

	count = 0;
	va_start(ap, str);
	while (str[count])
	{
		if (str[count] != '%')
			write(1, &str[count], 1);
		else
		{
			s = va_arg(ap, int);
			printf("%d\n", s);
			s = va_arg(ap, int);
			printf("%d\n", s);
			s = va_arg(ap, int);
			printf("%d\n", s);
		}
		count++;
	}
	va_end(ap);
	return (count);
}

int main()
{
	int a, b;
	a = ft_printf("Hello my dear friend\n%", 151, 1969, 359);
//	b = printf("Hello my dear friend\n%d %d\n", 151, 1969);
	printf("my_fun: %d\n", a);
//	printf("original: %d\n", b);
	return (0);
}
