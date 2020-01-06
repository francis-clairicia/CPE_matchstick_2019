/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** error.c
*/

#include "matchstick.h"

int error_invalid_input(char *line)
{
    free(line);
    my_putstr("Error: invalid input (positive number expected)\n");
    return (0);
}

int error_line_out_of_range(char *line)
{
    free(line);
    my_putstr("Error: this line is out of range\n");
    return (0);
}

int error_not_enought_matches(char *line)
{
    free(line);
    my_putstr("Error: not enough matches on this line\n");
    return (0);
}

int error_at_least_one_match(char *line)
{
    free(line);
    my_putstr("Error: you have to remove at least one match\n");
    return (0);
}

int error_too_much_matches(char *line, int max_nb_matches)
{
    free(line);
    my_putstr("Error: you cannot remove more than ");
    my_put_nbr(max_nb_matches);
    my_putstr(" matches per turn\n");
    return (0);
}