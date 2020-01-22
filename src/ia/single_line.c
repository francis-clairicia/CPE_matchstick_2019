/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** single_line.c
*/

#include "matchstick.h"

static int find_the_last_line(int const nb_sticks[])
{
    int i = 0;

    while (nb_sticks[i] == 0)
        i += 1;
    return (i);
}

void play_single_line(input_t *input, int const nb_sticks[], int max_matches)
{
    int last_line = find_the_last_line(nb_sticks);

    input->line = last_line;
    if (nb_sticks[last_line] <= max_matches)
        input->matches = nb_sticks[last_line] - 1;
    else
        input->matches = max_matches;
    if (input->matches == 0)
        input->matches = 1;
}