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
    }
    return;
}

void level_1 (sfEvent event)
{
    event_level_1(event);
    if (all_infos()->quit_main == 1) {
        return;
    }
    // sfRenderWindow_drawSprite(all_infos()->window, all_infos()->sprite_difficulty, NULL);
    return;
}
