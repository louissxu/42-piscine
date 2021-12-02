/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:44:30 by lxu               #+#    #+#             */
/*   Updated: 2021/12/01 23:52:44 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\n' || \
			c == '\v' || c == '\f')
	{
		return (1);
	}
	return (0);
}

int	simple_atoi(char *str)
{
	int	result;

	result = 0;
	while (*str && *str >= '0' && *str <= '9')
	{
		result = result * 10;
		result = result + *str - '0';
		str++;
	}
	return (result);
}

int	ft_atoi(char *str)
{
	int	i;
	int	is_positive;

	i = 0;
	is_positive = 1;
	while (str[i])
	{
		if (is_whitespace(str[i]))
			i++;
		else
			break ;
	}
	while (str[i])
	{
		if (str[i] == '-')
		{
			is_positive = is_positive * (-1);
			i++;
		}
		else if (str[i] == '+')
			i++;
		else
			break ;
	}
	return (simple_atoi(str + i) * is_positive);
}
