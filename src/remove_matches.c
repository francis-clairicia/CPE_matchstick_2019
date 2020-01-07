/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** remove_matches.c
*/

#include "matchstick.h"

static void print_action(char const *player, input_t input)
{
    my_putstr(player);
    my_putstr(" removed ");
    my_put_nbr(input.matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(input.line + 1);
    my_putchar('\n');
}

static int search_match_to_the_right(char *line)
{
    int i = my_strlen(line) - 1;

    while (line[i] != '|')
        i -= 1;
    return (i);
}

void remove_matches(char const *player, gameboard_t gb, input_t input)
{
    int index_pipe = search_match_to_the_right(gb.map[input.line]);
    int i = 0;

    print_action(player, input);
    while (i < input.matches) {
        gb.map[input.line][index_pipe] = ' ';
        i += 1;
        index_pipe -= 1;
    }
}