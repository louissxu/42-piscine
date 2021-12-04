#include <stdio.h>
#define MAX_GRID_SIZE 4
/* Would use VLA, but not allowed by norm */

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

int valid_line(int *line, int line_length)
{
	int i;
	int j;

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

/* Checks whether a line in the grid is valid
 * Param:
 *
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
	line_score = score_line(line, grid_size);
	if (line_score == l_val)
	{
		return (1);
	}
	return (0);
}

/*
int is_puzzle_valid(int* grid, int grid_size)
{
	//check rights, lefts, ups, downs
}
*/

int	solve_puzzle(char **argv)
{
	printf("Hello world");
	argv++;
	return (0);
}

