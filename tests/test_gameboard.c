/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** test_gameboard.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "matchstick.h"

Test(init_gameboard, fill_the_gameboard_structure)
{
    gameboard_t gameboard;

    cr_assert_eq(init_gameboard(&gameboard, 2, 5), 1);
    cr_expect_eq(gameboard.nb_lines, 2);
    cr_expect_eq(gameboard.nb_cols, 3);
    cr_expect_eq(gameboard.max_nb_matches, 5);
    cr_expect_str_eq(gameboard.map[0], " | ");
    cr_expect_str_eq(gameboard.map[1], "|||");
    free_map(gameboard.map, gameboard.nb_lines);
}

Test(print_gameboard, print_the_matchstick_gameboard)
{
    gameboard_t gameboard;
    char expected_map[] = "***********\n"
        "*    |    *\n"
        "*   |||   *\n"
        "*  |||||  *\n"
        "* ||||||| *\n"
        "*|||||||||*\n"
        "***********\n";

    cr_redirect_stdout();
    cr_assert_eq(init_gameboard(&gameboard, 5, 5), 1);
    print_gameboard(gameboard);
    cr_expect_stdout_eq_str(expected_map);
    free_map(gameboard.map, gameboard.nb_lines);
}