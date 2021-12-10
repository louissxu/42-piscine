/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoui.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 08:46:02 by jthiele           #+#    #+#             */
/*   Updated: 2021/12/11 09:02:51 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	atoui(char *string)
{
	int				i;
	unsigned int	result;

	i = 0;
	result = 0;
	if (string[i])
	{
		while (string[i] >= '0' && string[i] <= '9' && string[i])
		{
			result *= 10;
			result += string[i] - '0';
			i++;
		}
		if (string[i])
			result = 0;
	}
	return (result);
}
