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
    my_printf("Error: invalid input (positive number expected)\n");
    return (0);
}

int error_line_out_of_range(void)
{
    my_printf("Error: this line is out of range\n");
    return (0);
}

int error_not_enough_matches(void)
{
    my_printf("Error: not enough matches on this line\n");
    return (0);
}

int error_at_least_one_match(void)
{
    my_printf("Error: you have to remove at least one match\n");
    return (0);
}

int error_too_many_matches(int max_nb_matches)
{
    my_printf("Error: you cannot remove more than %d matches per turn\n",
        max_nb_matches);
    return (0);
}