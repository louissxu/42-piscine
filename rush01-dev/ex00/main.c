/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 18:47:18 by lxu               #+#    #+#             */
/*   Updated: 2021/12/06 00:37:38 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "skyscraper_backtracking_solver.h"

int	main(int argc, char **argv)
{
	int	return_value;

	if (argc != 2)
	{
		write(2, "Usage ./solve_puzzle \"<constraints>\"\n", 37);
		return (1);
	}
	return_value = bt_solve_puzzle(argv[1]);
	if (return_value == 1)
	{
	}
	else
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}
