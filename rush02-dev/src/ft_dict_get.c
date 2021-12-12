/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 12:11:19 by lxu               #+#    #+#             */
/*   Updated: 2021/12/12 22:43:23 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <stdlib.h>

char	*ft_dict_get(t_dict *lut_dict, long int num)
{
	while (lut_dict->value)
	{
		if (lut_dict->key == num)
		{
			return (lut_dict->value);
		}
		lut_dict++;
	}
	return (NULL);
}
