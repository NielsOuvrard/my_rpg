/*
** EPITECH PROJECT, 2022
** snake_no_map.c
** File description:
** snake level 0
*/

#include "my.h"
#include "rpg_header.h"

void add_new_y (char **map, int size, char c)
{
    map[size] = malloc(sizeof(char) * BUFF_SIZE);
    my_memset(map[size], BUFF_SIZE - 1, '\0');
    my_memset(map[size], all_editor()->size_edit.x, c);
}

void delete_y (char **map, int size)
{
    char *tmp = map[size - 1];
    map[size - 1] = NULL;
    free(tmp);
}

void add_new_x (char **map, int size, char c)
{
    for (int i = 0; map[i]; i++)
        map[i][size] = c;
}

void delete_x (char **map, int size)
{
    for (int i = 0; map[i]; i++)
        map[i][size - 1] = '\0';
}
