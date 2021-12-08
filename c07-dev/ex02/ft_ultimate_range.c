/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:07:41 by lxu               #+#    #+#             */
/*   Updated: 2021/12/08 12:58:03 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>


#include <stdio.h>
int	ft_ultimate_range(int **range, int min, int max)
{
	int i;

	if (min >= max)
	{
		*range = NULL;
		return 0;
	}
	*range = (int*)malloc((max - min) * sizeof(int));
	i = 0;
	while (i < max - min)
	{
		*((*range) + i) = (min + i);
		i++;
	}
	return (i);
}
