/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** matchstick.c
*/

#include "matchstick.h"

static int change_active_player(int player)
{
    player += 1;
    if (player == 2)
        player = 0;
    return (player);
}

int matchstick(int nb_lines, int max_nb_matches)
{
    int output = 0;
    gameboard_t gameboard;
    input_t input;
    char *players[] = {"Player", "AI"};
    int active_player = -1;

    if (!init_gameboard(&gameboard, nb_lines, max_nb_matches))
        return (84);
    while (output == 0) {
        active_player = change_active_player(active_player);
        print_gameboard(gameboard);
        output = check_game_status(players[active_player], gameboard);
        if (my_strcmp(players[active_player], "AI") == 0)
            ia_playing(gameboard, &input);
        else if (output != 0 || !get_input(&input, gameboard))
            break;
        remove_matches(players[active_player], gameboard, input);
    }
    free_map(gameboard.map, gameboard.nb_lines);
    return (output);
}