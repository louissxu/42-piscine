#include "header.h"
#include <stdio.h>

int main(void)
{
	int line[] = {3,4,1,2};

	printf("Returned value was: %d\n", score_line(line, 4));

	int grid[] = {1,2,3,4, 2,3,4,5, 3,4,5,6, 4,5,7,6};
	printf("Returned value was %d\n", check_line_dir(grid, 4, 1, 1, 2));
}
