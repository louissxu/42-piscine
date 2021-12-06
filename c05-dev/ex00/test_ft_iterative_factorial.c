#include <stdio.h>
#include "ft_iterative_factorial.c"

int main(void)
{
	int i = 0;

	while (i < 10)
	{
		printf("%c! is %d\n", i + '0', ft_iterative_factorial(i));
		i++;
	}
	printf("(-1)! is %d\n", ft_iterative_factorial(-1));
	printf("(-2)! is %d\n", ft_iterative_factorial(-2));
}
