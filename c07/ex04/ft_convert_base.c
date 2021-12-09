/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:01:57 by lxu               #+#    #+#             */
/*   Updated: 2021/12/09 11:35:08 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			is_whitespace(char c);
int			check_base(char *base);
int			get_digit_value(char c, char *base);
long int	ft_atoi_base(char *str, char *base, int radix);

char	*ft_itoa_base_recursive(long int n, char *base, int radix)
{
	char	*result;
	int		len;

	if (n / radix == 0)
	{
		result = (char *)malloc(2 * sizeof(char));
		result[0] = base[n];
		result[1] = '\0';
		return (result);
	}
	result = ft_itoa_base_recursive(n / radix, base, radix);
	len = 0;
	while (result[len])
	{
		len++;
	}
	result = realloc(result, (len + 2) * sizeof(char));
	result[len] = base[n % radix];
	result[len + 1] = '\0';
	return (result);
}

char	*add_prefix_minus(char *nbr)
{
	int		nbr_len;
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

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int			radix_from;
	int			radix_to;
	long int	value;
	char		*result;

	radix_from = check_base(base_from);
	radix_to = check_base(base_to);
	if (radix_from == 0 || radix_to == 0)
		return (NULL);
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
