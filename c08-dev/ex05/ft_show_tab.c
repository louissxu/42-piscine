/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:35:47 by lxu               #+#    #+#             */
/*   Updated: 2021/12/13 22:52:53 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_putnl(void)
{
	write(1, "\n", 1);
}

void	ft_putint(int n)
{
	char	c;

	if (n < 0)
	{
		ft_putstr("error: negative value");
	}
	if (n > 9)
	{
		ft_putint(n / 10);
	}
	c = '0' + (n % 10);
	write(1, &c, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	while (par->str)
	{
		ft_putstr(par->str);
		ft_putnl();
		ft_putint(par->size);
		ft_putnl();
		ft_putstr(par->copy);
		ft_putnl();
		par++;
	}
}
