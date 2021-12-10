/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 20:26:12 by lxu               #+#    #+#             */
/*   Updated: 2021/12/10 13:50:54 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	in_set(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	number_of_words(char *str, char *charset)
{
	int	i;
	int	word_count;

	word_count = 0;
	i = 1;
	while (str[i])
	{
		if (in_set(str[i], charset) == 0 && \
				(in_set(str[i + 1], charset) == 1 || str[i + 1] == '\0'))
		{
			word_count++;
		}
		i++;
	}
	return (word_count);
}

int	insert_word(char **results_array, char *str, int word_start, int word_end)
{
	int		i;
	char	*word;

	word = (char *)malloc((word_end - word_start + 1) * sizeof(char));
	i = 0;
	while (word_start < word_end)
	{
		word[i] = str[word_start];
		word_start++;
		i++;
	}
	word[i] = '\0';
	results_array[0] = word;
	return (word_start);
}

char	**ft_split(char *str, char *charset)
{
	char	**results_array;
	int		words;
	int		i;
	int		j;

	words = number_of_words(str, charset);
	results_array = (char **)malloc((words + 1) * sizeof(char *));
	words = 0;
	i = 0;
	while (str[i])
	{
		if ((in_set(str[i - 1], charset) && in_set(str[i], charset) == 0) || \
				(i == 0 && in_set(str[i], charset) == 0))
		{
			j = i;
			while (str[j] && in_set(str[j], charset) == 0)
				j++;
			i = insert_word(&results_array[words], str, i, j);
			words++;
		}
		i++;
	}
	results_array[words] = NULL;
	return (results_array);
}
