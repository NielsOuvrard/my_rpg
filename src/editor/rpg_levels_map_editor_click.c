/*
** EPITECH PROJECT, 2022
** snake_no_map.c
** File description:
** snake level 0
*/

#include "my.h"
#include "rpg_header.h"

int round_sup (float a)
{
    int b = (int)a;
    if ((float)b + 0.5 < a) {
        return ++b;
    }
    return b;
}

void change_tile_to_print(sfEvent event)
{
    if (event.key.code == sfKeyNum1)
        all_editor()->value_to_print = 'g';
    if (event.key.code == sfKeyNum2)
        all_editor()->value_to_print = 'd';
    if (event.key.code == sfKeyNum3)
        all_editor()->value_to_print = 'w';
    if (event.key.code == sfKeyNum4)
        all_editor()->value_to_print = 's';
}

void le_bon_click_editor (sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed)
        if (event.mouseButton.button == sfMouseLeft)
            all_editor()->is_writing = true;
    if (event.type == sfEvtMouseButtonReleased)
        if (event.mouseButton.button == sfMouseLeft)
            all_editor()->is_writing = false;
    if (!all_editor()->is_writing)
        return;
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(all_infos()->window);
    if (pos_mouse.x <= 300 && pos_mouse.y < 300) {
        all_editor()->value_to_print = '0';
        all_editor()->value_to_print += (pos_mouse.y / 50) * 6;
        all_editor()->value_to_print += (pos_mouse.x / 50);
        return;
    } else if (pos_mouse.x >= 1920 - 150 && pos_mouse.y <= 260) {
        editor_click_infos_right(pos_mouse);
        change_size_map();
        return;
    }
    int y = (pos_mouse.y / 50) - round_sup(all_infos()->pos_player.y / 50);
    int x = (pos_mouse.x / 50) - round_sup(all_infos()->pos_player.x / 50);
    if (all_editor()->ptr_map_edit && x >= 0 && y >= 0 &&
    y < my_arraylen(all_editor()->ptr_map_edit) &&
    x < my_strlen(all_editor()->ptr_map_edit[0])) {
        all_editor()->ptr_map_edit[y][x] = all_editor()->value_to_print;
        return;
    }
}

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
    change_tile_to_print(event);
    if (event.key.code == sfKeyN && all_editor()->ptr_map_edit)
        paint_bucket_tool();
}
