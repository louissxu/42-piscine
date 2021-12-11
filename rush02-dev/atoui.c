/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoui.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthiele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 08:46:02 by jthiele           #+#    #+#             */
/*   Updated: 2021/12/11 16:37:40 by tford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

//cum loop fix
unsigned int	atoui(char *string)
{
	int				i;
	unsigned int	result;

	i = 0;
	result = 0;
	if (*string)
	{
		while (*string >= '0' && *string <= '9' && *string)
		{
			result *= 10;
			result += *string - '0';
			string++;
		}
		if (*string)
		{
			result = 0;
		}
	}
	return (result);
}
