# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jthiele <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 16:48:07 by jthiele           #+#    #+#              #
#    Updated: 2021/12/12 17:25:56 by jthiele          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#name of folder holding all our functions and main
SOURCE = src/

#all our functions and main i.e. ft_this ft_that
SRC = ft_dict_get.c ft_is_colon.c ft_is_newline.c ft_is_numeric.c ft_is_printable.c ft_is_sign.c ft_is_space.c ft_print_comma.c ft_print_double_digit.c ft_print_error.c ft_print_multiplier.c ft_print_negative.c ft_print_newline.c ft_print_single_digit.c ft_print_space.c ft_print_special_number.c ft_print_triple_digit.c ft_print_whole_number.c ft_process_triplet.c ft_putchar.c ft_putstr.c

#cleaning
OBJS = ${addprefix ${SOURCE},${SRCS:.c=.o}}

#the folder containing the header file
HEAD = includes

#Compiler Collection / which compiler we are using
CC = gcc

#Compiler flags
CFLAGS = -Wall -Werror -Wextra

#Name of compiled file
NAME = rush-02

NORMINETTE = norminette

NORMOBJS = ${addprefix ${SOURCE},${SRC}}

.c.o:
	${CC} ${CFLAGS} -I ${HEAD} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	${CC} ${CFLAGS} $^ -o $@

all:	${NAME}

#Removes object files created
clean:
	rm -f ${OBJS}

fclean:
	rm -f ${OBJS}
	rm -f ${NAME}

norm:
	${NORMINETTE} ${NORMOBJS}

#Always run the commands even if there are files with these names
.PHONY:	all clean fclean norm
