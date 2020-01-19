/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** play.c
*/

#include <time.h>
#include "matchstick.h"

static void get_sticks(gameboard_t gameboard, int *nb_sticks)
{
    int i = 0;

    nb_sticks[0] = 0;
    while (i < gameboard.nb_lines) {
        nb_sticks[i + 1] = get_nb_sticks(gameboard.map, i + 1);
        i += 1;
    }
}

static void full_random_strategy(gameboard_t gameboard, input_t *input,
    int *nb_sticks)
{
    srandom(time(NULL));
    do
        input->line = (random() % gameboard.nb_lines) + 1;
    while (nb_sticks[input->line] == 0);
    do
        input->matches = (random() % nb_sticks[input->line]) + 1;
    while (input->matches > gameboard.max_nb_matches);
}

void ia_playing(gameboard_t gameboard, input_t *input)
{
    int nb_lines = gameboard.nb_lines;
    int nb_sticks[nb_lines + 1];

    get_sticks(gameboard, nb_sticks);
    full_random_strategy(gameboard, input, nb_sticks);
    print_action("AI", *input);
}