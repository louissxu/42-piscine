#include <stdio.h>
#include "ft_find_next_prime.c"

int main(void)
{
	int tests[6][2] = {{0, 3}, {4, 5}, {12, 13}, {13, 13}, {7907, 7907}, {7908, 7919}};

	printf("-------------------------------------------------\n");
	printf("Testing values, should return the next prime >= n\n");
	printf("-------------------------------------------------\n");
	for (size_t i = 0; i < sizeof(tests)/sizeof(tests[0]); i++)
	{
		printf("Testing: %d, Returns: %d. Correct: %d\n", tests[(int)i][0], ft_find_next_prime(tests[(int)i][0]), tests[(int)i][1]);
	}
}
