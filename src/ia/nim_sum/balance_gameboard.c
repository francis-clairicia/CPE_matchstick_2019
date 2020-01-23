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

static int get_matches(int balance)
{
    int mask = 1;
    int matches = 1;

    while (balance != 0) {
        if (balance & mask) {
            balance ^= mask;
            matches += mask;
        } else
            mask = mask << 1;
    }
    return (matches);
}

int balance_gameboard(input_t *input, int const nb_sticks[], int max_matches)
{
    int balance = get_balance(nb_sticks);
    int largest_unbalanced = find_largest_unbalanced(balance);
    int line = choose_line_to_delete(nb_sticks, largest_unbalanced);
    int matches = 0;

    if (line < 0)
        return (0);
    matches = get_matches(balance);
    if (matches > max_matches)
        return (0);
    input->line = line;
    input->matches = matches;
    return (1);
}