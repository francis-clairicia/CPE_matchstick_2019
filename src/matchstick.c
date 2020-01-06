/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** matchstick.c
*/

#include "matchstick.h"

int matchstick(int nb_lines, int max_nb_matches)
{
    int output = 0;
    gameboard_t gameboard;
    input_t input;

    if (!init_gameboard(&gameboard, nb_lines, max_nb_matches))
        return (84);
    while (output == 0) {
        print_gameboard(gameboard);
        if (!get_input(&input, gameboard))
            break;
        remove_matches("Player", gameboard, input);
    }
    free_map(gameboard.map, gameboard.nb_lines);
    return (output);
}