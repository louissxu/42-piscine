/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:50:37 by lxu               #+#    #+#             */
/*   Updated: 2021/12/12 20:38:13 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.c"

int	ft_parse_file(char *file_name, t_dict *dict)
{
	int		error_code;
	char	*file_as_string;

	error_code = ft_file_to_string(file_name, &file_as_string);
	if (error_code == 0)
	{
		ft_print_dict_error();
		return (0);
	}
	error_code = ft_string_to_dict_arr(file_as_string, &dict)
	if (error_code == 0)
	{
		ft_print_dict_error();
		return (0);
	}
	return (1);
}
