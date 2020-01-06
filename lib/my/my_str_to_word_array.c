/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** Split a string in a word array
*/

#include <stdlib.h>
#include "my.h"

static int is_alphanum(char c)
{
    if (my_find_char("0123456789", c) >= 0)
        return (1);
    if (my_find_char("abcdefghijklmnopqrstuvwxyz", c) >= 0)
        return (1);
    if (my_find_char("ABCDEFGHIJKLMNOPQRSTUVWXYZ", c) >= 0)
        return (1);
    return (0);
}

int get_nb_words(char const *str)
{
    int nb = 1;
    int i = 0;

    while (str[i] != '\0') {
        if (is_alphanum(str[i])) {
            i += 1;
            continue;
        }
        nb += 1;
        while (!is_alphanum(str[i]))
            i += 1;
    }
    return (nb);
}

int get_index_end_word(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (is_alphanum(str[i]))
            i += 1;
        else
            break;
    }
    return (i);
}

void generate_array(char **array, char const *str, int nb_words)
{
    int i = 0;
    int index_word;

    while (i < nb_words) {
        index_word = get_index_end_word(str);
        array[i] = my_strndup(str, index_word);
        index_word += 1;
        while (!is_alphanum(str[index_word]))
            index_word += 1;
        str = &str[index_word];
        i += 1;
    }
}

char **my_str_to_word_array(char const *str)
{
    int nb_words;
    char **array;

    if (str == NULL)
        return (NULL);
    nb_words = get_nb_words(str);
    array = malloc(sizeof(char *) * (nb_words + 1));
    if (array == NULL)
        return (NULL);
    generate_array(array, str, nb_words);
    array[nb_words] = NULL;
    return (array);
}
