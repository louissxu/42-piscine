/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_double_digit.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 12:43:39 by lxu               #+#    #+#             */
/*   Updated: 2021/12/12 14:25:55 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	ft_print_double_digit(long int num, int is_first_elem, t_dict *lut_dict)
{
	char		*word_ptr;
	long int	tens_value;
	long int	ones_value;

	if (num > 0 && num < 20)
	{
		word_ptr = ft_dict_get(lut_dict, num);
		if (is_first_elem == 0)
			ft_print_space();
		ft_putstr(word_ptr);
	}
	if (num >= 20)
	{
		tens_value = num / 10 * 10;
		word_ptr = ft_dict_get(lut_dict, tens_num);
		if (is_first_elem == 0)
			ft_print_space();
		putstr(word_ptr);
		is_first_elem = 0;
		ones_value = num % 10;
		ft_print_single_digit(ones_value, is_first_elem, lut_dict);
	}
}
