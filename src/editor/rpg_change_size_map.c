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

void change_size_map (void)
{
    int old_size_y = my_arraylen(all_editor()->map_bg);
    int old_size_x = my_strlen(all_editor()->map_bg[0]);
    while (all_editor()->size_edit.y > old_size_y) {
        add_new_y(all_editor()->map_bg, old_size_y, all_editor()->value_to_print);
        add_new_y(all_editor()->map_mg, old_size_y, 'R');
        add_new_y(all_editor()->map_fg, old_size_y++, 'R');
    }
    while (all_editor()->size_edit.y < old_size_y) {
        delete_y(all_editor()->map_bg, old_size_y);
        delete_y(all_editor()->map_mg, old_size_y);
        delete_y(all_editor()->map_fg, old_size_y--);
    }
    while (all_editor()->size_edit.x > old_size_x) {
        add_new_x(all_editor()->map_bg, old_size_x, all_editor()->value_to_print);
        add_new_x(all_editor()->map_mg, old_size_x, 'R');
        add_new_x(all_editor()->map_fg, old_size_x++, 'R');
    }
    while (all_editor()->size_edit.x < old_size_x) {
        delete_x(all_editor()->map_bg, old_size_x);
        delete_x(all_editor()->map_mg, old_size_x);
        delete_x(all_editor()->map_fg, old_size_x--);
    }
}

// pb valgrind, augmente size bg en y pas de texture sur la derniere tile de droite