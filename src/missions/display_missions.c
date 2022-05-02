/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_missions
*/

#include "my.h"
#include "rpg_header.h"

void event_level_missions(void)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(all_infos()->window, &event)) {
        if (event.type == sfEvtKeyPressed &&
        event.key.code == all_keys()->k_open_missions)
            all_infos()->level = GAME;
        if (event.type == sfEvtClosed) {
            all_infos()->quit_main = 1;
            return;
        }
    }
    return;
}

void display_mission(void)
{
    char *text;
    sfRenderWindow_drawSprite(all_infos()->window, all_sprites()[PARCHMENT].sprite, NULL);
    sfText_setCharacterSize(all_texts()->simple_text, 50);
    sfText_setPosition(all_texts()->simple_text, (sfVector2f) {790, 510});
    if (all_infos()->doing_quest == false) {
        sfText_setString(all_texts()->simple_text, "No quest at the moment!\n");
    }
    if (all_infos()->quest_id == 10) {
        sfText_setPosition(all_texts()->simple_text, (sfVector2f) {790, 460});
        text = my_strdup("Kill all enemies in the outer\narea of the map!\nEnemies remaining:");
        text = my_strcat(text, my_int_to_str(all_infos()->nb_of_enemies_outside));
        sfText_setString(all_texts()->simple_text, text);
    }
    // if (all_infos()->quest_id == 12) {
    //     sfText_setPosition(all_texts()->simple_text, (sfVector2f) {840, 520});
    //     sfText_setString(all_texts()->simple_text, "KILL THE BOSS!\n");
    // }
    if (all_infos()->quest_id == 14) {
        sfText_setPosition(all_texts()->simple_text, (sfVector2f) {820, 480});
        sfText_setString(all_texts()->simple_text, "Save the villager's son\nfrom the dungeon!\n");
    }
    sfRenderWindow_drawText(all_infos()->window, all_texts()->simple_text, NULL);
}

void level_missions(void)
{
    event_level_missions();
    if (all_infos()->quit_main == 1)
        return;
    disp_map(all_maps()[all_infos()->map_actual].bg);
    print_all_particules();
    disp_mg();
    disp_map(all_maps()[all_infos()->map_actual].fg);
    disp_all_npcs();
    disp_interaction_button();
    sfRenderWindow_setView(all_infos()->window, all_infos()->hud_view);
    display_hud();
    display_mission();
    sfRenderWindow_setView(all_infos()->window, all_infos()->view);
    return;
}
