/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** test_check_game_status.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "matchstick.h"

Test(check_game_status, returns_0_if_the_game_is_continuing)
{
    gameboard_t gameboard;

    cr_assert_eq(init_gameboard(&gameboard, 2, 2), 1);
    cr_expect_eq(check_game_status("", gameboard), 0);
    free_map(gameboard.map, gameboard.nb_lines);
}

Test(check_game_status, returns_1_if_the_player_1_wins)
{
    gameboard_t gameboard;

    cr_redirect_stdout();
    cr_assert_eq(init_gameboard(&gameboard, 2, 2), 1);
    remove_matches(gameboard, (input_t){1, 1});
    remove_matches(gameboard, (input_t){2, 3});
    cr_expect_eq(check_game_status("Player", gameboard), 1);
    cr_expect_stdout_eq_str("I lost... snif... but I'll get you next time!!\n");
    free_map(gameboard.map, gameboard.nb_lines);
}

Test(check_game_status, returns_2_if_ai_wins)
{
    gameboard_t gameboard;

    cr_redirect_stdout();
    cr_assert_eq(init_gameboard(&gameboard, 2, 2), 1);
    remove_matches(gameboard, (input_t){1, 1});
    remove_matches(gameboard, (input_t){2, 3});
    cr_expect_eq(check_game_status("AI", gameboard), 2);
    cr_expect_stdout_eq_str("You lost, too bad...\n");
    free_map(gameboard.map, gameboard.nb_lines);
}

Test(check_game_status, returns_negative_value_if_player_is_unkown)
{
    gameboard_t gameboard;

    cr_assert_eq(init_gameboard(&gameboard, 2, 2), 1);
    remove_matches(gameboard, (input_t){1, 1});
    remove_matches(gameboard, (input_t){2, 3});
    cr_expect_eq(check_game_status("Family Guy", gameboard), -1);
    free_map(gameboard.map, gameboard.nb_lines);
}