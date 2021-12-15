HEAD = includes
SOURCE = srcs/
CC = gcc
CC_FLAGS = -Wall -Wextra -Werror
SRCS = ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c
OBJS = $(addprefix $(SOURCE),$(SRCS:.c=.o))
NAME = libft.a


all: $(NAME)

.c.o:
	$(CC) $(CC_FLAGS) -I $(HEAD) -c -o $@ $<

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	-rm $(OBJS)

fclean: clean
	-rm $(NAME)

re: fclean all

.PHONY: all clean fclean re

