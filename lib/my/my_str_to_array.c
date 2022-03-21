/*
** EPITECH PROJECT, 2021
** my_str_to_array.c
** File description:
** str to array of str
*/

#include "my.h"
#include <stdlib.h>

void str_to_array_next (char ** map, char *str, int *i, int *i_map)
{
    int sz;
    for (sz = 0; str[(*i) + sz] != '\0' && str[(*i) + sz] != ' '
    && str[(*i) + sz] != '\t' && str[(*i) + sz] != '\n'; sz++);
    if (sz == 0)
        return;
    map[(*i_map)] = malloc(sizeof(char) * (sz + 1));
    my_memset(map[(*i_map)], sz + 1, '\0');
    for (int j = 0; j < sz; j++)
        map[(*i_map)][j] = str[(*i) + j];
    (*i_map)++;
    if (str[(*i) + sz] == '\0')
        (*i)--;
    (*i) += sz;
    return;
}

char **str_to_array (char *str)
{
    int k = 0, size, i_map = 0;
    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        int tmp = 0;
        while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t')) {
            tmp = 1;
            i++;
        }
        k += tmp;
    }
    char **map = malloc(sizeof(char *) * (k + 2));
    for (int i = 0; str[i] != '\0'; i++)
        str_to_array_next(map, str, &i, &i_map);
    map[i_map] = NULL;
    return map;
}
