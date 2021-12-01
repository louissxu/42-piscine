#include <stdio.h>
#include "ft_putnbr.c"

int main(void)
{
	int i1 = 0;
	printf("Testing: %d\n", i1);
	ft_putnbr(i1);
	printf("\n\n");

	int i2 = 512;
	printf("Testing: %d\n", i2);
	ft_putnbr(i2);
	printf("\n\n");

	int i3 = -1;
	printf("Testing: %d\n", i3);
	ft_putnbr(i3);
	printf("\n\n");

	int i4 = -123456789;
	printf("Testing: %d\n", i4);
	ft_putnbr(i4);
	printf("\n\n");

	int i5 = 2147483647;
	printf("Testing: %d\n", i5);
	ft_putnbr(i5);
	printf("\n\n");

	int i6 = -2147483648;
	printf("Testing: %d\n", i6);
	ft_putnbr(i6);
	printf("\n\n");
}
