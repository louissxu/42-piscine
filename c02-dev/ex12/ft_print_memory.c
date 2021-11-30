/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:19:35 by lxu               #+#    #+#             */
/*   Updated: 2021/11/30 17:30:58 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_int_as_hex_char(int val)
{
	int	i;
	int	hex_chars[16];

	i = 0;
	while (i < 16)
	{
		if (i < 10)
		{
			hex_chars[i] = '0' + i;
		}
		else
		{
			hex_chars[i] = 'a' + i - 10;
		}
		i++;
	}
	write(1, &hex_chars[val], 1);
}

void	print_pointer(void *ptr)
{
	int				pointer_size;
	int				hex_char_position;
	long unsigned	val_to_print;

	pointer_size = sizeof(size_t);
	hex_char_position = (pointer_size * 2) - 1;
	while (hex_char_position >= 0)
	{
		val_to_print = (long unsigned)ptr << ((16 - 1 - hex_char_position) * 4);
		val_to_print = val_to_print >> ((16 - 1 - hex_char_position) * 4);
		val_to_print = val_to_print >> ((hex_char_position) * 4);
		print_int_as_hex_char(val_to_print);
		hex_char_position--;
	}
	write(1, ": ", 2);
}

void	print_byte_as_hex(char *ptr)
{
	int		large_hex;
	int		small_hex;
	char	*hex_chars;

	hex_chars = "0123456789abcdef";
	large_hex = *ptr / 16;
	small_hex = *ptr % 16;
	write(1, &hex_chars[large_hex], 1);
	write(1, &hex_chars[small_hex], 1);
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

void	*ft_print_memory(void *addr, unsigned int size)
{
	int	counter;

	while (size > 0)
	{
		print_pointer(addr);
		counter = 0 - 1;
		while (++counter < 16)
		{	
			if ((unsigned int)counter < size)
				print_byte_as_hex(addr + counter);
			else
				write(1, "  ", 2);
			if (counter % 2 != 0)
				write(1, " ", 1);
		}
		while ((++counter - 17) < 16 && (unsigned int)(counter - 17) < size)
			print_byte_as_alpha(addr + counter - 17);
		write(1, "\n", 1);
		if (size > 16)
			size -= 16;
		else
			size = 0;
		addr += 16;
	}
	return (addr);
}
