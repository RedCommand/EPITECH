##
## EPITECH PROJECT, 2021
## libmy Makefile
## File description:
## Makefile to build libmy.a
##

override CFLAGS += -fno-builtin -W -Wall -Wextra -Llib -lmy -g
override CPPFLAGS += -Iinclude

TESTSRC = tests/test_make.c \
					tests/test_do_op.c \
					tests/test_summands.c \
					tests/test_factors.c	\
					tests/test_better_summands.c \
					tests/test_eval_expr.c

TESTOBJ = $(TESTSRC:.c=.o)

MAINSRC = main.c

MAINOBJ = $(MAINSRC:.c=.o)

SRC = src/do_op/do_op.c \
			src/do_op/function_operators.c \
			src/summands.c \
			src/full_summands.c \
			src/number.c \
			src/evalexpr.c \
			src/extract_expr.c

OBJ = $(SRC:.c=.o)

HEADER = my.h

NAME = calc

all: $(NAME)

$(NAME): $(OBJ) $(MAINOBJ)
				make -C lib/my
				gcc -o $(NAME) $(MAINOBJ) $(OBJ) $(CFLAGS) $(CPPFLAGS)

clean:
				rm -f $(OBJ) $(MAINOBJ)
				find -name "*.gc*" -delete
				make clean -C lib/my

fclean: clean
				rm -f $(NAME)
				rm -f unit_tests*
				make fclean -C lib/my

re: fclean all

tests_run: 	CFLAGS += -lcriterion --coverage
tests_run: re $(TESTOBJ)
				gcc -o unit_tests $(TESTOBJ) $(SRC) $(CFLAGS) $(CPPFLAGS)
				./unit_tests

cover:
				gcovr --exclude tests
				gcovr --exclude tests --branches
