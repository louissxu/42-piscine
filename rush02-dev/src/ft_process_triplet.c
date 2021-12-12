/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_triplet.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:07:08 by lxu               #+#    #+#             */
/*   Updated: 2021/12/12 14:12:50 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	ft_process_triplet(long int num, long int multiplier, \
		int is_first_elem, t_dict *lut_dict)
{
	long int	num_part;

	if (num >= 1000)
	{
		ft_process_triplet(num / 1000, multiplier * 1000, \
				is_first_elem, lut_dict);
		is_first_elem = 0;
	}
	num_part = num % 1000;
	if (num_part > 0)
	{
		ft_print_triple_digit(num_part, is_first_elem, lut_dict);
		ft_print_multiplier(multiplier, lut_dict);
	}
}
