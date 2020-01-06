/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** gameboard.c
*/

#include "matchstick.h"

static int fill_line(char *line, int nb_cols, int middle)
{
    static int nb_sticks = 1;
    int left_side = middle - (nb_sticks / 2);
    int right_side = middle + (nb_sticks / 2);
    int i = 0;

    if (line == NULL)
        return (0);
    line[nb_cols] = '\0';
    while (i < nb_cols) {
        if (i >= left_side && i <= right_side)
            line[i] = '|';
        else
            line[i] = ' ';
        i += 1;
    }
    nb_sticks += 2;
    return (1);
}

static int init_map(char **map, int nb_lines, int nb_cols)
{
    int i = 0;
    int middle = nb_cols / 2;

    while (i < nb_lines) {
        if (!fill_line(map[i], nb_cols, middle))
            return (0);
        i += 1;
    }
    return (1);
}

int init_gameboard(gameboard_t *gb, int nb_lines, int max_nb_matches)
{
    int i = 0;

    gb->nb_lines = nb_lines;
    gb->nb_cols = (2 * nb_lines) - 1;
    gb->max_nb_matches = max_nb_matches;
    gb->map = malloc(sizeof(char *) * nb_lines);
    if (gb->map == NULL)
        return (0);
    while (i < gb->nb_lines) {
        gb->map[i] = malloc(sizeof(char) * (gb->nb_cols + 1));
        i += 1;
    }
    if (!init_map(gb->map, gb->nb_lines, gb->nb_cols)) {
        free_map(gb->map, nb_lines);
        return (0);
    }
    return (1);
}

void free_map(char **map, int nb_lines)
{
    int i = 0;

    if (map == NULL)
        return;
    while (i < nb_lines) {
        free(map[i]);
        i += 1;
    }
    free(map);
}