/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-myrpg-niels.ouvrard
** File description:
** chest_level
*/

#include "my.h"
#include "rpg_header.h"

void chest_level(void)
{
    event_level_chest();
    if (all_infos()->quit_main == 1) {
        close_sounds();
        write_infos_to_file();
        return;
    }
    disp_map(all_maps()[all_infos()->map_actual].bg);
    print_all_particules();
    disp_mg();
    disp_map(all_maps()[all_infos()->map_actual].fg);
    disp_all_npcs();
    is_onchest();
    sfRenderWindow_setView(all_infos()->window, all_infos()->hud_view);
    display_hud();
    sfRenderWindow_drawSprite(all_infos()->window,
    all_sprites()[BALLON].sprite, NULL);
    print_items();
    sfRenderWindow_setView(all_infos()->window, all_infos()->view);
    return;
}

void event_level_chest(void)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(all_infos()->window, &event)) {
        if (event.type == sfEvtKeyPressed &&
        event.key.code == all_keys()->k_interact) {
            all_infos()->text_char = 0;
            all_infos()->banana_nb = 0;
            all_infos()->apple_nb = 0;
            all_infos()->level = GAME;
            all_infos()->opened_chest = false;
        }
        if (event.type == sfEvtClosed) {
            all_infos()->quit_main = 1;
            return;
        }
    }
    return;
}

void print_items(void)
{
    int nb_of_items = random_int(1, 5);
    int i = 0;
    int pick = 0;
    if (all_infos()->opened_chest || all_infos()->level != CHEST) {
        print_chestmsg();
        return;
    }
    while (i != nb_of_items) {
        pick = random_int(1, 2);
        add_item(pick);
        i++;
        all_infos()->opened_chest = true;
    }
}

void print_chestmsg(void)
{
    char *text = malloc(sizeof(char) * 200);
    text = my_strcpy(text, "You found ");
    char *apple_nb = my_itoa(all_infos()->apple_nb);
    char *banana_nb = my_itoa(all_infos()->banana_nb);
    text = my_strcat(text, apple_nb);
    text = my_strcat(text, " apples\n and ");
    text = my_strcat(text, banana_nb);
    text = my_strcat(text, " bananas\n Nice work !\n");
    print_quest(text);
}

void add_item(int pick)
{
    if (pick == 1) {
        add_to_inventory(&all_infos()->inventory, BANANA);
        all_infos()->banana_nb += 1;
    }
    if (pick == 2) {
        add_to_inventory(&all_infos()->inventory, APPLE);
        all_infos()->apple_nb += 1;
    }
}
