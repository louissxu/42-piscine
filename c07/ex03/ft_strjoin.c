/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:58:28 by lxu               #+#    #+#             */
/*   Updated: 2021/12/09 11:24:32 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	memory_needed(int size, char **str, char *sep)
{
	int	i;
	int	j;
	int	sep_size;
	int	memory_needed;

	i = 0 - 1;
	sep_size = 0;
	while (sep[++i])
		sep_size++;
	i = 0;
	memory_needed = 1;
	if (size > 1)
		memory_needed += (size - 1) * sep_size;
	while (i < size)
	{
		j = 0 - 1;
		while (str[i][++j])
			memory_needed++;
		i++;
	}
	return (memory_needed);
}

int	insert_word(char *dest, char *src, int location)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[location] = src[i];
		location++;
		i++;
	}
	return (location);
}

char	*ft_strjoin(int size, char **str, char *sep)
{
	char	*joined_str;
	int		joined_str_size;
	int		joined_str_i;
	int		i;

	joined_str_size = memory_needed(size, str, sep);
	joined_str = (char *)malloc(joined_str_size);
	joined_str_i = 0;
	i = 0;
	while (i < size)
	{
		joined_str_i = insert_word(joined_str, str[i], joined_str_i);
		if (i < size - 1)
		{
			joined_str_i = insert_word(joined_str, sep, joined_str_i);
		}
		i++;
	}
	joined_str[joined_str_i] = '\0';
	return (joined_str);
}
