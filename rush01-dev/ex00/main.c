/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 18:47:18 by lxu               #+#    #+#             */
/*   Updated: 2021/12/05 18:47:56 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(2, "Usage ./solve_puzzle \"<constraints\"", 20);
		return (1);
	}
	bt_solve_puzzle(argv[1]);
	return (0);
}
