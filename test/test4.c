#include <stdio.h>

int ft_sum(int x, int y)
{
	int sum;

	sum = x + y;
	return (sum);
}

int main(int argc, char const *argv[])
{
	int a = 2;
	int b = 3;
	int s;

	s = ft_sum(a, b);
	printf("%d\n", s);
	return 0;
}

