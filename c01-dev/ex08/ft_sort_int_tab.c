/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 21:19:14 by lxu               #+#    #+#             */
/*   Updated: 2021/11/28 21:19:19 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	insertion_sort(int *tab, int size)
{
	int	insert_position;
	int	read_position;
	int	smallest_value_position;
	int	temp;

	insert_position = 0;
	while (insert_position < size - 1)
	{
		smallest_value_position = insert_position;
		read_position = insert_position + 1;
		while (read_position < size)
		{
			if (tab[read_position] < tab[smallest_value_position])
				smallest_value_position = read_position;
			read_position++;
		}
		if (smallest_value_position != insert_position)
		{
			temp = tab[insert_position];
			tab[insert_position] = tab[smallest_value_position];
			tab[smallest_value_position] = temp;
		}
		insert_position++;
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	insertion_sort(tab, size);
}
