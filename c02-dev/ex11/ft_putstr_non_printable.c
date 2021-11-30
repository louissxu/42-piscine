/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 02:19:24 by lxu               #+#    #+#             */
/*   Updated: 2021/11/30 22:18:52 by lxu              ###   ########.fr       */
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
	char *hex_chars;

	hex_chars = "0123456789abcdef";
	return (hex_chars[num]);	
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
