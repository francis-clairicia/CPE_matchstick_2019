/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** nb_sticks.c
*/

#include "matchstick.h"

int get_nb_sticks(char *line)
{
    int i = 0;
    int count = 0;

    while (line[i] != '\0') {
        count += (line[i] == '|');
        i += 1;
    }
    return (count);
}