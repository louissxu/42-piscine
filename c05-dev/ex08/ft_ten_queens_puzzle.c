/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:48:17 by lxu               #+#    #+#             */
/*   Updated: 2021/12/07 16:47:26 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int reject(int *state, int *active_cell)
{
	int i;

	i = 0;
	while (i < *active_cell)
	{
		if (state[i] == state[*active_cell])
		{
			//printf("rejecting: matching value present\n");
			return (1);
		}
		if (state[i] - state[*active_cell] == i - *active_cell || \
				state[i] - state[*active_cell] == *active_cell - i)
		{
			//printf("rejecting: diagonal match present\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int accept(int *state)
{
	int i;

	i = 0;
	while (i < 10)
	{
		if (state[i] < 0)
			return (0);
		if (reject(state, &i) == 1)
			return (0);
		i++;
	}
	//printf("accepting: passed all checks\n");
	return (1);
}

int first(int *state, int *active_cell)
{
	if (*active_cell >= 9)
		return (0);
	*active_cell += 1;
	state[*active_cell] = 0;
	return (1);
}

int next(int *state, int *active_cell)
{
	if (state[*active_cell] >= 9)
	{
		state[*active_cell] = -1;
		*active_cell -= 1;
		return (0);
	}
	state[*active_cell]++;
	return (1);
}

int output(int *state, int *solution_count)
{
	int i;
	int c;

	solution_count[0] += 1;
	c = '0';
	i = 0;
	while (i < 10)
	{
		if (state[i] < 0)
			write(1, "_", 1);
		else
		{
			c = '0' + state[i];
			write(1, &c, 1);
		
		}
		i++;
	}
	write(1, "\n", 1);
	return (1); 
}

int ten_queen_backtrack(int *solution, int *active_cell, int *solution_count)
{
	int more_solutions;

	more_solutions = 0;
	if (reject(solution, active_cell))
		return(0);
	if (accept(solution))
		output(solution, solution_count);
	more_solutions = first(solution, active_cell);
	//output(solution);
	while (more_solutions)
	{
		ten_queen_backtrack(solution, active_cell, solution_count);
		more_solutions = next(solution, active_cell);
		//output(solution); 
	}
	return (1);
}


int ft_ten_queens_puzzle(void)
{
	int solution[11];
	int i;
	int active_cell[1];
	int solution_count[1];

	i = 0;
	while (i < 10)
	{
		solution[i] = -1;
		i++;
	}
	active_cell[0] = -1;
	solution_count[0] = 0;
	ten_queen_backtrack(solution, active_cell, solution_count);
	return(solution_count[0]);

	//if reject
	//	return null
	//if accept
	//	add state
	//s <- first
	//while s
	//backtrack(s)
	//s <- next(s)

}
