/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking_logic1.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:44:13 by lxu               #+#    #+#             */
/*   Updated: 2021/12/05 19:44:47 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKTRACKING_LOGIC1_H
# define BACKTRACKING_LOGIC1_H

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
