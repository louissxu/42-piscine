/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking_logic1.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:44:13 by lxu               #+#    #+#             */
/*   Updated: 2021/12/05 22:53:19 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKTRACKING_LOGIC1_H
# define BACKTRACKING_LOGIC1_H

/*
 * Function: root
 * --------------
 * The root procedural parameter
 *
 * Generates the root node for the backtracking algorithm
 *
 * Takes the passed in grid and populates the sufficient number of cells with
 * null nodes. (For this implementation, zero is used to represent null/
 * unpopulated nodes)
 */

void	root(int *grid, int grid_size)
{
	int	i;

	i = 0;
	while (i < grid_size * grid_size)
	{
		grid[i] = 0;
		i++;
	}
}

/*
 * Function: reject
 * ---------------- 
 * Reject procedural parameter
 *
 * The reject function for the backtrcking algorithm.
 *
 * returns: True (1) only if the current state is a partial candidate not worth
 *          completing and should be early pruned. Ie it is in some way invalid.
 */
int	reject(int *grid, int grid_size, int *constraints)
{
	int	result;

	result = is_puzzle_solved(grid, grid_size, constraints);
	if (result == 0)
	{
		return (1);
	}
	return (0);
}

/*
 * Function: accept
 * ----------------
 * Accept procedural parameter
 *
 * The accept function for the backtracking algorithm.
 *
 * returns: True(1) if the solution is a solution for the constraints given.
 */
int	accept(int *grid, int grid_size, int *constraints)
{
	int	i;
	int	result;

	i = 0;
	while (i < grid_size * grid_size)
	{
		if (grid[i] == 0)
		{
			return (0);
		}
		i++;
	}
	result = is_puzzle_solved(grid, grid_size, constraints);
	return (result);
}

/*
 * Function: first
 * ---------------
 * First procedural parameter
 *
 * Generates the first extension of the current candidate. Ie it assumes the
 * curent position is good and adds another cell going deeper down this branch
 * of the tree
 * */
int	first(int *grid, int grid_size, int active_cell)
{
	if (active_cell == (grid_size * grid_size) - 1)
	{
		return (-1);
	}
	else
	{
		active_cell++;
		grid[active_cell]++;
		return (active_cell);
	}
}

/*
 * Function: next
 * --------------
 * Next procedural parameter
 *
 * Generates the next alternative candidate from the current position. Ie the
 * current position is bad so it goes sideways to the adjacent branch on the
 * tree.
 *
 * Once all branches at this level have been explored it returns -1 to signal
 * that there are no valid solutions left on this tree
 */
int	next(int *grid, int grid_size, int active_cell)
{
	if (grid[active_cell] >= grid_size)
	{
		grid[active_cell] = 0;
		return (-1);
	}
	else
	{
		grid[active_cell]++;
		return (active_cell);
	}
}

#endif
