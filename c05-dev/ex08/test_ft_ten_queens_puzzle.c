#include <stdio.h>
#include "ft_ten_queens_puzzle.c"

int main(void)
{
	int solution_count;

	solution_count = ft_ten_queens_puzzle();
	printf("The number of solutions is: %d\n", solution_count);
}
