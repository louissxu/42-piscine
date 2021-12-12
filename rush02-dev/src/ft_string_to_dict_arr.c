/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tommy_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tford <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 10:39:29 by tford             #+#    #+#             */
/*   Updated: 2021/12/12 23:10:41 by tford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "rush.h"

int	ft_string_newlines(char *str)
{
	unsigned int	i;
	int				newlines;

	i = 0;
	newlines = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			newlines++;
		i++;
	}
	return (newlines);
}

t_dict	*ft_dict_create(int size)
{
	t_dict	*ptr;

	ptr = NULL;
	ptr = (t_dict *)malloc(sizeof(t_dict) * size + 1);
	return (ptr);
}

void	ft_str_to_dict_looper(char *str, t_dict **dict, int *state_flag)
{
	int	prev_state_flag;
	int	i_dict;
	int	k;

	i_dict = 0;
	k = 0;
	while (str[k])
	{	
		prev_state_flag = *state_flag;
		*state_flag = ft_dict_handler(*state_flag, &str[k]);
		if (!*state_flag)
			return ;
		if (*state_flag == 1 && prev_state_flag != 1)
			(*dict)[i_dict].key = ft_atoli(&str[k]);
		if (*state_flag == 5 && prev_state_flag != 5)
		{
			(*dict)[i_dict].value = &str[k];
			i_dict++;
		}
		k++;
	}
	(*dict)[i_dict].value = NULL;
}

int	ft_string_to_dict_arr(char *str, t_dict **dict)
{
	int	state_flag;

	*dict = ft_dict_create(ft_string_newlines(str));
	state_flag = 6;
	ft_str_to_dict_looper(str, dict, &state_flag);
	if (state_flag != 6)
		return (0);
	return (1);
}
