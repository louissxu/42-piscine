#include <stdio.h>
#include "ft_iterative_power.c"

int main(void)
{
	printf("0^0 returns %d. Should be 1\n", ft_iterative_power(0, 0));
	printf("1^0 returns %d. Should be 1\n", ft_iterative_power(1, 0));
	printf("0^1 returns %d. Should be 0\n", ft_iterative_power(0, 1));
	printf("2^4 returns %d. Should be 16\n", ft_iterative_power(2, 4));
	printf("5^3 returns %d. Should be 125\n", ft_iterative_power(5, 3));
	printf("12^10 returns %d. Should be 61917364224 from the math. but behaviour should be undefined per specification\n", ft_iterative_power(12, 10));
	printf("-2^4 returns %d. Should be 16\n", ft_iterative_power(-2, 4));
	printf("-5^3 returns %d. Should be -125\n", ft_iterative_power(-5, 3));
	printf("2^-3 returns %d. Per specification, return should be 0\n", ft_iterative_power(2, -3));
	printf("3^-4 returns %d. Per specification, return should be 0\n", ft_iterative_power(3, -4));
}
