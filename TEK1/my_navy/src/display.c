/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** display
*/

#include "my.h"
#include "local.h"

void printchar(int character)
{
    if (character == 0)
        my_putstr(". ");
    if (character == -1)
        my_putstr("x ");
    if (character == -2)
        my_putstr("o ");
}

void print_map(int **map, int line)
{
    my_printf("%d|", line);
    for (int j = 0; j < BOARD_SIZE; j++) {
        map[line - 1][j] > 1 && map[line - 1][j] < 10 ?
        my_printf("%d ", map[line - 1][j]) : printchar(map[line - 1][j]);
    }
    my_printf("\n");
}

void print_mapenemy(int **map, int line)
{
    my_printf("%d|", line);
    for (int j = 0; j < BOARD_SIZE; j++) {
        map[line - 1][j] > -1 && map[line - 1][j] < 10 ?
        my_putstr(". ") : printchar(map[line - 1][j]);
    }
    my_printf("\n");
}

void display_maps(int **me, int **enemy)
{
    my_printf("my positions:\n");
    write(1, " |A B C D E F G H I J K L M N O P Q R S T U V W X Y Z",
    1 + (2 * BOARD_SIZE));
    my_putchar('\n');
    write(1, "-+----------------------------------------------------",
    1 + (2 * BOARD_SIZE));
    my_putchar('\n');
    for (int i = 0; i < BOARD_SIZE; i++)
        print_map(me, i + 1);
    my_printf("\nenemy's positions:\n");
    write(1, " |A B C D E F G H I J K L M N O P Q R S T U V W X Y Z",
    2 + (2 * BOARD_SIZE));
    my_putchar('\n');
    write(1, "-+----------------------------------------------------",
    1 + (2 * BOARD_SIZE));
    my_putchar('\n');
    for (int i = 0; i < BOARD_SIZE; i++)
        print_mapenemy(enemy, i + 1);
    my_putchar('\n');
}
