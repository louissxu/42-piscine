/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:01:57 by lxu               #+#    #+#             */
/*   Updated: 2021/12/08 20:10:29 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int is_whitespace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || \
		   c == '\r' || c == ' ')
	{
		return (1);
	}
	return (0);
}

int check_base(char *base)
{
	int size;
	int i;

	size = 0;
	while (base[size])
	{
		if (base[size] == '+' || base[size] == '-')
		{
			return (0);
		}
		if (is_whitespace(base[size]))
		{
			return (0);
		}
		i = 0;
		while (i < size)
		{
			if (base[size] == base[i])
			{
				return (0);
			}
			i++;
		}
		size++;
	}
	if (size <= 1)
	{
		return (0);
	}
	return (size);
}

int get_digit_value(char c, char *base)
{
	int i;
	
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
	int is_positive;
	long int result;

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

char *ft_itoa_base_recursive(long int n, char *base, int radix)
{
	char *result;
	int len;

	if (n / radix == 0)
	{
		result = (char*)malloc(2 * sizeof(char));
		result[0] = base[n];
		result[1] = '\0';
		return (result);
	}
	result = ft_itoa_base_recursive(n/radix, base, radix);
	len = 0;
	while (result[len])
	{
		len++;
	}
	result = realloc(result, (len+2) * sizeof(char));
	result[len] = base[n % radix];
	result[len + 1] = '\0';
	return (result);
}

char *add_prefix_minus(char *nbr)
{
	int nbr_len;
	char	*result;

	nbr_len = 0;
	while (nbr[nbr_len])
	{
		nbr_len++;
	}
	result = realloc(nbr, (nbr_len + 2));
	while (nbr_len >= 0)
	{
		result[nbr_len + 1] = result[nbr_len];
		nbr_len--;
	}
	result[0] = '-';
	return (result);
}

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int radix_from;
	int radix_to;
	long int value;
	char *result;

	radix_from = check_base(base_from);
	radix_to = check_base(base_to);
	if (radix_from == 0 || radix_to == 0)
	{
		return (NULL);
	}
	value = ft_atoi_base(nbr, base_from, radix_from);

	if (value == 0)
	{
		result = malloc(2 * sizeof(char));
		result[0] = base_to[0];
		result[1] = '\0';
		return (result);
	}
	if (value > 0)
	{
		result = ft_itoa_base_recursive(value, base_to, radix_to);
		return (result);
	}
	result = ft_itoa_base_recursive(value * -1, base_to, radix_to);
	result = add_prefix_minus(result);
	return (result);
}


