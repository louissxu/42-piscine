/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 00:36:35 by lxu               #+#    #+#             */
/*   Updated: 2021/12/15 15:13:02 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	in_set(char c, char *set)
{
	while (*set)
	{
		if (c == *set)
		{
			return (1);
		}
		set++;
	}
	return (0);
}

int word_count(char *str, char *sep)
{
	int count;

	count = 0;
	while (*str)
	{
		if ((in_set(*str, sep) == 0 && in_set(*(str + 1), sep) == 1) || \
			(in_set(*str, sep) == 0 && *(str + 1) == '\0'))
		{
			count++;
		}
		str++;
	}
	return (count);
}

char	*dupe_word(char *str, char *sep)
{
	int		len;
	char	*word_cpy;
	int		i;

	len = 0;
	while (in_set(str[len], sep) == 0)
	{
		len++;
	}
	word_cpy = malloc(sizeof(*word_cpy) * (len + 1));
	i = 0;
	while (i < len)
	{
		word_cpy[i] = str[i];
		i++;
	}
	word_cpy[i] = '\0';
	return (word_cpy);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		number_of_words;
	int		word_number;
	int		prev_char_is_sep;

	number_of_words = word_count(str, charset);
	result = malloc(sizeof(*result) * (number_of_words + 1));
	if (result == NULL)
	{
		return (result);
	}
	prev_char_is_sep = 1;
	word_number = 0;
	while (*str)
	{
		if (in_set(*str, charset) == 0 && prev_char_is_sep)
		{
			result[word_number] = dupe_word(str, charset);
			word_number++;
		}
		prev_char_is_sep = in_set(*str, charset);
		str++;
	}
	result[word_number] = NULL;
	return (result);
}
