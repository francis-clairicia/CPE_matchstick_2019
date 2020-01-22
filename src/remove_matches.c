/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** remove_matches.c
*/

#include "matchstick.h"

static int search_match_to_the_right(char *line)
{
    int i = my_strlen(line) - 1;

    while (line[i] != '|')
        i -= 1;
    return (i);
}

void remove_matches(gameboard_t gb, input_t input)
{
    int index_pipe = search_match_to_the_right(gb.map[input.line - 1]);
    int i = 0;

    while (i < input.matches && index_pipe >= 0) {
        gb.map[input.line - 1][index_pipe] = ' ';
        i += 1;
        index_pipe -= 1;
    }
}