/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:56:16 by lxu               #+#    #+#             */
/*   Updated: 2021/12/06 12:52:34 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_whitespace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || \
			c == '\f' || c == '\r' || c == ' ')
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
		if (base[size] == '-' || base[size] == '+')
			return (-1);
		if (is_whitespace(base[size]))
			return (-1);
		i = size + 1;
		while (base[i])
		{
			if (base[size] == base[i])
				return (-1);
			i++;
		}
		size++;
	}
	if (size <= 1)
		return (-1);
	return (size);
}

int	char_to_val(char c, char *base)
{
	int	count;

	count = 0;
	while (base[count])
	{
		if (base[count] == c)
		{
			return (count);
		}
		count++;
	}
	return (-1);
}

int	core_atoi_base(char *str, char *base, int radix)
{
	int	digit;
	int	value;

	value = 0;
	while (*str)
	{
		digit = char_to_val(*str, base);
		if (digit < 0)
		{
			return (value);
		}
		value = value * radix;
		value = value + digit;
		str++;
	}
	return (value);
}

int	ft_atoi_base(char *str, char *base)
{
	int	radix;
	int	i;
	int	is_positive;

	radix = check_base(base);
	i = 0;
	is_positive = 1;
	if (radix == -1)
		return (0);
	while (str[i] && is_whitespace(str[i]))
		i++;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			is_positive = is_positive * (-1);
		i++;
	}
	if (str[i])
		return (core_atoi_base(&str[i], base, radix) * is_positive);
	return (0);
}
