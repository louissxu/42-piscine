/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:01:57 by lxu               #+#    #+#             */
/*   Updated: 2021/12/10 12:29:53 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			is_whitespace(char c);
int			check_base(char *base);
int			get_digit_value(char c, char *base);
long int	ft_atoi_base(char *str, char *base, int radix);

int	memory_needed(long int val, int radix)
{
	int	char_count;

	char_count = 2;
	if (val < 0)
	{
		char_count++;
		val = val * (-1);
	}
	while (val / radix)
	{
		char_count++;
		val = val / radix;
	}
	return (char_count);
}

void	ft_itoa_base_recursive2(long int val, char *result, char *base, \
		int insert_location)
{
	int	digit_val;
	int	radix;

	radix = check_base(base);
	digit_val = val % radix;
	result[insert_location] = base[digit_val];
	if (val / radix)
		ft_itoa_base_recursive2(val / radix, result, base, insert_location - 1);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int			radix_from;
	int			radix_to;
	long int	value;
	char		*result;
	int			to_size;

	radix_from = check_base(base_from);
	radix_to = check_base(base_to);
	if (radix_from == 0 || radix_to == 0)
		return (NULL);
	value = ft_atoi_base(nbr, base_from, radix_from);
	to_size = memory_needed(value, radix_to);
	result = (char *)malloc(sizeof(char) * to_size);
	if (value < 0)
	{
		result[0] = '-';
		value = value * -1;
	}
	result[to_size - 1] = '\0';
	ft_itoa_base_recursive2(value, result, base_to, to_size - 2);
	return (result);
}
