#include <stdio.h>

void ft_increase(int *y)
{
	*y *= 2;
	printf("y = %d\n", *y);
}

int main()
{
	int x = 10;

	ft_increase(&x);
	printf("x = %d\n", x);

	return 0;
}
