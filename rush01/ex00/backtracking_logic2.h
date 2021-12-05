/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking_logic2.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:45:06 by lxu               #+#    #+#             */
/*   Updated: 2021/12/05 22:59:17 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKTRACKING_LOGIC2_H
# define BACKTRACKING_LOGIC2_H

/*
 * Function: bt_core
 * -----------------
 * The core of the backtracking procedure.
 *
 * This function is used recursively to backtrack through the nodes of the tree
 * to be searched. See readme for more details.
 *
 * grid: The pointer to the grid which holds the board state.
 * grid_size: The width/height of the puzzle.
 * constraints: The pointer to the constraints array.
 * active cell: The current location where the state is being worked upon.
 *
 * returns: True (1) if successfuly finds solution.
 *          False (0) if no solution found.
 */
int	bt_core(int	*grid, int grid_size, int *constraints, int active_cell)
{	
	int	solution_found;

	solution_found = 0;
	if (reject(grid, grid_size, constraints))
		return (0);
	if (accept(grid, grid_size, constraints))
	{
		print_state_compliant(grid, grid_size);
		return (1);
	}
	active_cell = first(grid, grid_size, active_cell);
	while (active_cell > -1)
	{	
		solution_found = bt_core(grid, grid_size, constraints, active_cell);
		if (solution_found)
			return (1);
		active_cell = next(grid, grid_size, active_cell);
	}		
	if (solution_found)
	{
		return (1);
	}
	else
		return (0);
}

/*
 * Funcntion: bt_solve_puzzle
 * --------------------------
 * The entry function into the backtracking.
 *
 * Responsible to initialise the space in stack that will hold the grid as it is
 * being worked on. Also calls initialise then populates the constraints array
 * by calling calling the parser.
 *
 * Then starts backtracking by calling bt_core and returns the result back to
 * the caller of this function.
 *
 * constraints_str: The pointer to the start of the string of constraints to be
 *                  parsed.
 * returns: True (1) if successfully finds solution.
 *          False (0) if no solution found or error.
 */
int	bt_solve_puzzle(char *constraints_str)
{
	int	grid[9 * 9];
	int	constraints[9 * 4];
	int	grid_size;
	int	return_value;
	int	i;

	grid_size = parse_constraints(constraints, constraints_str);
	if (grid_size <= 0)
	{
		return (0);
	}
	i = 0;
	root(grid, grid_size);
	return_value = bt_core(grid, grid_size, constraints, -1);
	return (return_value);
}

#endif
