

CC = cc
CFLAGS = -Wall -Wextra -std=c99

SRCS = ft_print_chr.c ft_print_hex.c ft_print_nbr.c ft_print_string.c ft_print_u_nbr.c ft_print_upper_hex.c ft_printf.c ft_strdup.c
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rc $(NAME) $(OBJS)

$(OBJS) : $(SRC)
	$(CC) $(FLAGS) -c $(SRCS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

