/*
** EPITECH PROJECT, 2021
** header_libmy
** File description:
** header for libmy
*/

#ifndef MY_H
    #define MY_H

int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_getnbr(char const *str);
int my_is_prime(int nb);
int my_is_prime(int nb);
int my_isneg(int nb);
int my_put_nbr(int nb);
int my_put_dig(int dig);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void my_sort_int_array(int *tab, int size);
int is_in_str(char *str, char c);
int my_str_isalpha(char *str);
int my_str_islower(char *str);
int my_str_isnum(char *str);
int my_str_isprintable(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char *str);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
char replace_char(char *dic_src, char *dic_dest, char c);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
void my_swap (int *a, int *b);
int is_in_str(char *str, char c);
int my_put_float(float nb);
void my_sort_int_array(int *tab, int size);
int get_int_pos(int size, int nb, int *tabl);
#endif
