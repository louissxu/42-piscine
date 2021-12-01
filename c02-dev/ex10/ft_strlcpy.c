/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 01:48:49 by lxu               #+#    #+#             */
/*   Updated: 2021/12/01 12:29:03 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	counter;
	unsigned int	source_size;

	counter = 0;
	source_size = 0;
	while (counter < (size - 1) && src[counter])
	{
		dest[counter] = src[counter];
		counter++;
	}
	while (counter < (size))
	{
		dest[counter] = '\0';
		counter++;
	}
	while (src[source_size])
	{
		source_size++;
	}
	return (source_size);
}
