/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:50:37 by lxu               #+#    #+#             */
/*   Updated: 2021/12/12 22:39:30 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	char		*number_string;
	char		*dict_string;
	long int	num;
	int			error_code;
	t_dict		*dict;

	dict_string = NULL;
	dict = NULL;
	if (argc > 3 || argc < 2)
	{
		ft_putstr("Usage: ./rush-02 [file.dict] number");
		ft_print_space();
		return (0);
	}
	if (argc == 2)
	{
		number_string = argv[1];
	}
	if (argc == 3)
	{
		number_string = argv[2];
		dict_string = argv[1];
	}
	error_code = ft_check_number_string(number_string);
	if (error_code == 0)
	{
		ft_print_error();
		return (0);
	}
	num = ft_atoli(number_string);

	
	if (dict_string)
	{
		error_code = ft_parse_file(dict_string, &dict);
		{
			if (error_code == 0)
			{
				return (0);
			}
		}
		if (ft_print_special_number(num, dict))
		{
			return (0);
		}
	}

	dict_string = "numbers.dict";

	error_code = ft_parse_file(dict_string, &dict);
	if (error_code == 0)
	{
		return (0);
	}

	ft_print_whole_number(num, dict);
	return (0);
}
