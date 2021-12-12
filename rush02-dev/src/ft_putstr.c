/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 11:24:06 by lxu               #+#    #+#             */
/*   Updated: 2021/12/12 12:02:29 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <unistd.h>

void	ft_putstr(char *str)
{
	while(*str)
	{
		ft_putchar(*str);
		str++;	
	}
}

