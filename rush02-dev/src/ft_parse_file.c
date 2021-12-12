/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:50:37 by lxu               #+#    #+#             */
/*   Updated: 2021/12/12 23:16:28 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	ft_parse_file(char *file_name, t_dict **dict, char **file_as_string)
{
	int		error_code;

	error_code = ft_file_to_string(file_name, file_as_string);
	if (error_code == 0)
	{
		ft_print_dict_error();
		return (0);
	}
	error_code = ft_string_to_dict_arr(*file_as_string, dict);
	if (error_code == 0)
	{
		ft_print_dict_error();
		return (0);
	}
	return (1);
}
