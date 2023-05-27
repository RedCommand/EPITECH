/*
** EPITECH PROJECT, 2021
** my_strcpy
** File description:
** copy a str into another
*/

int my_strlen(char const *str);

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;
    for (i = 0; i < n; i++) {
        dest[i] = src[i];
    }
    if (n < (my_strlen(src) - 1)) {
        dest[n] = '\0';
    }
    return dest;
}
