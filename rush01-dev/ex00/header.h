#include <stdio.h>
#include <unistd.h>
#define MAX_GRID_SIZE 4
/* Would use VLA, but not allowed by norm */

int print_state(int* grid, int grid_size, int* constraints, int active_cell)
{
	int i;
	
	printf("STATE - Grid Size: %d  Active Cell: %d  Grid: ", grid_size, active_cell);

	i = 0;
	while (i < grid_size * grid_size)
	{
		printf("%d ", grid[i]);
		i++;
	}

	printf(" Constraints: ");
	i = 0;
	while (i < grid_size * 4)
	{
		printf("%d ", constraints[i]);
		i++;
	}
	printf("\n");
	
	return (0);
}

int score_line(int *line, int line_length)
{
	int	i;
	int score;
	int max_seen;

	i = 0;
	score = 0;
	max_seen = 0;
	while (i < line_length)
	{
		if (line[i] > max_seen)
		{
			score++;
			max_seen = line[i];
		}
		i++;
	}
	return (score);
}

int score_line_min(int *line, int line_length)
{
	int i;
	int score;
	int max_seen;

	i = 0;
	score = 0;
	max_seen = 0;
	while (i < line_length)
	{
		if (line[i] == 0)
		{
			return (score);
		}
		if (line[i] > max_seen)
		{
			score++;
			max_seen = line[i];
		}
		i++;
	}
	return (score);
}

/* Fix:
 * Need to look into the zero values
 * For handling partial candidates to implement backtracking
 */
int valid_line(int *line, int line_length)
{
	int i;
	int j;

	i = 0; 
	while (i < line_length)
	{
		j = 0;
		while (j < i)
		{
			if ((line[j] == line[i]) && line[i] > 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/* Checks whether a line in the grid is valid
 * Param:
 * dir: 0 is up, 1 is down, 2 is left, 3 is right
 */
int check_line_dir(int* grid, int grid_size, int dir, int l_num, int l_val)
{
	int line[9];
	int i;
	int line_score;

	i = 0;
	while (i < grid_size)
	{
		if (dir == 0)
			line[i] = grid[l_num + (i * grid_size)];
		else if (dir == 1)
			line[i] = grid[(grid_size * (grid_size - i - 1)) + l_num];
		else if (dir == 2)
			line[i] = grid[(l_num * grid_size) + i];
		else
			line[i] = grid[((l_num + 1) * grid_size) - i - 1];	
		i++;
	}
	
	line_score = score_line_min(line, grid_size);
	if (line_score <= l_val && valid_line(line, grid_size) == 1)
	{
		return (1);
	}
	printf("Failing because line %d, in direction %d is not valid\n", l_num, dir);
	printf("It has constraint %d. but scored %d\n", l_val, line_score);
	printf("The line itself is: ");
	i = 0;
	while (i < grid_size)
	{
		printf("%d ", line[i]);
		i++;
	}
	printf("\n");	
	return (0);
}

int is_puzzle_invalid(int* grid, int grid_size, int* constraints)
{
	int i;
	int is_valid;
	
	i = 0;
	while (i < (grid_size * 4))
	{
		is_valid = check_line_dir(grid, grid_size, i/grid_size, i%grid_size, constraints[i]);
		if (is_valid == 0)
		{
			return (1);
		}
		i++;
	}
	
	return (0);
}

/* Checks if puzzle is solved according to provided constraints
 * Param:
 * constraints: a array of values. in same order as described in subject.pdf
 *     ups left to right, then
 *     downs left to right, then 
 *     lefts top to bottom, 
 *     then rights top to bottom
 */
int is_puzzle_solved(int* grid, int grid_size, int* constraints)
{
	int i;
	int is_valid;

	i = 0;
	while (i < (grid_size * 4))
	{
		is_valid = check_line_dir(grid, grid_size, i/grid_size, i%grid_size, constraints[i]);
		if (is_valid == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int bf_next(int* grid, int grid_size, int insert_location)
{
	int result;

	if (insert_location < 0)
	{
		return bf_next (grid, grid_size, (grid_size * grid_size) - 1);
	}
	if (grid[insert_location] == grid_size && insert_location == 0)
	{
		return (0);
	}
	if (grid[insert_location] == grid_size)
	{
		result = bf_next (grid, grid_size, insert_location - 1);
		if (result == (1))
		{
			grid[insert_location] = 1;
		}
		return (result);
	}
	else
	{
		grid[insert_location]++;
	}
	return (1);
}

int parse_constraints(int* constraints, char* constraint_str)
{
	int i;
	int grid_size;

	//parse constraints
	i = 0;
	while(*constraint_str)
	{
		if (*constraint_str == ' ')
		{
			constraint_str++;
		}
		else
		{
			constraints[i] = (int)*constraint_str - '0';
			constraint_str++;
			i++;
		}
	}
	grid_size = i / 4;

	return(grid_size);
}

int	bf_solve_puzzle(char *constraints_str)
{
	int return_value;
	int constraints[9*4];
	int i;
	int grid_size;
	//int grid[9*9];
	int grid[] = {1, 2, 3, 4,  1, 1, 1, 1,  1, 1, 1, 1,  1, 1, 1, 1};

	printf("Solving puzzle using brute force\n");
	grid_size = parse_constraints(constraints, constraints_str);
	
	//Populate empty grid
/*	
	i = 0;
	while (i < grid_size * grid_size)
	{
	grid[i] = 1;
	i++;
	}
*/	
	
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

int reject(int* grid, int grid_size, int* constraints)
{
	int result;
	result = is_puzzle_invalid(grid, grid_size, constraints);
	if (result)
	{
		return (1);
	}
	return (0);
}

int accept(int* grid, int grid_size, int* constraints)
{
	int i;
	int result;

	i = 0;
	while (i < grid_size * grid_size)
	{
		if (grid[i] == 0 )
		{
			return (0);
		}
		i++;
	}
	result = is_puzzle_solved(grid, grid_size, constraints);
	return (result);
}

int first(int* grid, int grid_size, int active_cell)
{
	if (active_cell == (grid_size * grid_size) - 1)
	{
		return (-1);
	}
	else
	{
		active_cell++;
		grid[active_cell]++;
		return active_cell;
	}
}

int next(int* grid, int grid_size, int active_cell)
{
	if (grid[active_cell] >= grid_size)
	{
		grid[active_cell] = 0;
		return (-1);
	}
	else
	{
		grid[active_cell]++;
		return active_cell;
	}
}

int bt_core(int* grid, int grid_size, int* constraints, int active_cell)
{	
	int solution_found;

	solution_found = 0;
	if (reject(grid, grid_size, constraints))
	{
		return (0);
	}
	if (accept(grid, grid_size, constraints))
	{
		printf("Solution found!\n");
		print_state(grid, grid_size, constraints, active_cell);
		return (1);
	}
	active_cell = first(grid, grid_size, active_cell);
	print_state(grid, grid_size, constraints, active_cell);
	while(active_cell > -1)
	{	
		solution_found = bt_core(grid, grid_size, constraints, active_cell);
		if (solution_found)
		{
			return(1);
		}
		active_cell = next(grid, grid_size, active_cell);
		print_state(grid, grid_size, constraints, active_cell);
	}		
	printf("Exiting this stack frame\n");	
	if (solution_found)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int bt_solve_puzzle(char *constraints_str)
{
	int constraints[9*4];
	int grid_size;
	int grid[9*9];
	//int grid[] = {1, 2, 3, 4,  2, 3, 4, 1,  1, 1, 1, 1,  1, 1, 1, 1};
	int return_value;
	int i;

	printf("Solving puzzle using backtracking\n");
	grid_size = parse_constraints(constraints, constraints_str);
	
	i = 0;
	while (i < grid_size * grid_size)
	{
		grid[i] = 0;
		i++;
	}

	return_value = bt_core(grid, grid_size, constraints, -1);
	return (return_value);
}



/* Lol, didn't need this
int sieve_simple_root(int dividend)
{
	int divisor;

	divisor = 1;

	while (divisor * divisor <= dividend)
	{
		if (dividend / divisor == divisor && dividend % divisor == 0)
		{
			return (divisor);
		}
		divisor++;
	}
	return (0);
}
*/
