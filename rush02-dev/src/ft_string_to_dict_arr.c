/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tommy_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tford <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 10:39:29 by tford             #+#    #+#             */
/*   Updated: 2021/12/12 20:40:31 by tford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "rush.h"

int	ft_string_newlines(char *str)
{
	unsigned int 	i;
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
	t_dict *ptr;

	ptr = NULL;
	ptr = (t_dict *)malloc(sizeof(t_dict) * size);
	return (ptr);
}

int	ft_string_to_dict_arr(char *str, t_dict **dict)
{
	int i_dict;
	int i;
	int state_flag;
	int	prev_state_flag;

	*dict = ft_dict_create(ft_string_newlines);

	state_flag = 6;
	i = 0;
	i_dict = 0;
	while (str[i])
	{	
		prev_state_flag = state_flag;
		state_flag = ft_dict_handler(state_flag, &str[i]);
		if (!state_flag)
			return (0);
		if (state_flag == 1 && prev_state_flag != 1)
			**dict[i_dict].key = ft_atoli(&str[i]);
		if (state_flag == 5 && prev_state_flag != 5)
		{
			**dict[i_dict].value = &str[i];
			i_dict++;
		}
		i++;
	}
	**dict[i_dict].value = NULL;
	if (state_flag != 6)
		return (0);
	return (1);
}

int	main()
{
	printf("running");
	char *dict_str = NULL;
	ft_file_to_string("numbers.dict", &dict_str);
	
	int val = ft_string_to_dict_arr(dict_str);
	printf("the return val was: %d\n", val);
	printf("out");
}
