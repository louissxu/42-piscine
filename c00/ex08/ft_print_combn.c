/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 00:46:25 by lxu               #+#    #+#             */
/*   Updated: 2021/11/26 00:56:09 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	increment_digit(char *ijk, int position, int n)
{
	ijk[position] += 1;
	if (ijk[position] > ('9' - (n - position - 1)))
	{
		if (position == 0)
		{
			ijk[position] = 'x';
		}
		else
		{
			increment_digit(ijk, position - 1, n);
			ijk[position] = ijk[position - 1] + 1;
		}
	}
}

void	increment_number(char *ijk, int n)
{
	increment_digit(ijk, n - 1, n);
}

void	ft_print_combn(int n)
{
	char	ijk[10];
	int		counter;

	if (n == 0)
		return ;
	counter = 0 - 1;
	while (++counter < n)
		ijk[counter] = '0' + counter;
	while (ijk[0] != 'x')
	{
		write(1, &ijk, n);
		increment_number(ijk, n);
		if (ijk[0] != 'x')
			write(1, ", ", 2);
	}
}
