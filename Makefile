PROG = exec
NAME = libftprintf.a
CC = gcc
CFLAG = -Wall -Werror -Wextra
SRC = ft_printf.c \
	ft_dec.c \
	ft_hex.c \
	ft_str.c

OBJ= $(subst .c,.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $^
	ranlib $(NAME)

%.o : %.c
	$(CC) $(CFLAG) -c $^ -o $@

build: all
	$(CC) $(OBJ) $(CFLAG) -o $(PROG)

bonus : all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all build bonus clean fclean re