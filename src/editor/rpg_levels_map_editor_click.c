/*
** EPITECH PROJECT, 2022
** snake_no_map.c
** File description:
** snake level 0
*/

#include "my.h"
#include "rpg_header.h"

void paint_bucket_tool (void)
{
    free_my_arr(all_editor()->ptr_map_edit);
    if (all_editor()->edit_ground == 'b') {
        all_editor()->map_bg = editor_create_map(
        all_editor()->size_edit.x, all_editor()->size_edit.y,
        all_editor()->value_to_print);
        all_editor()->ptr_map_edit = all_editor()->map_bg;
    } else if (all_editor()->edit_ground == 'm') {
        all_editor()->map_mg = editor_create_map(
        all_editor()->size_edit.x, all_editor()->size_edit.y,
        all_editor()->value_to_print);
        all_editor()->ptr_map_edit = all_editor()->map_mg;
    } else {
        all_editor()->map_fg = editor_create_map(
        all_editor()->size_edit.x, all_editor()->size_edit.y,
        all_editor()->value_to_print);
        all_editor()->ptr_map_edit = all_editor()->map_fg;
    }
}

void la_bonne_touche_editor (sfEvent event)
{
    if (!(event.type == sfEvtKeyPressed))
        return;
    if (event.key.code == sfKeyEscape) {
        free_my_arr(all_editor()->map_bg);
        free_my_arr(all_editor()->map_mg);
        free_my_arr(all_editor()->map_fg);
        all_editor()->map_bg = NULL;
        all_editor()->map_mg = NULL;
        all_editor()->map_fg = NULL;
        all_infos()->level = 0;
    }
    if (event.key.code == sfKeyN && all_editor()->ptr_map_edit)
        paint_bucket_tool();
}
