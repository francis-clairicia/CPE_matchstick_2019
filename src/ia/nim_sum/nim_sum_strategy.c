/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** nim_sum_strategy.c
*/

#include "matchstick.h"

int break_the_strategy(input_t *input, int const nb_sticks[], int max_matches)
{
    int lines_greather_than_one = 0;
    int lines_one = 0;
    int i = 1;

    while (nb_sticks[i] != END_OF_INT_TAB) {
        lines_greather_than_one += (nb_sticks[i] > 1);
        lines_one += (nb_sticks[i] == 1);
        input->line = (nb_sticks[i] > 1) ? i : input->line;
        i += 1;
    }
    if (lines_greather_than_one > 1)
        return (0);
    if (lines_greather_than_one == 0)
        input->line = random_line(i - 1, nb_sticks);
    else
        input->matches = nb_sticks[input->line] - (lines_one % 2 == 0);
    return (input->matches <= max_matches);
}

int nim_sum_strategy(input_t *input, int const nb_sticks[], int max_matches)
{
    int balance = 0;
    int copy_sticks[array_size(nb_sticks) + 1];

    input->line = 1;
    input->matches = 1;
    if (break_the_strategy(input, nb_sticks, max_matches))
        return (1);
    balance = get_balance(nb_sticks);
    copy_array(copy_sticks, nb_sticks);
    if (balance != 0)
        return (balance_gameboard(input, copy_sticks, max_matches));
    return (0);
}