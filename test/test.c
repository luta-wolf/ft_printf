#include <stdio.h>

void ft_printf(char **str)
{
	*str = "CDF";

}


int main()
{
//	int a = 10;
	char *c = "ABC";

	//printf("%d\n", );

	ft_printf(&c);
	printf("%s\n", c);
	return (0);
}
