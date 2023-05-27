/*
** EPITECH PROJECT, 2021
** my_put_float
** File description:
** print float nbr
*/

void my_putchar(char c);
int my_put_nbr(int nb);

void my_put_float(float nb)
{
    int int_nb = nb;
    int float_nb = ((nb * 100) - (int_nb * 100));

    my_put_nbr(int_nb);
    my_putchar('.');
    my_put_nbr(float_nb);
}
