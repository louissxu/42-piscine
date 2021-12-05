/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_functions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:46:45 by lxu               #+#    #+#             */
/*   Updated: 2021/12/05 23:23:34 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_FUNCTIONS_H
# define IO_FUNCTIONS_H

/*
 * Function: print_state_compliant
 * -------------------------------
 * Outputs to stdio the passed in grid printed as a square.
 *
 * This is specification compliant as opposed to a previous non-compliant print.
 *
 * grid: Pointer to the start of the array holding all the grid values.
 * grid_size: Width and height of the puzzle.
 */
void	print_state_compliant(int *grid, int grid_size)
{
	int		i;
	char	c;

	i = 0;
	while (i < grid_size * grid_size)
	{
		c = '0' + grid[i];
		write(1, &c, 1);
		if ((i + 1) % grid_size == 0)
		{
			write(1, "\n", 1);
		}
		else
		{
			write(1, " ", 1);
		}
		i++;
	}
}

/*
 * Function: parse_constraints
 * ---------------------------
 * Parses an input string and pokes the values into a constraints array passed
 * in to it.
 *
 * constraints: Previously initialised array to store the constraints. Has
 *              sufficient size to hold the constraints up to a size 9 puzzle.
 * constraint_str: Passed in str to parse. Str is expected to have single digits
 *                 representing each constraint. They can be separated by spaces.
 *
 *                 ie: constraints_str = "4 3 2 1 1 2 2 ..."
 *                 and is parsed into an array containing these values as ints
 *                 ie:
 *                 int constraints[] = {4, 3, 2, 1, 1, 2, 2, ...}
 *
 *                 The order of the values is as discussed in the
 *                 skyscraper_backtracking_solver.h file and adheres to the same
 *                 conventions.
 *
 * returns: The grid size if the string was valid to parse (ie constraints / 4).
 *          If it was not valid, returns -1 as error code.
 *
 * Extra sanity checks on the passed in string performed at the bottom
 * If fails, returns -1 error code.
 * Checks that the constraints is a multiple of 4.
 * Checks that all the constraints are in range:
 *   0 <= constraint[i] <= grid_size
 */
int	parse_constraints(int *constraints, char *constraint_str)
{
	int	i;
	int	grid_size;

	i = 0;
	while (*constraint_str)
	{
		if (*constraint_str == ' ')
			constraint_str++;
		else
		{
			constraints[i] = (int)*constraint_str - '0';
			constraint_str++;
			i++;
		}
	}
	grid_size = i / 4;
	if (grid_size * 4 != i)
		return (-1);
	i = 0 - 1;
	while (++i < grid_size * 4)
	{
		if (constraints[i] < 0 || constraints[i] > grid_size)
			return (-1);
	}
	return (grid_size);
}

/*
# include <stdio.h>
*/

/*
 * Function: print_state
 * ---------------------
 * Prints the current state passed into it as a single line. Primarily for
 * debuging use.
 *
 * grid: Grid in standard format (see readme).
 * grid_size: The size of the grid (width and height).
 * constraints: Pointer to the list of constraints.
 * active_cell: The active cell where insertions/updates are being made.
 */

/*
int	print_state(int *grid, int grid_size, int *constraints, int active_cell)
{
	int	i;

	printf("STATE - Grid Size: %d  Active Cell: %d  Grid: ", \
			grid_size, active_cell);
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
*/

#endif
