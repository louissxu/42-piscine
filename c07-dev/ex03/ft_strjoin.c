/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:58:28 by lxu               #+#    #+#             */
/*   Updated: 2021/12/08 17:00:32 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	memory_needed(int size, char **str, char *sep)
{
	int i;
	int j;
	int sep_size;
	int	memory_needed;

	i = 0;
	sep_size = 0;
	while (sep[i])
	{
		sep_size++;
		i++;
	}
	i = 0;
	memory_needed = 1;
	if (size > 1)
	{
		memory_needed += (size - 1) * sep_size;
	}
	while (i < size)
	{
		j = 0;
		while (str[i][j])
		{
			memory_needed++;
			j++;
		}
		i++;
	}
	return (memory_needed);
}

char	*ft_strjoin(int size, char **str, char *sep)
{
	char	*joined_str;
	int		joined_str_size;
	int		joined_str_i;
	int		i;
	int		j;

	joined_str_size = memory_needed(size, str, sep);
	joined_str = (char*)malloc(joined_str_size);
	joined_str_i = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (str[i][j])
		{
			joined_str[joined_str_i] = str[i][j];
			j++;
			joined_str_i++;
		}
		j = 0;
		if (i < size - 1)
		while (sep[j])
		{
			joined_str[joined_str_i] = sep[j];
			j++;
			joined_str_i++;
		}
		i++;
	}
	joined_str[joined_str_i] = '\0';
	return (joined_str);
}
