/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** print_gameboard.c
*/

#include "matchstick.h"

static void print_horizontal_side(int nb_cols)
{
    int i = 0;

    while (i < nb_cols + 2) {
        my_putchar('*');
        i += 1;
    }
    my_putchar('\n');
}

void print_gameboard(gameboard_t gameboard)
{
    int i = 0;

    print_horizontal_side(gameboard.nb_cols);
    while (i < gameboard.nb_lines) {
        my_putchar('*');
        my_putstr(gameboard.map[i]);
        my_putchar('*');
        my_putchar('\n');
        i += 1;
    }
    print_horizontal_side(gameboard.nb_cols);
}