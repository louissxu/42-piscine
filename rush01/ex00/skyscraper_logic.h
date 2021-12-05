/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyscraper_logic.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:47:16 by lxu               #+#    #+#             */
/*   Updated: 2021/12/05 23:22:16 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SKYSCRAPER_LOGIC_H
# define SKYSCRAPER_LOGIC_H

/*
 * Function: score_line_min
 * ------------------------
 * Calculates the score of a line in a skyscraper.
 *
 * line: A array of the cells being viewed The cells are "viewed" from line[0]
 * to line[max].
 * line_length: To know max length of array.
 *
 * returns: The score that this arrangement would score.
 *
 * Note: Extra check was added to become score_line_min. It returns the
 * /minimum/ value possible so that it doesn't return a high value which might
 * cause a reject when the state is actually fine as it would be blocked later
 * by a high block.
 *
 * Eg, consider [0, 0, 2, 3] would score a 2,
 * but later when it becomes [4, 1, 2, 3] it scores a 1.
 *
 * Therefore, if an empty space (0) is encountered it assumes that this will be
 * filled by a high block and occlude everything behind it and therefore returns
 * the count thus far.
 */
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

/* 
 * Function: valid_line
 * --------------------
 * Checks whether a line is "valid" by it's merits alone.
 *
 * The checks it performs are:
 *   Whether there are any unfilled spaces (0) and,
 *   Whether there are any duplicates eg [1, 2, 4, 1] which are forbidden.
 *
 * line: An array of cells being "viewed" from line[0] to line[max].
 * line_length: The length of the line array.
 * 
 * returns: -1 If invalid (numbers clashing).
 *          0 For partial candidate (ie there is a zero in the line, therefore
 *          it /could/ be okay depending on how it's filled, but it isn't a
 *          valid *solution* line.
 *          1 Is valid (actually valid. so all cells are filled and no clashes).
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

/*
 * Function: check_line_dir
 * ------------------------
 * Checks whether a line is valid when given a entire grid and the location of
 * the line in the grid.
 *
 * grid: Pointer to the board state.
 * grid_size: The height/width of the grid.
 * constraint_num: Originally the line number (l_num) and direction (dir) were
 *                 passed in as parameters. But for norm reasons (too many args
 *                 this has been passed in as the constraint_num and the math
 *                 is performed here to get l_num and dir.
 * dir: The direction you are looking from encoded as follows.
 *   0 is from the top.
 *   1 is from the bottom.
 *   2 is from the left.
 *   3 is from thte right.
 * l_num: The line number of that side. Top and bottom are read left to right
 *        (book read). Left and right are numbered top to bottom.
 * l_val: The correct value of that view.
 *
 * returns: True (1) if that line is valid.
 *          False (0) if that line is invalid.
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

/*
 * Function: is_puzzle_solved
 * --------------------------
 * Checks if the puzzle is completely solved.
 *
 * Checks all the constraint views from all the lines by using check_line_dir.
 *
 * returns: True (1) if puzzle is solved.
 *          False (0) i the puzzle is not solved (if any of the lines are not
 *          valid as per check_line_dir).
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
