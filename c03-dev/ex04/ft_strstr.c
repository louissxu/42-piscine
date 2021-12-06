/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 01:18:21 by lxu               #+#    #+#             */
/*   Updated: 2021/12/06 23:50:14 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_match(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	if (*to_find == '\0')
	{
		return (str);
	}
	while (*str)
	{
		if (is_match(str, to_find))
		{
			return (str);
		}
		str++;
	}
	return ('\0');
}
