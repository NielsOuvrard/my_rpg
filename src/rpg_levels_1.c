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
        if (event.type == sfEvtMouseButtonPressed && event.mouseButton.button == sfMouseLeft) {
            sfVector2i C = sfMouse_getPositionRenderWindow(my_main.window);
            if (C.x > SCREEN_MAX_X / 2 - 150 && C.x < SCREEN_MAX_X / 2 + 150) {
                if (C.y > SCREEN_MAX_Y / 2 - 0 && C.y < SCREEN_MAX_Y / 2 + 100) {
                    my_putstr("hard\n");
                    sfSound_play(my_main.coin_sound);
                    my_main.level = 0;
                    return my_main;
                }
                if (C.y > SCREEN_MAX_Y / 2 - 130 && C.y < SCREEN_MAX_Y / 2 - 30) {
                    my_putstr("normal\n");
                    sfSound_play(my_main.coin_sound);
                    my_main.level = 0;
                    return my_main;
                }
                if (C.y > SCREEN_MAX_Y / 2 - 260 && C.y < SCREEN_MAX_Y / 2 - 160) {
                    my_putstr("eazy\n");
                    sfSound_play(my_main.coin_sound);
                    my_main.level = 0;
                    return my_main;
                }
            }
            if (C.x > SCREEN_MAX_X / 2 - 50 && C.x < SCREEN_MAX_X / 2 + 50 &&
            C.y > SCREEN_MAX_Y / 2 + 150 && C.y < SCREEN_MAX_Y / 2 + 250) {
                my_main.quit_main = 1;
                return my_main;
            }
            // my_putstr("click\n");
        }
    }
    // sfRenderWindow_drawSprite(my_main.window, my_main.sprite_menu, NULL);
    return my_main;
}

main_screen level_1 (main_screen my_main, sfEvent event)
{
    my_main = event_level_1(my_main, event);
    if (my_main.quit_main == 1) {
        return my_main;
    }
    sfRenderWindow_drawSprite(my_main.window, my_main.sprite_difficulty, NULL);
    // sfRenderWindow_drawText(my_main.window, my_main.text, NULL);
    // sfRenderWindow_drawText(my_main.window, my_main.text_qt, NULL);
    return my_main;
}
