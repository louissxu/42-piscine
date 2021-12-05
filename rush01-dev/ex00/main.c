#include "header.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	int return_value;
	int constraints[9*9];
	int i;
	int grid_size;

	if (argc != 2)
	{
		write(2, "Usage ./solve_puzzle \"<constraints>\"", 20);
		return (1);
	}

	//parse constraints
	i = 0;
	while(*argv[1])
	{
		if (*argv[1] == ' ')
		{
			argv[1]++;
		}
		else
		{
			constraints[i] = (int)*argv[1] - '0';
			argv[1]++;
			i++;
		}
	}
	grid_size = i / 4;
	printf("number of constraints is %d\n", i);
	printf("the constraints list is:\n");
	printf("the grid size is %d\n", grid_size);
	i = 0;
	while (i < grid_size * 4)
	{
		printf("constraint[%d]: %d,\n", i, constraints[i]);
		i++;
	}	

	//return_value = solve_puzzle(argv[1]);
	return_value = 0;
	return (return_value);
}
