##
## EPITECH PROJECT, 2021
## libmy Makefile
## File description:
## Makefile to build libmy.a
##

override CFLAGS += -fno-builtin -W -Wall -Wextra
override CPPFLAGS += -Iinclude -Llib -lmy

TESTSRC = tests/test_make.c \
		  tests/test_navy.c

TESTOBJ = $(TESTSRC:.c=.o)

MAINSRC = main.c

MAINOBJ = $(MAINSRC:.c=.o)

SRC = src/navy.c \
	  src/get_boat_position.c \
	  src/display.c \
	  src/utils.c \
	  src/signal/signal.c \
	  src/signal/signal_send_utils.c \
	  src/signal/signal_get_utils.c \
	  src/signal/user_input.c \
	  src/client/client.c \
	  src/client/get_connection.c \
	  src/server/server.c \
	  src/server/get_connection.c \
	  src/turn.c

OBJ = $(SRC:.c=.o)

NAME = navy

all: $(NAME)

$(NAME): $(OBJ) $(MAINOBJ)
				make -C lib/my
				gcc -o $(NAME) $(MAINOBJ) $(OBJ) $(CFLAGS) $(CPPFLAGS)

clean:
				rm -f $(OBJ) $(MAINOBJ)
				find . -type f -name '*.gcda' -delete
				find . -type f -name '*.gcno' -delete
				make clean -C lib/my

fclean: clean
				rm -f $(NAME)
				make fclean -C lib/my

re: fclean all

debug: CFLAGS += -g
debug: re

tests_run:  	CFLAGS += -lcriterion --coverage
tests_run:  	debug $(TESTOBJ)
		    	gcc -o unit_tests $(TESTOBJ) $(SRC) $(CFLAGS) $(CPPFLAGS)
				./unit_tests

cover:
				gcovr --exclude tests
				gcovr --exclude tests --branches
				rm -f unit_tests*
