/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 21:06:35 by lxu               #+#    #+#             */
/*   Updated: 2021/12/02 18:29:51 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);

int	simple_atoi(char *str)
{
	int	val;

	val = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (-1);
		val = val * 10;
		val = val + (*str - '0');
		str++;
	}
	return (val);
}

int	main(int argc, char **argv)
{
	int	x;
	int	y;

	if (argc != 3)
	{
		write(2, "Usage: ./a.out num_columns num_rows\n", 35);
		return (1);
	}
	else
	{
		x = simple_atoi(argv[1]);
		y = simple_atoi(argv[2]);
		if (x == -1 || y == -1)
		{
			write(2, "Error: Inputs are not numbers\n", 30);
			return (1);
		}
		else
			rush(x, y);
	}
	return (0);
}
