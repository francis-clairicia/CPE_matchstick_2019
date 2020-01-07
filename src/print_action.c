/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** print_action.c
*/

#include "matchstick.h"

void print_action(char const *player, input_t input)
{
    my_putstr(player);
    my_putstr(" removed ");
    my_put_nbr(input.matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(input.line);
    my_putchar('\n');
}