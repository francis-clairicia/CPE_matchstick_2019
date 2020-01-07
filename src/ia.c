/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** ia.c
*/

#include <time.h>
#include "matchstick.h"

void ia_playing(gameboard_t gameboard, input_t *input)
{
    int nb_sticks;

    srandom(time(0));
    input->line = random() % gameboard.nb_lines;
    while ((nb_sticks = get_nb_sticks(gameboard.map[input->line])) == 0)
        input->line = random() % gameboard.nb_lines;
    input->matches = (random() % nb_sticks) + 1;
}