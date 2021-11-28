/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 00:32:17 by lxu               #+#    #+#             */
/*   Updated: 2021/11/29 00:57:14 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_lower_alpha(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	is_upper_alpha(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	is_number(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	is_alphanum(char c)
{
	if (is_lower_alpha(c) == 1 || is_upper_alpha(c) == 1 || is_number(c) == 1)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

char	*ft_strcapitalize(char *str)
{
	char	*start;
	int		new_word;

	start = str;
	new_word = 1;
	while (*str)
	{
		if (new_word)
		{
			if (is_lower_alpha(*str))
				*str = *str - ('a' - 'A');
		}
		else
		{
			if (is_upper_alpha(*str))
				*str = *str + ('a' - 'A');
		}
		if (is_alphanum(*str))
			new_word = 0;
		else
			new_word = 1;
		str++;
	}
	return (start);
}
