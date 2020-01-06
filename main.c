/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** main.c
*/

#include "matchstick.h"

static int print_help(int ac, char **av)
{
    if (ac < 2)
        return (0);
    if (my_strcmp(av[1], "-h") != 0)
        return (0);
    my_putstr("USAGE\n");
    my_putstr("\t./matchstick nb_lines max_nb_matches\n\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tThe Matchstick game in taking matches.\n");
    my_putstr("\tThe object of the game is not to take the last match\n\n");
    my_putstr("OPTIONS\n");
    my_putstr("\tnb_lines\tThe number of matches lines\n");
    my_putstr("\tmax_nb_matches\tThe maximum number of matches that ");
    my_putstr("can be taken out each turn\n");
    return (1);
}

static int valid_args(int ac, char **av)
{
    if (ac != 3 || !my_str_isnum(av[1]) || !my_str_isnum(av[2]))
        return (0);
    if (my_getnbr(av[1]) <= 1 || my_getnbr(av[1]) >= 100)
        return (0);
    if (my_getnbr(av[2]) <= 0)
        return (0);
    return (1);
}

int main(int ac, char *av[])
{
    if (print_help(ac, av))
        return (0);
    if (!valid_args(ac, av))
        return (84);
    return (matchstick(my_getnbr(av[1]), my_getnbr(av[2])));
}