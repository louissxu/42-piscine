/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 01:48:49 by lxu               #+#    #+#             */
/*   Updated: 2021/11/29 01:49:45 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	counter;
	unsigned int	source_size;

	counter = 0;
	while (dest[counter] && size >= 2 && src[counter])
	{
		dest[counter] = src[counter];
		counter++;
		size--;
	}
	source_size = counter;
	while (dest[counter])
	{
		dest[counter] = '\0';
	}
	while (src[source_size])
	{
		source_size++;
	}
	return (source_size);
}
