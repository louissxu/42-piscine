/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:50:37 by lxu               #+#    #+#             */
/*   Updated: 2021/12/12 20:35:11 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.c"

#define REFERENCE_DICT_STRING = "numbers.dict"

int	main(int argc, char **argv)
{
	char		*number_string;
	char		*dict_string;
	long int	num;
	int			error_code;
	t_dict		*dict;

	if (argc > 3 || argc < 2)
	{
		ft_putstr("Usage: ./rush-02 [file.dict] number");
		ft_print_space();
		return (0);
	}
	if (argc == 2)
	{
		number_string = argv[1];
		dict_string = NULL;
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
	num = ft_atoli(num_string)

	if (dict_string)
	{
		error_code = ft_parse_file(dict_string, dict)
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

	dict_string = REFERENCE_DICT_STRING;

	error_code = ft_parse_file(dict_string, dict);
	if (error_code == 0)
	{
		return (0);
	}
	ft_print_whole_numer(number, dict)
	return (0);
}
