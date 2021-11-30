/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 22:03:15 by lxu               #+#    #+#             */
/*   Updated: 2021/11/30 19:57:02 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int				terminate_string;
	unsigned int	i;

	terminate_string = 0;
	i = 0;
	while (i < n)
	{
		if (src[i])
			dest[i] = src[i];
		else
		{
			terminate_string = 1;
			break ;
		}
		i++;
	}
	if (terminate_string)
	{
		while (i < n)
		{
			dest[i] = '\0';
			i++;
		}
	}
	return (dest);
}
