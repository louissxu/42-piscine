/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tommy_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tford <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 10:39:29 by tford             #+#    #+#             */
/*   Updated: 2021/12/12 21:58:15 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "rush.h"

int	ft_dict_handler_helper(int state_flag, char *c)
{
	if (state_flag == 1)
	{
		if (ft_is_numeric(*c))
			return (1);
		if (ft_is_space(*c))
			return (2);
		if (ft_is_colon(*c))
			return (3);
	}
	if (state_flag == 2)
	{
		if (ft_is_space(*c))
			return (2);
		if (ft_is_colon(*c))
			return (3);
	}
	if (state_flag == 3)
	{
		if (ft_is_space(*c))
			return (4);
		if (ft_is_printable(*c))
			return (5);
	}
	return (0);
}

int	ft_dict_handler(int state_flag, char *c)
{
	if (state_flag >= 1 && state_flag <= 3)
		return (ft_dict_handler_helper(state_flag, c));
	if (state_flag == 4)
	{
		if (ft_is_space(*c))
			return (4);
		if (ft_is_printable(*c))
			return (5);
	}
	if (state_flag == 5)
	{
		if (ft_is_printable(*c))
			return (5);
		if (ft_is_newline(*c))
			return (6);
	}
	if (state_flag == 6)
	{
		if ((ft_is_sign(*c) && ft_is_numeric(*(c + 1))) || ft_is_numeric(*c))
			return (1);
	}
	return (0);
}
