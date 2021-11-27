#include <stdio.h>
#include "ft_div_mod.c"

int main(void)
{
	int div = 0;
	int mod = 0;
	ft_div_mod(14, 4, &div, &mod);
	printf("14/4 is 3 (div: %d) and remainder 2 (mod: %d)\n", div, mod);
}
