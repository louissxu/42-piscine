/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:54:36 by lxu               #+#    #+#             */
/*   Updated: 2021/12/12 17:28:32 by jthiele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

typedef struct s_dict
{
	long int	key;
	char		*value;
}	t_dict;

char	*ft_dict_get(t_dict *lut_dict, long int num);
int		ft_is_colon(char c);
int		ft_is_newline(char c);
int		ft_is_numeric(char c);
int		ft_is_printable(char c);
int		ft_is_sign(char c);
int		ft_is_space(char c);
void	ft_print_comma(void);
void	ft_print_double_digit(long int num, int is_first_el, t_dict *lut_dict);
void	ft_print_error(void);
void	ft_print_multiplier(long int num, t_dict *lut_dict);
void	ft_print_negative(void);
void	ft_print_newline(void);
void	ft_print_single_digit(long int num, int is_first_el, t_dict *lut_dict);
void	ft_print_space(void);
int		ft_print_special_number(long int num, t_dict *lut_dict);
void	ft_print_triple_digit(long int num, int is_first_el, t_dict *lut_dict);
void	ft_print_whole_number(long int num, t_dict *lut_dict);
void	ft_process_triplet(long int num, long int multiplier, \
		int is_first_el, t_dict *lut_dict);
void	ft_putchar(const char c);
void	ft_putstr(char *str);

#endif
