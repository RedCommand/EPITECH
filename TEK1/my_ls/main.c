/*
** EPITECH PROJECT, 2021
** B-PSU-100-BDX-1-1-myls-maxime.senard
** File description:
** main
*/

int my_ls(int const ac, char const **av);

int main(int argc, char **argv)
{
    int success = 0;

    success = my_ls(argc, argv);
    if (success != 0)
        return 84;
    return 0;
}