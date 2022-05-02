/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** bonus
*/

#include "my.h"
#include "rpg_header.h"

void event_level_bonus(void)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(all_infos()->window, &event)) {
        if (event.type == sfEvtKeyPressed &&
        event.key.code == all_keys()->k_interact) {
            all_infos()->text_char = 0;
            all_infos()->level = GAME;
        }
        if (event.type == sfEvtClosed) {
            all_infos()->quit_main = 1;
            return;
        }
    }
    return;
}

void level_bonus(void)
{
    event_level_bonus();
        disp_map(all_maps()[all_infos()->map_actual].bg);
    print_all_particules();
    disp_mg();
    disp_map(all_maps()[all_infos()->map_actual].fg);
    disp_all_npcs();
    disp_interaction_button();
    sfRenderWindow_setView(all_infos()->window, all_infos()->hud_view);
    display_hud();
    sfRenderWindow_setView(all_infos()->window, all_infos()->view);
}
