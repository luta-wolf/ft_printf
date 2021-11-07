#include <stdio.h>

//ширина и точность для строки
int main()
{
	printf("{%s}\n", "hello world");
	printf("{%*s}\n", 21, "hello world");
	printf("{%*s}\n", 7, "hello world");
	printf("{%.*s}\n", 21, "hello world");
	printf("{%.*s}\n", 7, "hello world");
	printf("{%.*s}\n", 0, "hello world");
	printf("{%*.*s}\n", 21, 21, "hello world");
	printf("{%*.*s}\n\n", 21, 7, "hello world");

	printf("{%.*i}\n", 7, 123456789);
	return (0);
}
