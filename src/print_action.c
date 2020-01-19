/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** print_action.c
*/

#include "matchstick.h"

void print_action(char const *player, input_t input)
{
    int match = input.matches;
    int line = input.line;

    my_printf("%s removed %d match(es) from line %d\n", player, match, line);
}