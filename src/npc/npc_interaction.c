/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** rpg_npc_interaction
*/

#include "my.h"
#include "rpg_header.h"

bool check_if_mission_was_done(char find)
{
    for (int i = 0; all_infos()->quest_done[i] != '\0'; i++) {
        if (all_infos()->quest_done[i] == find) {
            return true;
        }
    }
    return false;
}

void check_for_easter_egg(sfEvent event)
{
    npcs *expl = all_maps()[all_infos()->map_actual].all_npcs;
    while (expl) {
        if (event.type == sfEvtKeyPressed &&
        event.key.code == all_keys()->k_yes &&
        all_infos()->entering_password == 1) {
            all_infos()->text_char = 0;
            all_infos()->level = BONUS;
        }
        if (event.type == sfEvtKeyPressed && event.key.code ==
        all_keys()->k_no && all_infos()->entering_password == 1) {
            all_infos()->text_char = 0;
            all_infos()->level = GAME;
        }
        expl = expl->next;
    }
}

void event_level_quest(void)
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
        check_for_easter_egg(event);
    }
    return;
}

void print_quest(char *text)
{
    int i = 4, j = all_infos()->text_char;
    sfTime time = sfClock_getElapsedTime(all_infos()->text_clock);
    if (sfTime_asMilliseconds(time) > 0.6) {
        if (j + 1 < my_strlen(text))
            all_infos()->text_char += 1;
        sfClock_restart(all_infos()->text_clock);
    }
    char *tmp = my_strdup_to(text, j);
    sfText_setCharacterSize(all_texts()->simple_text, 50);
    sfText_setString(all_texts()->simple_text, tmp);
    sfText_setPosition(all_texts()->simple_text, (sfVector2f) {610, 777});
    sfRenderWindow_drawText(all_infos()->window,
    all_texts()->simple_text, NULL);
}

void npc_check_quest_3(npcs *expl)
{
    if (expl->value == 17 && expl->interaction == 1) {
        if (all_infos()->doing_quest == true && all_infos()->quest_id == 14) {
            all_infos()->doing_quest = false;
            all_infos()->quest_id = 0;
            all_infos()->quest_done[my_strlen(all_infos()->quest_done)] = '2';
        }
        print_quest("Finally someone came!\nThanks for saving me!\n");
    }
}

void npc_check_quest_2(npcs *expl, char *text)
{
    if (expl->value == 14 && expl->interaction == 1) {
        if (check_if_mission_was_done('2') == true) {
            print_quest("Thanks for your help!\n");
            return;
        }
        if (all_infos()->doing_quest == false ||
        all_infos()->quest_id == expl->value) {
            all_infos()->quest_id = expl->value;
            all_infos()->doing_quest = true;
            text = my_strcpy(text, "My son went to the dungeon!!!\nI need ");
            text = my_strcat(text, "I need someone to save him and\nI do not");
            text = my_strcat(text, " know what to do!\nCould you help me?\n");
            print_quest(text);
        } else {
            print_quest("You are already in a quest...\nCome back later!\n");
        }
    }
    npc_check_quest_3(expl);
}

void npc_check_quest(npcs *expl, char *text)
{
    if (expl->value == 10 && expl->interaction == 1) {
        if (check_if_mission_was_done('1') == true) {
            print_quest("Thanks for your help!\n");
            return;
        }
        if (all_infos()->doing_quest == false ||
        all_infos()->quest_id == expl->value) {
            all_infos()->quest_id = expl->value;
            all_infos()->doing_quest = true;
            text = my_strcpy(text, "Hello hero,\nI'm glad you are here! The ");
            text = my_strcat(text, "demons and ninjas\nare attacking our ");
            text = my_strcat(text, "village.. \nPlease kill them!");
            print_quest(text);
        } else {
            print_quest("You are already in a quest...\nCome back later!\n");
        }
    }
    if (expl->value == 12 && expl->interaction == 1) {
        if (check_if_mission_was_done('3') == true) {
            print_quest("Password already done!\n");
            return;
        }
        text = my_strcpy(text, "Do you have the password?\nPress");
        text = my_strcat(text, " Y for 'yes' and N for 'no'\n");
        print_quest(text);
        all_infos()->entering_password = 1;
    }
    npc_check_quest_2(expl, text);
}

void npc_quest(void)
{
    npcs *expl = all_maps()[all_infos()->map_actual].all_npcs;
    char *text = malloc(sizeof(char) * 200);
    all_infos()->entering_password = 0;
    while (expl) {
        npc_check_quest(expl, text);
        expl = expl->next;
    }
}

void disp_interaction_button(void)
{
    npcs *expl = all_maps()[all_infos()->map_actual].all_npcs;
    for (; expl; expl = expl->next) {
        sfFloatRect rect_player =
        sfSprite_getGlobalBounds(all_sprites()[HUNTER].sprite);
        sfFloatRect rect_npc =
        sfSprite_getGlobalBounds(all_sprites()[expl->value].sprite);
        rect_npc.height = 60;
        rect_npc.width = 60;
        expl->interaction = 0;
        if (sfFloatRect_intersects(&rect_player, &rect_npc, NULL)) {
            expl->interaction = 1;
            sfSprite_setScale(all_sprites()[INTERACTION_BT].sprite,
            (sfVector2f) {2, 2});
            sfSprite_setPosition(all_sprites()[INTERACTION_BT].sprite,
            (sfVector2f) {expl->pos.x - 13, expl->pos.y - 85});
            sfRenderWindow_drawSprite(all_infos()->window,
            all_sprites()[INTERACTION_BT].sprite, NULL);
            return;
        }
    }
}

void level_quest(void)
{
    event_level_quest();
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
    sfRenderWindow_drawSprite(all_infos()->window,
    all_sprites()[BALLON].sprite, NULL);
    npc_quest();
    sfRenderWindow_setView(all_infos()->window, all_infos()->view);
    return;
}
