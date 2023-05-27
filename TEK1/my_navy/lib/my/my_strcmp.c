/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** compare two string in ascii
*/

int my_strlen(char const *str);

static int is_sup(int n1, int n2)
{
    if (n1 < n2) {
        return 1;
    } else if (n1 > n2) {
        return -1;
    } else {
        return 0;
    }
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int c1;
    int c2;
    int result;

    while ((s1[i] != '\0') && (s2[i] != '\0')) {
        c1 = s1[i];
        c2 = s2[i];
        result = is_sup(c1, c2);
        if (result != 0) {
            return result;
        }
        i++;
    }
    result = is_sup(my_strlen(s1), my_strlen(s2));
    if (result != 0)
        return result;
    return 0;
}
