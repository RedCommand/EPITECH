/*
** EPITECH PROJECT, 2021
** my_stnrcpy
** File description:
** copy n char of a str into another
*/

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src)
{
    int i;
    int length = my_strlen(src);

    for (i = 0; i <= length - 1; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
