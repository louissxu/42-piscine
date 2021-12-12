/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 23:30:55 by lxu               #+#    #+#             */
/*   Updated: 2021/12/12 23:58:15 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <stdlib.h>

int	main_helper2(long int num, char *dict_string)
{
	int		error_code;
	t_dict	*dict;
	char	*file_as_string;

	dict_string = "numbers.dict";
	error_code = ft_parse_file(dict_string, &dict, &file_as_string);
	if (error_code == 0)
	{
		return (0);
	}
	ft_print_whole_number(num, dict);
	ft_destroy_dict(dict);
	free(file_as_string);
	return (0);
}

int	main_helper1(char *number_string, char *dict_string)
{
	int			error_code;
	long int	num;
	char		*file_as_string;
	t_dict		*dict;

	error_code = ft_check_number_string(number_string);
	if (error_code == 0)
	{
		ft_print_error();
		return (0);
	}
	num = ft_atoli(number_string);
	if (dict_string)
	{
		error_code = ft_parse_file(dict_string, &dict, &file_as_string);
		if (error_code == 0)
			return (0);
		error_code = ft_print_special_number(num, dict);
		ft_destroy_dict(dict);
		free(file_as_string);
		if (error_code)
			return (0);
	}
	return (main_helper2(num, dict_string));
}

int	main(int argc, char **argv)
{
	char		*number_string;
	char		*dict_string;
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
		number_string = argv[1];
	if (argc == 3)
	{
		number_string = argv[2];
		dict_string = argv[1];
	}
	return (main_helper1(number_string, dict_string));
}
