#include <stdio.h>
#include "ft_ultimate_range.c"

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
	int a = 5;
	int* b = &a;
	int** r0 = &b;
	printf("Range's pointer (before): %p\n", *r0);
	int r0_size = ft_ultimate_range(r0, 5, 1);
	printf("Size of range (return val - should be 0): %d\n", r0_size);
	printf("Range's pointer (after - should be 0x0): %p\n", *r0);
	print_range(*r0, r0_size);

	printf("--------------------\n");
	printf("Checking range(1, 5)\n");
	int* r1p = NULL;
	int** r1 = &r1p;
	int r1_size = ft_ultimate_range(r1, 1, 5);
	printf("Size of range (return val): %d\n", r1_size);
	printf("Range's pointer: %p\n", *r1);
	print_range(*r1, r1_size);

	printf("--------------------\n");
	printf("Checking range(-2, 4)\n");
	int* r2p = NULL;
	int** r2 = &r2p;
	int r2_size = ft_ultimate_range(r2, -2, 4);
	printf("Size of range (return val): %d\n", r2_size);
	printf("Range's pointer: %p\n", *r2);
	print_range(*r2, r2_size);

	printf("--------------------\n");
	printf("Checking range(-100, -90)\n");
	int* r3p = NULL;
	int** r3 = &r3p;
	int r3_size = ft_ultimate_range(r3, -100, -90);
	printf("size of range (return val): %d\n", r3_size);
	printf("Range's pointer: %p\n", *r3);
	print_range(*r3, r3_size);

	free(*r0);
	free(*r1);
	free(*r2);
	free(*r3);
}
