##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

MAIN		=	main.c

SRC_NO_TEST	=	src/matchstick.c		\
				src/get_player_input.c

SRC_TEST	=	src/gameboard.c			\
				src/print_gameboard.c	\
				src/remove_matches.c	\
				src/get_nb_sticks.c		\
				src/error.c				\
				src/print_action.c		\
				src/check_game_status.c

SRC_IA		=	src/ia/play.c

SRC			=	$(SRC_NO_TEST) $(SRC_TEST) $(SRC_IA)

CFLAGS		=	-I./include/ -Wall -Wextra

LIB			=	-L./lib -lmy

OBJ			=	$(MAIN:.c=.o) $(SRC:.c=.o)

NAME		=	matchstick

all:	$(NAME)

lib:
	make -s -C ./lib/my

$(NAME):	lib $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LIB)
	rm -f $(OBJ)

tests_run:	lib
	@find . -name "*.gc*" -delete
	gcc -o unit_tests $(SRC_TEST) tests/*.c $(LIB) $(CFLAGS) --coverage -lcriterion
	./unit_tests
	rm -f unit_tests test*.gc*
	mkdir -p coverage
	mv *.gc* coverage/

debug:	lib
	gcc -g -o $(NAME) $(MAIN) $(SRC) $(LIB) $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f unit_tests *.gc*

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all lib tests_run debug clean fclean re
