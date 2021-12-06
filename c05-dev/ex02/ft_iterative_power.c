/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:11:43 by lxu               #+#    #+#             */
/*   Updated: 2021/12/06 13:22:35 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int pow)
{
	int result;

	result = 1;
	if (pow < 0)
	{
		return (0);
	}
	while(pow)
	{
		result = result * nb;
		pow--;
	}
	return (result);
}
