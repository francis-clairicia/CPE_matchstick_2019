/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** matchstick.h
*/

#ifndef HEADER_MATCHSTICK
#define HEADER_MATCHSTICK

#include <stdlib.h>
#include "my.h"
#include "my_printf.h"

typedef struct gameboard
{
    int nb_lines;
    int nb_cols;
    char **map;
    int max_nb_matches;
} gameboard_t;

typedef struct input
{
    int line;
    int matches;
} input_t;

int matchstick(int nb_lines, int max_nb_matches);
int get_player_input(input_t *input, gameboard_t gameboard);
int get_nb_sticks(char **map, int line_index);
void print_action(char const *player, input_t input);
void remove_matches(gameboard_t gb, input_t input);
int check_game_status(char const *player_who_wins, gameboard_t gameboard);

int init_gameboard(gameboard_t *gb, int nb_lines, int max_nb_matches);
void print_gameboard(gameboard_t gameboard);
void free_map(char **map, int nb_lines);

int print_error_and_returns(char const *error, int status);
int error_invalid_input(char *line);
int error_line_out_of_range(char *line);
int error_not_enought_matches(char *line);
int error_at_least_one_match(char *line);
int error_too_many_matches(char *line, int max_nb_matches);

void ia_playing(gameboard_t gameboard, input_t *input);

#endif