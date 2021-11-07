#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
void ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int	size_nbr(int n)
{
	int		len;
	long	i;

	i = (long)n;
	if (n < 0)
		i = (long)n * -1;
	len = 0;
	while (i > 0)
	{
		i = i / 10;
		len++;
	}
	if (n > 0)
		return (len);
	else if (n == 0)
		return (1);
	else
		return (len + 1);
}

void	ft_putnbr(long int n)
{

	if (n < 0)
	{
		write (1, "-", 1);
		n = n * -1;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	char tmp = n % 10 + '0';
	write(1, &tmp, 1);

}

int	size_nbr_hex(unsigned int n)
{
	int				len;
	unsigned int	i;

	i = n;
	len = 0;
	while (i > 0)
	{
		i = i / 16;
		len++;
	}
	if (n == 0)
		return (1);
	return (len);
}

void    ft_putnbr_hex(unsigned int n)
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
	int a;
	int b;
	int x = 0xf;
	char *h;


	h = "Hello";
	b = 12349;

	printf("My fun Decimal:\n");
	ft_putnbr(b);
	a = size_nbr(b);
	printf("\nLen: %d\n", a);
	printf("Orig Decimal: %d\n\n", b);

	printf("My fun hex:\n");
	ft_putnbr_hex(b);
	printf("\n");
	a = size_nbr_hex(b);
	printf("Len: %d\n", a);
	printf("Orig hex: %x\n", b);

	printf("Poniter: %p\n", h);

	return (0);
}
