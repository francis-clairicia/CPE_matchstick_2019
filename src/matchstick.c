/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** matchstick.c
*/

#include "matchstick.h"

static int change_active_player(int player)
{
    player += (player == 1) ? -1 : 1;
    return (player);
}

static int play(char const *player, char const *turn, gameboard_t gameboard)
{
    input_t input;

    my_printf("\n%s\n", turn);
    if (my_strcmp(player, "AI") == 0)
        ia_playing(gameboard, &input);
    else if (!get_player_input(&input, gameboard))
        return (1);
    print_action(player, input);
    remove_matches(gameboard, input);
    return (0);
}

int matchstick(int nb_lines, int max_nb_matches)
{
    char *players[] = {"Player", "AI"};
    char *turn[] = {"Your turn:", "AI's turn..."};
    int active = -1;
    int output = 0;
    int quit_game = 0;
    gameboard_t gameboard;

    if (!init_gameboard(&gameboard, nb_lines, max_nb_matches))
        return (84);
    while (!quit_game && output == 0) {
        print_gameboard(gameboard);
        active = change_active_player(active);
        output = check_game_status(players[active], gameboard);
        if (output == 0)
            quit_game = play(players[active], turn[active], gameboard);
    }
    free_map(gameboard.map, gameboard.nb_lines);
    return (output);
}