/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:48:38 by lxu               #+#    #+#             */
/*   Updated: 2021/12/09 11:05:08 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		str_len;
	char	*str_cpy;
	int		i;

	str_len = 0;
	while (src[str_len])
	{
		str_len++;
	}
	str_cpy = (char *)malloc((str_len + 1) * sizeof(char));
	if (str_cpy)
	{
		i = 0;
		while (src[i])
		{
			str_cpy[i] = src[i];
			i++;
		}
		str_cpy[i] = '\0';
	}
	return (str_cpy);
}
