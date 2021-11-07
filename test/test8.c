#include <stdio.h>
#include <unistd.h>

void    ft_putnbr_hex(unsigned long long n)
{
    char	tmp;

    if (n >= 16)
        ft_putnbr_hex(n / 16);
    if ((n % 16) >= 0 && (n % 16) <= 9)
        tmp = n % 16 + '0';
    else
       tmp = n % 16 + 'a' - 10;
    write(1, &tmp, 1);
}

int main()
{
	char *h;
	unsigned long long a;

	a = (unsigned long long)h;
	printf("%p\n", h);
	printf("%llu\n", a);
	write(1, "0x", 2);
	ft_putnbr_hex(a);
	printf("\n");
	return (0);
}
