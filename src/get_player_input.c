/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** get_player_input.c
*/

#include "matchstick.h"

static int get_line(input_t *input, int nb_lines)
{
    char *line = NULL;

    my_putstr("Line: ");
    if (!get_next_line(&line, 0))
        return (-1);
    if (my_strlen(line) == 0 || !my_str_isnum(line))
        return (error_invalid_input(line));
    input->line = my_getnbr(line);
    if (input->line < 1 || input->line > nb_lines)
        return (error_line_out_of_range(line));
    free(line);
    return (1);
}

static int get_matches(input_t *input, int nb_matches, int max_match)
{
    char *line = NULL;

    my_putstr("Matches: ");
    if (!get_next_line(&line, 0))
        return (-1);
    if (my_strlen(line) == 0 || !my_str_isnum(line))
        return (error_invalid_input(line));
    input->matches = my_getnbr(line);
    if (input->matches <= 0)
        return (error_at_least_one_match(line));
    if (input->matches > max_match)
        return (error_too_many_matches(line, max_match));
    if (input->matches > nb_matches)
        return (error_not_enough_matches(line));
    free(line);
    return (1);
}

int get_player_input(input_t *input, gameboard_t gb)
{
    int valid = 0;
    int matches = 0;

    while (1) {
        valid = get_line(input, gb.nb_lines);
        if (valid < 0)
            return (0);
        else if (!valid)
            continue;
        matches = get_nb_sticks(gb.map, input->line);
        valid = get_matches(input, matches, gb.max_nb_matches);
        if (valid < 0)
            return (0);
        else if (!valid)
            continue;
        break;
    }
    print_action("Player", *input);
    return (1);
}