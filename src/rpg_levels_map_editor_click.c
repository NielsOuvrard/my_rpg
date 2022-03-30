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

void change_map_size(sfEvent event)
{
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyUp)
            all_editor()->size_edit.y--;
        if (event.key.code == sfKeyLeft)
            all_editor()->size_edit.x--;
        if (event.key.code == sfKeyDown)
            all_editor()->size_edit.y++;
        if (event.key.code == sfKeyRight)
            all_editor()->size_edit.x++;
    }
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
    }
    int y = (pos_mouse.y / 50) - round_sup(all_infos()->pos_player.y / 50);
    int x = (pos_mouse.x / 50) - round_sup(all_infos()->pos_player.x / 50);
    if (all_editor()->map_editor && x >= 0 && y >= 0 &&
    y < my_arraylen(all_editor()->map_editor) &&
    x < my_strlen(all_editor()->map_editor[0])) {
        all_editor()->map_editor[y][x] = all_editor()->value_to_print;
        return;
    }
}

void la_bonne_touche_editor (sfEvent event)
{
    if (!(event.type == sfEvtKeyPressed))
        return;
    if (event.key.code == sfKeyEscape)
        all_infos()->level = 0;
    change_tile_to_print(event);
    if (event.key.code == sfKeyN) {
        if (all_editor()->map_editor)
            free_my_arr(all_editor()->map_editor);
        all_editor()->map_editor = editor_create_map(
        all_editor()->size_edit.x, all_editor()->size_edit.y);
    }
}
