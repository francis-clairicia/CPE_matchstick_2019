/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** matchstick.c
*/

#include "matchstick.h"

static int change_active_player(int player)
{
    char *player_turn[] = {
        "Your turn:",
        "AI's turn..."
    };

    player += (player == 1) ? -1 : 1;
    my_printf("\n%s\n", player_turn[player]);
    return (player);
}

static int play(char const *player, int gameplay_status,
    gameboard_t gameboard, input_t input)
{
    if (gameplay_status != 0)
        return (1);
    if (my_strcmp(player, "AI") == 0)
        ia_playing(gameboard, &input);
    else if (!get_player_input(&input, gameboard))
        return (1);
    remove_matches(gameboard, input);
    return (0);
}

int matchstick(int nb_lines, int max_nb_matches)
{
    int output = 0;
    int quit_game = 0;
    gameboard_t gameboard;
    input_t input;
    char *players[] = {"Player", "AI"};
    int active_player = -1;

    if (!init_gameboard(&gameboard, nb_lines, max_nb_matches))
        return (84);
    while (!quit_game) {
        print_gameboard(gameboard);
        active_player = change_active_player(active_player);
        output = check_game_status(players[active_player], gameboard);
        quit_game = play(players[active_player], output, gameboard, input);
    }
    free_map(gameboard.map, gameboard.nb_lines);
    return (output);
}