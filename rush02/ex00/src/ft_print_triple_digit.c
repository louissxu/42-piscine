/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_triple_digit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 13:28:25 by lxu               #+#    #+#             */
/*   Updated: 2021/12/12 21:28:33 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	ft_print_triple_digit(long int num, int is_first_elem, t_dict *lut_dict)
{
	char		*word_ptr;
	long int	num_part;

	if (num >= 100)
	{
		if (is_first_elem == 0)
			ft_print_comma();
		num_part = num / 100 * 100;
		ft_print_single_digit(num_part / 100, is_first_elem, lut_dict);
		num_part = 100;
		word_ptr = ft_dict_get(lut_dict, num_part);
		ft_print_space();
		ft_putstr(word_ptr);
		is_first_elem = 0;
	}
	num_part = num % 100;
	if (num_part)
	{
		if (is_first_elem == 0)
		{
			ft_print_space();
			ft_putstr("and");
		}
		ft_print_double_digit(num_part, is_first_elem, lut_dict);
	}
}
