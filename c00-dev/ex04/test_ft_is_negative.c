#include "ft_is_negative.c"
#include <stdio.h>

void ft_is_negative(int n);

int main(void)
{
	printf(">>ft_is_negative(-5)\n");
	ft_is_negative(-5);
	printf("\n");
	printf(">>ft_is_negative(2)\n");
	ft_is_negative(2);
	printf("\n");
	printf(">>ft_is_negative(0)\n");
	ft_is_negative(0);
	printf("\n");
}
