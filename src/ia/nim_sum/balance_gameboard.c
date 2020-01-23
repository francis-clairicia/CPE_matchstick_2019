/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** balance_gameboard.c
*/

#include "matchstick.h"

static int choose_line_to_delete(int const nb_sticks[], int largest_u)
{
    int no_line = -1;
    int i = 1;

    while (nb_sticks[i] != END_OF_INT_TAB) {
        if (nb_sticks[i] & largest_u)
            return (i);
        i += 1;
    }
    return (no_line);
}

static int get_default_matches(int value, int largest_u)
{
    int mask = 1;
    int matches = 0;

    while ((largest_u & mask) == 0) {
        if (value & mask)
            matches += mask;
        mask = mask << 1;
    }
    return (matches);
}

static void next_matchstick_line(int const nb_sticks[], int *line, int l_u)
{
    do {
        *line += 1;
    } while ((nb_sticks[*line] & l_u) == 0);
}

static int get_matches(int nb_sticks[], int *line, int largest_u)
{
    int balance = get_balance(nb_sticks);
    int matches = get_default_matches(nb_sticks[*line], largest_u);
    int save_nb_sticks = nb_sticks[*line];

    nb_sticks[*line] -= matches;
    while ((balance = get_balance(nb_sticks)) != 0) {
        nb_sticks[*line] -= 1;
        matches += 1;
        if (nb_sticks[*line] == 0) {
            nb_sticks[*line] = save_nb_sticks;
            next_matchstick_line(nb_sticks, line, largest_u);
            save_nb_sticks = nb_sticks[*line];
            matches = get_default_matches(nb_sticks[*line], largest_u);
            nb_sticks[*line] -= matches;
        }
        if (nb_sticks[*line] < 0)
            return (-1);
    }
    return (matches);
}

int balance_gameboard(input_t *input, int nb_sticks[], int max_matches)
{
    int balance = get_balance(nb_sticks);
    int largest_unbalanced = find_largest_unbalanced(balance);
    int line = choose_line_to_delete(nb_sticks, largest_unbalanced);
    int matches = 0;

    if (line < 0)
        return (0);
    matches = get_matches(nb_sticks, &line, largest_unbalanced);
    if (matches <= 0 || matches > max_matches)
        return (0);
    input->line = line;
    input->matches = matches;
    return (1);
}