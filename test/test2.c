#include <stdio.h>

int f2(int j)
{
	j = 110;
	return (j);
}

void f1(int j)
{
	j = 100;
}

void f3(int *i)
{
	*i = *i * 2; // i - адрес памяти
}

int main()
{
	int i;

	i = 5;
	f1(i);
	printf("%d\n", i);
	i = f2(i);
	printf("%d\n", i);
	f3(&i);
	printf("%d\n", i);
	return (0);
}
