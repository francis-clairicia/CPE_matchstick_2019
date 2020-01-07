/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** test_print_action.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "matchstick.h"

Test(print_action, print_what_player_do)
{
    cr_redirect_stdout();
    print_action("Player", ((input_t){4, 5}));
    cr_assert_stdout_eq_str("Player removed 5 match(es) from line 4\n");
}