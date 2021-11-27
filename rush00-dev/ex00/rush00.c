/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 21:08:33 by lxu               #+#    #+#             */
/*   Updated: 2021/11/27 21:08:34 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char *c);

void	print_first_line(int x)
{
	int	x_current;

	x_current = 0;
	while (x_current < x)
	{
		if (x_current == 0)
			ft_putchar("o");
		else if (x_current == x - 1)
			ft_putchar("o");
		else
			ft_putchar("-");
	x_current++;
	}
}

void	print_middle_line(int x)
{
	int	x_current;

	x_current = 0;
	while (x_current < x)
	{
		if (x_current == 0)
			ft_putchar("|");
		else if (x_current == x - 1)
			ft_putchar("|");
		else
			ft_putchar(" ");
	x_current++;
	}
}

void	print_last_line(int x)
{
	int	x_current;

	x_current = 0;
	while (x_current < x)
	{
		if (x_current == 0)
			ft_putchar("o");
		else if (x_current == x - 1)
			ft_putchar("o");
		else
			ft_putchar("-");
	x_current++;
	}
}

void	rush(int x, int y)
{
	int	y_current;

	y_current = 0;
	while (y_current < y)
	{
		if (y_current == 0)
			print_first_line(x);
		else if (y_current == y - 1)
			print_last_line(x);
		else
			print_middle_line(x);
		ft_putchar("\n");
		y_current++;
	}
}
