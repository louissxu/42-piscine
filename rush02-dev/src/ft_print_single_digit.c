/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_single_digit.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 12:03:41 by lxu               #+#    #+#             */
/*   Updated: 2021/12/12 21:28:07 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	ft_print_single_digit(long int num, int is_first_elem, t_dict *lut_dict)
{
	char	*word_ptr;

	if (num == 0)
	{
		return ;
	}
	word_ptr = ft_dict_get(lut_dict, num);
	if (is_first_elem == 0)
	{
		ft_print_space();
	}
	ft_putstr(word_ptr);
}
