##
## EPITECH PROJECT, 2023
## myftp
## File description:
## Makefile
##

NAME	=		panoramix

all: configure $(NAME)

$(NAME):
				make -C build
				cp build/$(NAME) .

configure:
				mkdir -p build
				cd build && cmake ..

clean: configure
				make clean -C build

fclean:
				rm -rf build
				rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re configure