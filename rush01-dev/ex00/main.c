#include "header.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	int return_value;
	int constraints[9*4];
	int i;
	int grid_size;
	int grid[9*9];
	//int grid[] = {1, 2, 3, 4,  2, 3, 4, 1,  1, 1, 1, 1,  1, 1, 1, 1};

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

	i = 0;
	while (i < grid_size * grid_size)
	{
	grid[i] = 1;
	i++;
	}
	
	int is_solved = is_puzzle_solved(grid, grid_size, constraints);	
	int checked_everything;
	while (is_solved != 1)
	{
		checked_everything = bf_next(grid, grid_size, -1);
		if (checked_everything == 0)
		{
			write (1, "There is no valid solution to these constraints\n", 48);
			return (0);
		}
		i = 0;
		printf("Checking: ");
		while (i < grid_size * grid_size)
		{
			printf("%d ", grid[i]);
			i++;
		}
		printf("\n");
		is_solved = is_puzzle_solved(grid, grid_size, constraints);
	}
	i = 0;
	write(1, "Solution found!", 10);
	while (i < grid_size * grid_size)
	{
		printf("%d, ", grid[i]);
		i++;
	}
	
	//return_value = solve_puzzle(argv[1]);
	return_value = 0;
	return (return_value);
}
