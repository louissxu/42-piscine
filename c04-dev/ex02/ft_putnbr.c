/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:03:19 by lxu               #+#    #+#             */
/*   Updated: 2021/12/02 22:07:44 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	int			size;
	char		result[10];
	long int	nb_l;

	if (nb == 0)
		write(1, "0", 1);
	nb_l = nb;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb_l = (long int)nb * -1;
	}
	size = 0;
	while (nb_l)
	{
		result[size] = '0' + (nb_l % 10);
		nb_l = nb_l / 10;
		size++;
	}	
	while (--size >= 0)
	{
		write(1, &result[size], 1);
	}
}
