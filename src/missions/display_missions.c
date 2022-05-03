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

void display_mission_2(void)
{
    if (all_infos()->quest_id == 14) {
        sfText_setPosition(all_texts()->simple_text, (sfVector2f) {820, 480});
        sfText_setString(all_texts()->simple_text,
        "Save the villager's son\nfrom the dungeon!\n");
    }
    sfRenderWindow_drawText(all_infos()->window,
    all_texts()->simple_text, NULL);
}

void display_mission(void)
{
    char *text = malloc(sizeof(char) * 100);
    sfRenderWindow_drawSprite(all_infos()->window,
    all_sprites()[PARCHMENT].sprite, NULL);
    sfText_setCharacterSize(all_texts()->simple_text, 50);
    sfText_setPosition(all_texts()->simple_text, (sfVector2f) {790, 510});
    if (all_infos()->doing_quest == false) {
        sfText_setString(all_texts()->simple_text,
        "No quest at the moment!\n");
    }
    if (all_infos()->quest_id == 10) {
        sfText_setPosition(all_texts()->simple_text, (sfVector2f) {790, 460});
        text = my_strcpy(text, "Kill all enemies in the outer\n");
        text = my_strcat(text, "area of the map!\nEnemies remaining: ");
        text = my_strcat(text,
        my_int_to_str(all_infos()->nb_of_enemies_outside));
        sfText_setString(all_texts()->simple_text, text);
    }
    display_mission_2();
}

void level_missions(void)
{
    event_level_missions();
    if (all_infos()->quit_main == 1) {
        write_infos_to_file();
        return;
    }
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
