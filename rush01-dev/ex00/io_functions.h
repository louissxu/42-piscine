/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_functions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 19:46:45 by lxu               #+#    #+#             */
/*   Updated: 2021/12/05 19:46:58 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_FUNCTIONS_H
# define IO_FUNCTIONS_H

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

int	parse_constraints(int *constraints, char *constraint_str)
{
	int	i;
	int	grid_size;

	i = 0;
	while (*constraint_str)
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
	return (grid_size);
}

#endif
