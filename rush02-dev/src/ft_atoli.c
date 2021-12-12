/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoui.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 08:46:02 by jthiele           #+#    #+#             */
/*   Updated: 2021/12/12 19:25:56 by tford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

long int	ft_atoli(char *string)
{
	int				i;
	long int	result;
	long int	sign;

	i = 0;
	result = 0;
	sign = 1;
	if (string[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (string[i])
	{
		while (string[i] >= '0' && string[i] <= '9' && string[i])
		{
			result *= 10;
			result += string[i] - '0';
			i++;
		}
		return (result * sign);
	}
	return (result);
}
