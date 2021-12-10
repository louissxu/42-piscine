#include <stdio.h>
#include "ft_is_prime.c"

int main(void)
{
	int not_primes[] = {0, 1, 4, 6, 8, 9, 12, 50, 100, 9999};
	int primes[] = {2, 3, 5, 7, 11, 13, 17, 223, 2777, 4127};

	printf("--------------------------------------\n");
	printf("Testing not primes. Return should be 0\n");
	printf("--------------------------------------\n");
	for (size_t i = 0; i < sizeof(not_primes)/sizeof(not_primes[0]); i++)
	{
		printf("Testing: %d. Returns: %d\n", not_primes[i], ft_is_prime(not_primes[i]));
	}

	printf("----------------------------------\n");
	printf("Testing primes. Return should be 1\n");
	printf("----------------------------------\n");
	for (size_t i = 0; i < sizeof(primes)/sizeof(primes[0]); i++)
	{
		printf("Testing: %d. Returns: %d\n", primes[i], ft_is_prime(primes[i]));
	}
}
