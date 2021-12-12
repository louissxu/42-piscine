/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tommy_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tford <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 10:39:29 by tford             #+#    #+#             */
/*   Updated: 2021/12/12 20:41:50 by tford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "rush.h"

int	ft_file_to_string(char *file_name, char **str_ptr)
{
	int					f_index;
	unsigned long int	f_bytes;
	char				c;
	int					r_val;

	*str_ptr = &c;
	f_bytes = 0;
	f_index = open(file_name, O_RDONLY);
	r_val = 1;
	if (f_index < 0)
		r_val = 0;
	while (read(f_index, *str_ptr, 1) && r_val)
		f_bytes++;
	*str_ptr = (char *)malloc((sizeof(char) * (f_bytes + 1)));
	close(f_index);
	f_index = open(file_name, O_RDONLY);
	if (!read(f_index, *str_ptr, f_bytes))
		r_val = 0;
	close(f_index);
	*(*str_ptr + f_bytes) = '\0';
	if (r_val == 0)
		free(*str_ptr);
	return (r_val);
}
