/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:54:36 by lxu               #+#    #+#             */
/*   Updated: 2021/12/13 00:07:18 by lxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

typedef struct s_dict
{
	long int	key;
	char		*value;
}	t_dict;

long int	ft_atoli(char *str);
char		*ft_dict_get(t_dict *lut_dict, long int num);
int			ft_is_colon(char c);
int			ft_is_newline(char c);
int			ft_is_numeric(char c);
int			ft_is_printable(char c);
int			ft_is_sign(char c);
int			ft_is_space(char c);
void		ft_print_comma(void);
void		ft_print_double_digit(long int num, \
		int is_first_el, t_dict *lut_dict);
void		ft_putstr(char *str);
int			ft_string_to_dict_arr(char *str, t_dict **dict);
int			ft_file_to_string(char *file_name, char **str_ptr);
int			ft_check_number_string(char *str);
int			ft_dict_handler(int state_flag, char *c);
int			ft_parse_file(char *file_name, t_dict **dict, char **file_as_string);
void		ft_print_dict_error(void);
void		ft_destroy_dict(t_dict *dict);
void		ft_print_error(void);
void		ft_print_negative(void);
void		ft_print_newline(void);
void		ft_print_single_digit(long int num, int is_first_el, \
		t_dict *lut_dict);
void		ft_print_space(void);
int			ft_print_special_number(long int num, t_dict *lut_dict);
void		ft_print_triple_digit(long int num, \
		int is_first_el, t_dict *lut_dict);
void		ft_print_whole_number(long int num, t_dict *lut_dict);
void		ft_process_triplet(long int num, long int multiplier, \
		int is_first_el, t_dict *lut_dict);
void		ft_putchar(const char c);
void		ft_putstr(char *str);
int			ft_string_to_dict_arr(char *str, t_dict **dict);
int			ft_file_to_string(char *file_name, char **str_ptr);
int			ft_check_number_string(char *str);
int			ft_dict_handler(int state_flag, char *c);
void		ft_print_dict_error(void);
void		ft_print_multiplier(long int multiplier, t_dict *lut_dict);

#endif
