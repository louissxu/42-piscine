/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_multiplier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:01:09 by lxu               #+#    #+#             */
/*   Updated: 2021/12/12 21:27:52 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	ft_print_multiplier(long int multiplier, t_dict *lut_dict)
{
	char	*word_ptr;

	if (multiplier == 1)
	{
		return ;
	}
	word_ptr = ft_dict_get(lut_dict, multiplier);
	ft_print_space();
	ft_putstr(word_ptr);
}
