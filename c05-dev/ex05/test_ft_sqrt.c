#include <stdio.h>
#include "ft_sqrt.c"

int main(void)
{
	printf("Sqrt -10 returns: %d. Should be: 0 (per specification return 0 if irrational root)\n", ft_sqrt(-10));
	printf("Sqrt 0 returns: %d. Should be 0\n", ft_sqrt(0));
	printf("Sqrt 3 returns: %d. Should be 0 (per specification, only looking for perfect roots)\n", ft_sqrt(0));
	printf("Sqrt 4 returns: %d. Should be 2\n", ft_sqrt(4));
	printf("Sqrt 81 returns: %d. Should be 9\n", ft_sqrt(81));
	printf("Sqrt 144 returns: %d. Should be 12\n", ft_sqrt(144));
	printf("Sqrt 2147395600 returns: %d. Should be 46340 (largest pefect squre < MAX_INT)\n", ft_sqrt(2147395600));
}
