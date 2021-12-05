#include "header.h"
#include <stdio.h>

int main(void)
{
	int line[] = {3,4,1,2};

	printf("Returned value was: %d\n", score_line(line, 4));

	int grid[] = {1,2,3,4, 2,0,4,5, 3,4,5,6, 4,5,7,6};
	printf("Returned value was %d\n", check_line_dir(grid, 4, 0, 1, 3));

	int grid1[] = {2,1,1,2};
	printf("The returned value was: %d\n", bf_next(grid1, 2, -1));
	int i = 0;
	while (i < 4)
	{
		printf("The returned vale at %d is %d\n", i, grid1[i]);
		i++;
	}
}
