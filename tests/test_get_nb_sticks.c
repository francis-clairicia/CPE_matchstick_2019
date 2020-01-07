/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** test_get_nb_sticks.c
*/

#include <criterion/criterion.h>
#include "matchstick.h"

Test(get_nb_sticks, count_how_many_sticks_are_in_a_line)
{
    char *map[] = {
        " | | | ",
        " | ",
        "         ",
    };

    cr_expect_eq(get_nb_sticks(map, 1), 3);
    cr_expect_eq(get_nb_sticks(map, 2), 1);
    cr_expect_eq(get_nb_sticks(map, 3), 0);
}