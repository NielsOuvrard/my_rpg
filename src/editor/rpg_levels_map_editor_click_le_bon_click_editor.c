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

int le_bon_click_editor_pos_map (sfEvent event, sfVector2i pos_mouse)
{
    if (pos_mouse.x <= SCALE_TILE_SHEET * SIZE_TILE_SHEET_X &&
        pos_mouse.y < SCALE_TILE_SHEET * SIZE_TILE_SHEET_Y) {
        all_editor()->value_to_print = '0';
        all_editor()->value_to_print += (pos_mouse.y / 50) * 6;
        all_editor()->value_to_print += (pos_mouse.x / 50);
        return 1;
    } else if (pos_mouse.x >= 1920 - 150 && pos_mouse.y <= 260) {
        editor_click_infos_right(pos_mouse);
        change_size_map();
        return 1;
    }
    return 0;
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
    if (le_bon_click_editor_pos_map(event, pos_mouse))
        return;
    int y = (pos_mouse.y / 50) - (((all_infos()->pos_player.y - 8) / 50));
    int x = (pos_mouse.x / 50) - (((all_infos()->pos_player.x - 8) / 50));
    if (all_editor()->ptr_map_edit && x >= 0 && y >= 0 &&
    y < my_arraylen(all_editor()->ptr_map_edit) &&
    x < my_strlen(all_editor()->ptr_map_edit[0])) {
        all_editor()->ptr_map_edit[y][x] = all_editor()->value_to_print;
        return;
    }
}
