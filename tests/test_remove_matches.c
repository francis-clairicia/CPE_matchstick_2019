/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** test_remove_matches.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "matchstick.h"

Test(remove_matches, remove_matches_from_a_line)
{
    gameboard_t gameboard;
    char expected_map[] =
        "***********\n"
        "*         *\n"
        "*   |||   *\n"
        "*  |||||  *\n"
        "* ||||||| *\n"
        "*|||||    *\n"
        "***********\n";

    cr_redirect_stdout();
    cr_assert_eq(init_gameboard(&gameboard, 5, 5), 1);
    remove_matches(gameboard, ((input_t){5, 4}));
    remove_matches(gameboard, ((input_t){1, 1}));
    print_gameboard(gameboard);
    cr_expect_stdout_eq_str(expected_map);
    free_map(gameboard.map, gameboard.nb_lines);
}