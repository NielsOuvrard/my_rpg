/*
** EPITECH PROJECT, 2022
** snake_no_map.c
** File description:
** snake level 0
*/

#include "my.h"
#include "rpg_header.h"

void key_pressed (sfEvent event)
{
    if (event.key.code == sfKeySpace) {
        all_infos()->level = 1;
    }
    if (event.key.code == sfKeyE) {
        sfView_setCenter(all_infos()->view, (sfVector2f) {960, 540});
        sfView_setSize(all_infos()->view, (sfVector2f) {1920, 1080});
        sfRenderWindow_setView(all_infos()->window, all_infos()->view);
        all_editor()->map_bg = editor_create_map( 30, 30,
        all_editor()->value_to_print);
        all_editor()->map_mg = editor_create_map(30, 30, 'R');
        all_editor()->map_fg = editor_create_map(30, 30, 'R');
        all_editor()->ptr_map_edit = all_editor()->map_bg;
        all_infos()->level = MAP_EDITOR;
    }
}

void event_level_0 (sfEvent event)
{
    while (sfRenderWindow_pollEvent(all_infos()->window, &event)) {
        if (event.type == sfEvtClosed) {
            all_infos()->quit_main = 1;
            return;
        }
        if (event.type == sfEvtKeyPressed)
            key_pressed(event);
    }
    return;
}

void level_0 (sfEvent event)
{
    event_level_0(event);
    if (all_infos()->quit_main == 1) {
        write_infos_to_file();
        return;
    }
    return;
}
