NAME = libftprintf.a
CC = gcc
CFLAG = -Wall -Werror -Wextra
SRC = ft_printf.c \
	utils.c \
	utils2.c

OBJ= $(subst .c,.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $^
	ranlib $(NAME)
%.o : %.c
	$(CC) $(CFLAG) -c $^ -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all build bonus clean fclean re