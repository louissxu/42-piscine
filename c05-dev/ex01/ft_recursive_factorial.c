/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:08:02 by lxu               #+#    #+#             */
/*   Updated: 2021/12/07 16:54:22 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	result;

	if (nb < 0)
	{
		return (0);
	}
	result = 0;
	if (nb == 0)
	{
		return (1);
	}
	return (ft_recursive_factorial(nb - 1) * nb);
}
