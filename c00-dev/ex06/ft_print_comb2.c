/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:43:30 by lxu               #+#    #+#             */
/*   Updated: 2021/11/28 18:39:24 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	increment_number(char *ptr_num)
{	
	if (ptr_num[1] < '9')
	{
		ptr_num[1]++;
	}
	else
	{
		ptr_num[1] = '0';
		ptr_num[0]++;
	}
}

void	print_number(char *big_num, char *small_num)
{
	write(1, big_num, 2);
	write(1, " ", 1);
	write(1, small_num, 2);
	if (! (big_num[0] >= '9' && big_num[1] >= '8' && \
		small_num[0] >= '9' && small_num[1] >= '9'))
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	char	small_num[2];
	char	big_num[2];

	small_num[0] = '0';
	small_num[1] = '0';
	big_num[0] = '0';
	big_num[1] = '0';
	while ((big_num[0] < '9') || (big_num[0] <= '9' && big_num[1] <= '8'))
	{
		small_num[0] = big_num[0];
		small_num[1] = big_num[1];
		increment_number(small_num);
		while (small_num[0] <= '9')
		{
			print_number(big_num, small_num);
			increment_number(small_num);
		}
		increment_number(big_num);
	}
}
