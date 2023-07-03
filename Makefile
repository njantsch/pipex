CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = pipex

SOURCES = ./src/pipex.c ./src/input_checks.c ./src/utils.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME) : $(OBJECTS)
	@cd libs && make
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) ./libs/libs.a

clean:
	@cd libs && make fclean
	@rm -f $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)

re:	fclean all
