/*
** EPITECH PROJECT, 2022
** snake_no_map.c
** File description:
** snake level 0
*/

#include "my.h"
#include "rpg_header.h"


main_screen event_level_1 (main_screen my_main, sfEvent event)
{
    while (sfRenderWindow_pollEvent(my_main.window, &event)) {
        if (event.type == sfEvtClosed) {
            my_main.quit_main = 1;
            return my_main;
        }
    }
    return my_main;
}

main_screen level_1 (main_screen my_main, sfEvent event)
{
    my_main = event_level_1(my_main, event);
    if (my_main.quit_main == 1) {
        return my_main;
    }
    // sfRenderWindow_drawSprite(my_main.window, my_main.sprite_difficulty, NULL);
    return my_main;
}
