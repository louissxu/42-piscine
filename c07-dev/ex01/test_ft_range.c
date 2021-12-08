#include <stdio.h>
#include "ft_range.c"

void print_range(int* range, int size)
{
	printf("[");
	int i = 0;
	while (i < size)
	{
		printf("%d", range[i]);
		if (i != size -1)
		{
			printf(", ");
		}
		i++;

	}
	printf("]\n");
}

int main(void)
{
	printf("--------------------\n");
	printf("Checking invalid range returns null pointer (0x0)\n");
	printf("%p\n", ft_range(5, 1));
	print_range(ft_range(5, 1), 0);

	printf("--------------------\n");
	printf("Checking range(1, 5)\n");
	int* r1 = ft_range(1,5);
	printf("%p\n", r1);
	print_range(r1, 5 - 1);

	printf("--------------------\n");
	printf("Checking range(-2, 4)\n");
	int* r2 = ft_range(-2, 4);
	printf("%p\n", r2);
	print_range(r2, 4 - -2);

	printf("--------------------\n");
	printf("Checking range(-100, -90)\n");
	int* r3 = ft_range(-100, -90);
	printf("%p\n", r3);
	print_range(r3, -90 - -100);

	free(r1);
	free(r2);
	free(r3);
}
