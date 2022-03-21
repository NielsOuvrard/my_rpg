/*
** EPITECH PROJECT, 2022
** snake_no_map.c
** File description:
** snake level 0
*/

#include "my.h"
#include "rpg_header.h"

void event_level_1 (sfEvent event)
{
    while (sfRenderWindow_pollEvent(all_infos()->window, &event)) {
        if (event.type == sfEvtClosed) {
            all_infos()->quit_main = 1;
            return;
        }

        if (event.type == sfEvtKeyPressed) {
            if (event.key.code == sfKeySpace)
                all_infos()->level = 0;
        }
    }
    return;
}

void disp_map (void)
{
    for (int i = 0; all_infos()->map[i]; i++) {
        for (int j = 0; all_infos()->map[i][j]; j++) {
            if (all_infos()->map[i][j] == 'c') {
                all_sprites()[GROUND].pos.x = 100 * i;
                all_sprites()[GROUND].pos.y = 100 * j;
                sfSprite_setPosition(all_sprites()[GROUND].sprite, all_sprites()[GROUND].pos);
                sfRenderWindow_drawSprite(all_infos()->window, all_sprites()[GROUND].sprite, NULL);
            }
        }
    }
}

void level_1 (sfEvent event)
{
    event_level_1(event);
    if (all_infos()->quit_main == 1) {
        return;
    }
    disp_map();
    // sfRenderWindow_drawSprite(all_infos()->window, all_infos()->sprite_difficulty, NULL);
    return;
}
