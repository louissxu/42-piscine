/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 20:26:12 by lxu               #+#    #+#             */
/*   Updated: 2021/12/08 22:10:21 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int in_set(char c, char *charset)
{
	int i;

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

int number_of_words(char *str, char *charset)
{
	int i;
	int word_count;

	word_count = 0;
	i = 1;
	while (str[i])
	{
		if (in_set(str[i], charset) == 0 && \
				(in_set(str[i+1], charset) == 1 || str[i+1] == '\0'))
		{
			word_count++;
		}
		i++;
	}
	return (word_count);
}

char **ft_split(char *str, char *charset)
{
	char** result_array;
	int words;
	int i;
	int j;
	int k;
	char *word;

	words = number_of_words(str, charset);
	result_array = (char**)malloc((words + 1) * sizeof(char*));

	words = 0;
	i = 0;
	while (str[i])
	{
		if ((in_set(str[i-1], charset) == 1 && in_set(str[i], charset) == 0) ||\
				(i == 0 && in_set(str[i], charset) == 0))
		{
			j = i;
			while(str[j] && in_set(str[j], charset) == 0)
			{
				j++;
			}
			word = (char*)malloc((j - i) * sizeof(char));
			
			k = 0;
			while(i < j)
			{
				word[k] = str[i];
				i++;
				k++;
			}
			result_array[words] = word;
			words++;
		}
		i++;
	}
	result_array[words] = NULL;
	return (result_array);
}
