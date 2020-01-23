/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** play.c
*/

#include <time.h>
#include "matchstick.h"

static int get_sticks(gameboard_t gameboard, int *nb_sticks)
{
    int i = 1;
    int nb_lines_with_sticks = 0;

    nb_sticks[0] = 0;
    while (i <= gameboard.nb_lines) {
        nb_sticks[i] = get_nb_sticks(gameboard.map, i);
        nb_lines_with_sticks += (nb_sticks[i] > 0);
        i += 1;
    }
    nb_sticks[i] = END_OF_INT_TAB;
    return (nb_lines_with_sticks);
}

void ia_playing(gameboard_t gameboard, input_t *input)
{
    int nb_lines = gameboard.nb_lines;
    int max_matches = gameboard.max_nb_matches;
    int nb_sticks[nb_lines + 2];
    int nb_lines_with_sticks = get_sticks(gameboard, nb_sticks);

    if (nb_lines_with_sticks == 1)
        play_single_line(input, nb_sticks, max_matches);
    else if (!nim_sum_strategy(input, nb_sticks, max_matches)
    || input->matches <= 0) {
        input->line = random_line(nb_lines, nb_sticks);
        input->matches = random_match(nb_sticks[input->line], max_matches);
    }
    print_action("AI", *input);
}