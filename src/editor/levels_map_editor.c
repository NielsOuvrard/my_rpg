/*
** EPITECH PROJECT, 2022
** snake_no_map.c
** File description:
** snake level 0
*/

#include "my.h"
#include "rpg_header.h"

void level_map_editor_event(sfEvent event)
{
    while (sfRenderWindow_pollEvent(all_infos()->window, &event)) {
        if (event.type == sfEvtClosed) {
            all_infos()->quit_main = 1;
            return;
        }
        if (sfKeyboard_isKeyPressed(sfKeyP) && all_editor()->map_bg) {
            write_maps();
        }
        la_bonne_touche_editor(event);
        le_bon_click_editor(event);
    }
}

// pb avec dernier char des str du char **
// 0 fichier = default
// si param, modif map existante
void level_map_editor_clock(void)
{
    if ((all_infos()->move_u || all_infos()->move_d ||
        all_infos()->move_r || all_infos()->move_l) &&
        !(all_infos()->clock_val % 2)) {
        if (all_infos()->move_u)
            all_infos()->pos_player.y += 10;
        if (all_infos()->move_d)
            all_infos()->pos_player.y -= 10;
        if (all_infos()->move_l)
            all_infos()->pos_player.x += 10;
        if (all_infos()->move_r)
            all_infos()->pos_player.x -= 10;
    }
}

void level_map_editor(sfEvent event)
{
    level_map_editor_event(event);
    if (all_editor()->v_bg && all_editor()->map_bg)
        disp_map_editor(all_editor()->map_bg);
    if (all_editor()->v_mg && all_editor()->map_mg)
        disp_map_editor(all_editor()->map_mg);
    if (all_editor()->v_fg && all_editor()->map_fg)
        disp_map_editor(all_editor()->map_fg);
    disp_value_to_print();
    disp_text_and_boxes();
}
