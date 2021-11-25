/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:37:06 by lxu               #+#    #+#             */
/*   Updated: 2021/11/25 20:00:52 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <stdio.h>

int	int_size(int num)
{
	int	size;

	size = 0;
	while (num > 0)
	{
		num = num / 10;
		size++;
	}
	return (size);
}

int	get_ith_digit(int num, int i)
{
	while (i > 0)
	{
		num = num / 10;
		i--;
	}
	num = num % 10;
	return (num);
}

char	single_int2char(int num)
{
	char	result;

	if (num > 9)
	{
		return ('0');
	}
	result = '0';
	result = result + num;
	return (result);
}

void	ft_putnbr(int nb)
{
	int		size;
	char	result_char;

	if (nb == 0)
	{
		write(1, "0", 1);
	}
	else if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb = nb * -1;
		}
		size = int_size(nb) + 1;
		while (--size > 0)
		{
			result_char = single_int2char(get_ith_digit(nb, size - 1));
			write(1, &result_char, 1);
		}
	}
}
