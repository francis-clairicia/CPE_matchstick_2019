/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** get_balance.c
*/

#include "matchstick.h"

int get_balance(int const nb_sticks[])
{
    int balance = 0;
    int i = 1;

    while (nb_sticks[i] != END_OF_INT_TAB) {
        balance ^= nb_sticks[i];
        i += 1;
    }
    return (balance);
}