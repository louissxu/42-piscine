/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 02:19:24 by lxu               #+#    #+#             */
/*   Updated: 2021/11/29 02:20:10 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_printable(char c)
{
	if (c < ' ' || c > '~')
	{
		return (0);
	}
	return (1);
}

char	int_to_hex_char(int num)
{
	if (num >= 0 && num <= 9)
		return ('0' + num);
	else if (num < 16)
		return ('a' + num - 10);
	else
		return ('!');
}

void	print_escaped_char(char c)
{
	char	char_to_print;

	write(1, "\\", 1);
	char_to_print = int_to_hex_char((0 + c) / 16);
	write(1, &char_to_print, 1);
	char_to_print = int_to_hex_char((0 + c) % 16);
	write(1, &char_to_print, 1);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (is_printable(*str))
		{
			write(1, str, 1);
		}
		else
		{
			print_escaped_char(*str);
		}
	str++;
	}	
}
