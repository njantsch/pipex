CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a

SOURCES = ft_printf.c ft_num_in_hex.c ft_print_unsigned.c \
		ft_print_number.c ft_print_word.c ft_void_pointer.c

OBJECTS = $(SOURCES:.c=.o)

$(NAME) : $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

all: $(NAME)

clean:
	@rm -f $(OBJECTS) $(BONUSOBJECTS)

fclean:
	@rm -f $(NAME) $(OBJECTS) $(BONUSOBJECTS)

re:	fclean all

.PHONY : all clean fclean re
