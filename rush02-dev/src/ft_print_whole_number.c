/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_whole_number.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:31:43 by lxu               #+#    #+#             */
/*   Updated: 2021/12/12 14:34:22 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_print_whole_number(long int num, t_dict *lut_dict)
{
	char	*word_ptr;

	if (number == 0)
	{
		word_ptr = ft_dict_get(lut_dict, num);
		ft_putstr(word_ptr);
		return (0);
	}
	if (number < 0)
	{
		ft_print_negative();
		number = number * -1;
	}
	ft_process_triplet(num, 1, 1, lut_dict);
	ft_putstr("\n");
}
