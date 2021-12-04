/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:29:02 by lxu               #+#    #+#             */
/*   Updated: 2021/12/04 11:04:44 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	string_okay(char *str)
{
	int	i;
	int	str_len;

	str_len = 0;
	while (str[str_len])
	{
		if (str[str_len] == '-' || str[str_len] == '+')
			return (-1);
		i = str_len + 1;
		while (str[i])
		{
			if (str[str_len] == str[i])
				return (-1);
			i++;
		}
		str_len++;
	}
	if (str_len <= 1)
		return (-1);
	return (str_len);
}

int	log_base(int nbr, int base)
{
	int	count;

	count = 0;
	while (nbr)
	{
		count++;
		nbr = nbr / base;
	}
	return (count);
}

int	exponent(int nbr, int exp)
{
	int	result;

	result = 1;
	while (exp)
	{
		result = result * nbr;
		exp--;
	}
	return (result);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			nbr_len;
	int			radix_size;
	int			digit_val;
	long int	nbr_l;

	if (nbr == 0)
		write(1, base, 1);
	radix_size = string_okay(base);
	if (radix_size == -1)
		return ;
	nbr_len = log_base(nbr, radix_size);
	if (nbr < 0)
	{
		nbr_l = (-1) * (long int)nbr;
		write(1, "-", 1);
	}
	else
		nbr_l = (long int)nbr;
	while (nbr_len)
	{
		digit_val = (nbr_l / exponent(radix_size, (nbr_len - 1))) % radix_size;
		write(1, &base[digit_val], 1);
		nbr_len--;
	}
}
