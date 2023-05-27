##
## EPITECH PROJECT, 2021
## libmy Makefile
## File description:
## Makefile to build libmy.a
##

override CFLAGS += -fno-builtin -W -Wall -Wextra -Llib -lmy
override CPPFLAGS += -Iinclude

TESTSRC = tests/test_make.c

TESTOBJ = $(TESTSRC:.c=.o)

MAINSRC = main.c

MAINOBJ = $(MAINSRC:.c=.o)

SRC = src/args.c\
	  src/directory.c\
	  src/files.c\
	  src/display.c\
	  src/free.c\
	  src/utils.c\
	  src/sort.c\
	  src/my_ls.c

OBJ = $(SRC:.c=.o)

HEADER = my.h

NAME = my_ls

all: $(NAME)

$(NAME): $(OBJ) $(MAINOBJ)
				make -C lib/my
				gcc -o $(NAME) $(MAINOBJ) $(OBJ) $(CFLAGS) $(CPPFLAGS)

clean:
				rm -f $(OBJ) $(MAINOBJ) $(TESTOBJ)
				find . -type f -name '*.gcda' -delete
				find . -type f -name '*.gcno' -delete
				make clean -C lib/my

fclean: clean
				rm -f $(NAME)
				make fclean -C lib/my

re: fclean all

tests_run:	CFLAGS += -lcriterion --coverage
tests_run: re $(TESTOBJ)
				gcc -o unit_tests $(TESTOBJ) $(SRC) $(CFLAGS) $(CPPFLAGS)
				./unit_tests

cover:
				gcovr --exclude tests
				gcovr --exclude tests --branches
				rm -f unit_tests*

debug: CFLAGS += -g
debug: re
