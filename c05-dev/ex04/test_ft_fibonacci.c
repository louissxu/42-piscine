#include <stdio.h>
#include "ft_fibonacci.c"

int main(void)
{
	printf("Fibonacci -2 returns: %d. Should be: -1 (error return)\n", ft_fibonacci(-2));
	printf("Fibonacci -1 returns: %d. Should be: -1 (error return)\n", ft_fibonacci(-1));
	printf("Fibonacci 0 returns: %d. Should be: 0\n", ft_fibonacci(0));
	printf("Fibonacci 1 returns: %d. Should be: 1\n", ft_fibonacci(1));
	printf("Fibonacci 2 returns: %d. Should be: 1\n", ft_fibonacci(2));
	printf("Fibonacci 3 returns: %d. Should be: 2\n", ft_fibonacci(3));
	printf("Fibonacci 4 returns: %d. Should be: 3\n", ft_fibonacci(4));
	printf("Fibonacci 5 returns: %d. Should be: 5\n", ft_fibonacci(5));
	printf("Fibonacci 6 returns: %d. Should be: 8\n", ft_fibonacci(6));
	printf("Fibonacci 7 returns: %d. Should be: 13\n", ft_fibonacci(7));
	printf("Fibonacci 8 returns: %d. Should be: 21\n", ft_fibonacci(8));
	printf("Fibonacci 9 returns: %d. Should be: 34\n", ft_fibonacci(9));
}
