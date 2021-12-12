/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_special_number.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:34:47 by lxu               #+#    #+#             */
/*   Updated: 2021/12/12 23:27:15 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	ft_print_special_number(long int num, t_dict *lut_dict)
{
	char	*word_ptr;

	word_ptr = ft_dict_get(lut_dict, num);
	if (word_ptr)
	{
		ft_putstr(word_ptr);
		ft_print_newline();
		return (1);
	}
	return (0);
}
