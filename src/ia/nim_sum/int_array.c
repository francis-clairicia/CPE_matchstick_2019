/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** int_array.c
*/

#include "matchstick.h"

int array_size(int const *nb_sticks)
{
    int i = 0;

    while (nb_sticks != NULL && nb_sticks[i] != END_OF_INT_TAB)
        i += 1;
    return (i);
}

int *copy_array(int *dest, int const *src)
{
    int i = 0;

    if (src == NULL || dest == NULL)
        return (NULL);
    while (src[i] != END_OF_INT_TAB) {
        dest[i] = src[i];
        i += 1;
    }
    dest[i] = END_OF_INT_TAB;
    return (dest);
}