/*
** EPITECH PROJECT, 2022
** snake_no_map.c
** File description:
** snake level 0
*/

#include "my.h"
#include "rpg_header.h"


void change_size_map_next (int old_size_y, int old_size_x)
{
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
    change_size_map_next(old_size_y, old_size_x);
}

// pb valgrind, augmente size bg en y pas de texture
// sur la derniere tile de droite
