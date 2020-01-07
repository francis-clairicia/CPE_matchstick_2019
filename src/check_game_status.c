/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** check_game_status.c
*/

#include "matchstick.h"

int check_game_status(char const *player_who_wins, gameboard_t gameboard)
{
    int i = 0;
    int status = 0;

    while (i < gameboard.nb_lines) {
        if (my_find_char(gameboard.map[i], '|') >= 0)
            return (status);
        i += 1;
    }
    if (my_strcmp(player_who_wins, "Player") == 0) {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        status = 1;
    } else if (my_strcmp(player_who_wins, "AI") == 0) {
        my_putstr("You lost, too bad...\n");
        status = 2;
    } else
        return (-1);
    return (status);
}