#include <stdio.h>
#include "ft_swap.c"

int main(void)
{
	int a = 1;
	int b = 8;

	printf("The prior values of a: %d, b; %d\n", a, b);
	ft_swap(&a, &b);
	printf("The new values are  a: %d, b; %d\n", a, b);
}
