/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:19:35 by lxu               #+#    #+#             */
/*   Updated: 2021/12/12 00:07:08 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_pointer(void *ptr)
{
	char	addr_chars[16];
	long	addr_long;
	int		i;

	addr_long = (long)ptr;
	i = 0;
	while (i < 16)
	{
		addr_chars[16 - 1 - i] = addr_long % 16;
		if (addr_chars[16 - 1 - i] < 10)
			addr_chars[16 - 1 - i] += '0';
		else
			addr_chars[16 - 1 - i] += ('a' - 10);
		addr_long = addr_long / 16;
		i++;
	}
	i = 0;
	while (i < 16)
	{
		write(1, &addr_chars[i], 1);
		i++;
	}
	write(1, ": ", 2);
}

void	print_byte_as_hex(char *ptr)
{
	char	large_hex;
	char	small_hex;
	char	*hex_chars;

	hex_chars = "0123456789abcdef";
	large_hex = *ptr / 16;
	small_hex = *ptr % 16;
	write(1, &hex_chars[(int)large_hex], 1);
	write(1, &hex_chars[(int)small_hex], 1);
}

void	print_byte_as_alpha(char *ptr)
{
	if (*ptr >= ' ' && *ptr <= '~')
	{
		write(1, ptr, 1);
	}
	else
	{
		write(1, ".", 1);
	}
}

void	print_combined_data_line(char *ptr, int bytes)
{
	int	i;

	i = 0;
	while (i < bytes)
	{
		print_byte_as_hex(ptr + i);
		if (i % 2 != 0)
			write (1, " ", 1);
		i++;
	}
	while (i < 16)
	{
		write(1, "  ", 2);
		if (i % 2 != 0)
			write (1, " ", 1);
		i++;
	}
	i = 0;
	while (i < bytes)
	{
		print_byte_as_alpha(ptr + i);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int				bytes_to_print;
	unsigned int	offset;

	offset = 0;
	while (size > 0)
	{
		if (size >= 16)
			bytes_to_print = 16;
		else
			bytes_to_print = size;
		print_pointer(addr + offset);
		print_combined_data_line(addr + offset, bytes_to_print);
		write(1, "\n", 1);
		if (size > 16)
			size -= 16;
		else
			size = 0;
		offset += 16;
	}
	return (addr);
}
