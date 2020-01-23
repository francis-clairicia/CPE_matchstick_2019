/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** find_largest_balance.c
*/

#include "matchstick.h"

static int get_max_of_mask(int balance)
{
    int mask = 1;

    while (mask <= balance)
        mask = mask << 1;
    return (mask);
}

int find_largest_unbalanced(int balance)
{
    int mask = 1;
    int max_mask = get_max_of_mask(balance);
    int largest = 0;

    do {
        while ((balance & mask) == 0 && mask <= max_mask)
            mask = mask << 1;
        if (mask <= max_mask)
            largest = mask;
        mask = mask << 1;
    } while (mask <= max_mask);
    return (largest);
}