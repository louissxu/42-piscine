/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:01:57 by lxu               #+#    #+#             */
/*   Updated: 2021/12/09 11:32:08 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_whitespace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || \
		c == '\r' || c == ' ')
	{
		return (1);
	}
	return (0);
}

int	check_base(char *base)
{
	int	size;
	int	i;

	size = 0;
	while (base[size])
	{
		if (base[size] == '+' || base[size] == '-')
			return (0);
		if (is_whitespace(base[size]))
			return (0);
		i = 0;
		while (i < size)
		{
			if (base[size] == base[i])
				return (0);
			i++;
		}
		size++;
	}
	if (size <= 1)
		return (0);
	return (size);
}

int	get_digit_value(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

long int	ft_atoi_base(char *str, char *base, int radix)
{
	int			is_positive;
	long int	result;

	while (*str && is_whitespace(*str))
	{
		str++;
	}
	is_positive = 1;
	while (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
		{
			is_positive = is_positive * -1;
		}
		str++;
	}
	result = 0;
	while (*str && (get_digit_value(*str, base) != -1))
	{
		result = result * radix;
		result = result + get_digit_value(*str, base);
		str++;
	}
	result = result * is_positive;
	return (result);
}
