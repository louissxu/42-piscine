/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 00:32:17 by lxu               #+#    #+#             */
/*   Updated: 2021/11/29 00:32:44 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	char	*start;
	int		space_before;

	start = str;
	space_before = 1;
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z' && space_before == 1)
		{
			*str = *str - ('a' - 'A');
		}
		if (*str == ' ')
		{
			space_before = 1;
		}
		else
		{
			space_before = 0;
		}
		str++;
	}
	return (start);
}
