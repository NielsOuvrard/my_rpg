/*
** EPITECH PROJECT, 2022
** snake_no_map.c
** File description:
** snake level 0
*/

#include "my.h"
#include "rpg_header.h"

void editor_click_infos_right_4 (sfVector2i pos_mouse, bool views)
{
    if (views)
        all_editor()->size_edit.y++;
    else
        all_editor()->size_edit.y--;
    return;
}

void editor_click_infos_right_3 (sfVector2i pos_mouse, bool views)
{
    if (pos_mouse.y <= 190) {
        if (views) {
            all_editor()->v_bg = all_editor()->v_bg ? false : true;
        } else {
            all_editor()->edit_ground = 'b';
            all_editor()->ptr_map_edit = all_editor()->map_bg;
        }
        return;
    }
    if (pos_mouse.y <= 230) {
        if (views)
            all_editor()->size_edit.x++;
        else
            all_editor()->size_edit.x--;
        return;
    }
    return editor_click_infos_right_4(pos_mouse, views);
}

int editor_click_infos_right_2 (sfVector2i pos_mouse, bool views)
{
    if (pos_mouse.y <= 130) {
        if (views) {
            all_editor()->v_mg = all_editor()->v_mg ? false : true;
        } else {
            all_editor()->edit_ground = 'm';
            all_editor()->ptr_map_edit = all_editor()->map_mg;
        }
        return 1;
    }
    return 0;
}

void editor_click_infos_right (sfVector2i pos_mouse)
{
    bool views = false;
    if (pos_mouse.x >= 1920 - 50)
        views = true;
    if (pos_mouse.y <= 80) {
        if (views) {
            all_editor()->v_fg = all_editor()->v_fg ? false : true;
        } else {
            all_editor()->edit_ground = 'f';
            all_editor()->ptr_map_edit = all_editor()->map_fg;
        }
        return;
    }
    if (editor_click_infos_right_2(pos_mouse, views))
        return;
    editor_click_infos_right_3(pos_mouse, views);
}
