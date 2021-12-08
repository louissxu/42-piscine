/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:22:26 by lxu               #+#    #+#             */
/*   Updated: 2021/12/08 12:07:23 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int i;

	if (min >= max)
	{
		return (NULL);
	}
	range = (int*)malloc((max - min) * sizeof(int));
	i = 0;
	while (i < (max - min))
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}
