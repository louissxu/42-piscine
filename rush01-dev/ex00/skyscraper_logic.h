/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyscraper_logic.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:47:16 by lxu               #+#    #+#             */
/*   Updated: 2021/12/05 22:08:48 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SKYSCRAPER_LOGIC_H
# define SKYSCRAPER_LOGIC_H

int	score_line_min(int *line, int line_length)
{
	int	i;
	int	score;
	int	max_seen;

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

/* Checks whether a line is valid
 * 

	returns -1 if invalid (numbers clash)
	0 if could be valid (has a zero in the line)
	1 if valid (actual valid)

 */

int	valid_line(int *line, int line_length)
{
	int	i;
	int	j;

	i = 0;
	while (i < line_length)
	{
		j = 0;
		if (line[i] == 0)
		{
			return (0);
		}
		while (j < i)
		{
			if (line[j] == line[i])
				return (-1);
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
int	check_line_dir(int *grid, int grid_size, int constraint_num, int l_val)
{
	int	line[9];
	int	i;
	int	line_score;
	int	dir;
	int	l_num;

	dir = constraint_num / grid_size;
	l_num = constraint_num % grid_size;
	i = 0 - 1;
	while (++i < grid_size)
	{
		if (dir == 0)
			line[i] = grid[l_num + (i * grid_size)];
		else if (dir == 1)
			line[i] = grid[(grid_size * (grid_size - i - 1)) + l_num];
		else if (dir == 2)
			line[i] = grid[(l_num * grid_size) + i];
		else
			line[i] = grid[((l_num + 1) * grid_size) - i - 1];
	}
	line_score = score_line_min(line, grid_size);
	if ((valid_line(line, grid_size) == 0 && line_score <= l_val) || \
		(valid_line(line, grid_size) == 1 && line_score == l_val))
		return (1);
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
int	is_puzzle_solved(int *grid, int grid_size, int *constraints)
{
	int	i;
	int	is_valid;

	i = 0;
	while (i < (grid_size * 4))
	{
		is_valid = check_line_dir(grid, grid_size, i, constraints[i]);
		if (is_valid == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

#endif
