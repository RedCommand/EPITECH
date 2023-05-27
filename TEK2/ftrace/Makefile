##
## EPITECH PROJECT, 2023
## myftrace
## File description:
## Makefile
##

NAME	=						ftrace

all:	configure $(NAME)

$(NAME):
								make -C build
								cp build/ftrace .

configure:
								mkdir -p build
								cd build && cmake ..

clean: configure
								make clean -C build

fclean:
								rm -rf build
								rm -f ftrace

re:	fclean all

.PHONY:	all clean fclean re configure
