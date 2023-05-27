/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** print an str
*/

void my_putchar(char c);
int my_strlen(char const *str);

/* int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return 0;
} */

int my_putstr(char const *str)
{
    int lenstr = my_strlen(str);

    write(1, str, lenstr);
    return 0;
}

int my_put_nstr(char const *str, int nb)
{
    int lenstr = my_strlen(str);

    if (lenstr > nb) {
        my_putstr(str);
    } else {
        for (int i = 0; i < nb - lenstr; i++) {
            my_putchar(' ');
        }
        my_putstr(str);
    }
    return 0;
}