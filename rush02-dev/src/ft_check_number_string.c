/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_number_string.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 20:28:15 by lxu               #+#    #+#             */
/*   Updated: 2021/12/12 22:52:18 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	ft_check_number_string(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
	{
		i++;
	}
	if (ft_is_numeric(str[i]) == 0)
	{
		return (0);
	}
	while (str[i])
	{
		if (ft_is_numeric(str[i]) == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
