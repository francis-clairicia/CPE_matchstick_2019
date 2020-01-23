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

long int random(void);
void srandom(unsigned int seed);

#define BALANCED 0
#define UNBALANCED 1

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

#define END_OF_INT_TAB -1

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
int error_not_enough_matches(char *line);
int error_at_least_one_match(char *line);
int error_too_many_matches(char *line, int max_nb_matches);

void ia_playing(gameboard_t gameboard, input_t *input);
void play_single_line(input_t *input, int const nb_sticks[], int max_matches);
int random_line(int nb_lines_gameboard, int const nb_sticks[]);
int random_match(int nb_matches_in_line, int max_nb_matches_per_turn);

int nim_sum_strategy(input_t *input, int const nb_sticks[], int max_matches);
int get_balance(int const nb_sticks[]);
int find_largest_unbalanced(int balance);
int balance_gameboard(input_t *input, int nb_sticks[], int max_matches);

int array_size(int const *nb_sticks);
int *copy_array(int *dest, int const *src);

#endif