/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking_logic2.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:45:06 by lxu               #+#    #+#             */
/*   Updated: 2021/12/05 19:45:59 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKTRACKING_LOGIC2_H
# define BACKTRACKING_LOGIC2_H

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
		return (1);
	else
		return (0);
}

int	bt_solve_puzzle(char *constraints_str)
{
	int	constraints[9 * 4];
	int	grid_size;
	int	grid[9 * 9];
	int	return_value;
	int	i;

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

#endif
