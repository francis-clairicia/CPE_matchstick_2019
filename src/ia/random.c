/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** random.c
*/

#include "matchstick.h"

int random_line(int nb_lines_gameboard, int const nb_sticks[])
{
    int line = 0;

    do
        line = (random() % nb_lines_gameboard) + 1;
    while (nb_sticks[line] == 0);
    return (line);
}

int random_match(int nb_matches_in_line, int max_nb_matches_per_turn)
{
    int matches = 0;

    do
        matches = (random() % nb_matches_in_line) + 1;
    while (matches > max_nb_matches_per_turn);
    return (matches);
}