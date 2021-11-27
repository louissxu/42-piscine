/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 22:39:34 by lxu               #+#    #+#             */
/*   Updated: 2021/11/27 22:54:33 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	counter;

	counter = 0;
	while (counter < size / 2)
	{
		temp = tab[counter];
		tab[counter] = tab[size - 1 - counter];
		tab[size - 1 - counter] = temp;
		counter++;
	}
}
