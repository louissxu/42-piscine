/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:52:55 by lxu               #+#    #+#             */
/*   Updated: 2021/12/07 20:49:39 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	insertion_sort(char **tab, int tab_len)
{
	int		i;
	int		j;
	int		cur_lowest;
	char	*tmp;

	i = 0;
	while (i < tab_len - 1)
	{
		j = i;
		cur_lowest = i;
		while (j < tab_len)
		{
			if (ft_strcmp(tab[i], tab[j]) > ft_strcmp(tab[i], tab[cur_lowest]))
			{
				cur_lowest = j;
			}
			j++;
		}
		tmp = tab[cur_lowest];
		tab[cur_lowest] = tab[i];
		tab[i] = tmp;
		i++;
	}
}

void	print_str(char *s)
{
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int	i;

	insertion_sort(&argv[1], argc - 1);
	i = 1;
	while (i < argc)
	{
		print_str(argv[i]);
		i++;
	}
}
