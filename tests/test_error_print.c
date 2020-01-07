/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** test_error_print.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "matchstick.h"

Test(error_invalid_input, called_when_the_input_was_invalid)
{
    char error[] = "Error: invalid input (positive number expected)\n";

    cr_redirect_stdout();
    error_invalid_input(NULL);
    cr_assert_stdout_eq_str(error);
}

Test(error_line_out_of_range, called_when_the_input_was_invalid)
{
    char error[] = "Error: this line is out of range\n";

    cr_redirect_stdout();
    error_line_out_of_range(NULL);
    cr_assert_stdout_eq_str(error);
}

Test(error_at_least_one_match, called_when_the_input_was_invalid)
{
    char error[] = "Error: you have to remove at least one match\n";

    cr_redirect_stdout();
    error_at_least_one_match(NULL);
    cr_assert_stdout_eq_str(error);
}

Test(error_not_enought_matches, called_when_the_input_was_invalid)
{
    char error[] = "Error: not enough matches on this line\n";

    cr_redirect_stdout();
    error_not_enought_matches(NULL);
    cr_assert_stdout_eq_str(error);
}

Test(error_too_much_matches, called_when_the_input_was_invalid)
{
    char error[] = "Error: you cannot remove more than 5 matches per turn\n";

    cr_redirect_stdout();
    error_too_much_matches(NULL, 5);
    cr_assert_stdout_eq_str(error);
}