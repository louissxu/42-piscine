/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:03:19 by lxu               #+#    #+#             */
/*   Updated: 2021/12/01 23:05:37 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	long int	size;
	char		result[10];

	if (nb == 0)
		write(1, "0", 1);
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * -1;
	}
	size = 0;
	while (nb)
	{
		result[size] = '0' + (nb % 10);
		nb = nb / 10;
		size++;
	}	
	while (--size >= 0)
	{
		write(1, &result[size], 1);
	}
}
