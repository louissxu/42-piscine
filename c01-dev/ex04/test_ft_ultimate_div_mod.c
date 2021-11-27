#include <stdio.h>
#include "ft_ultimate_div_mod.c"

int main(void)
{
	int a = 20;
	int b = 3;

	ft_ultimate_div_mod(&a, &b);
	printf("20/3 is quotient 6 (a: %d) and remainder 2 (b: %d)\n", a, b);
}
