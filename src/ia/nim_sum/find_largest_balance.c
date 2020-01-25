/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** find_largest_balance.c
*/

#include "matchstick.h"

int find_largest_unbalanced(int balance)
{
    int mask = 1;
    int largest = 0;

    do {
        while ((balance & mask) == 0 && mask <= balance)
            mask = mask << 1;
        if (mask <= balance)
            largest = mask;
        mask = mask << 1;
    } while (mask <= balance);
    return (largest);
}