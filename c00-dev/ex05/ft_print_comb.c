/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:25:16 by lxu               #+#    #+#             */
/*   Updated: 2021/11/24 21:27:11 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void ft_print_comb(void)
{
	char numbers[10];
	char zero = '0';
	char spacer[2];
	for(int i = 0; i <= 9; i++)
	{
		numbers[i] = zero;
		zero++;
	}
	spacer[0] = ',';
	spacer[1] = ' ';

	for(int i = 0; i <= 7; i++)
	{
		for(int j = (i+1); j<=8; j++)
		{
			for(int k=(j+1); k<=9; k++)
			{
				write(1, &numbers[i], 1);
				write(1, &numbers[j], 1);
				write(1, &numbers[k], 1);
				if (i != 7)
				{
					write(1, &spacer, sizeof(spacer));
				}
			}
		}
   	}
}

