/*
** EPITECH PROJECT, 2022
** snake_no_map.c
** File description:
** snake level 0
*/

#include "my.h"
#include "rpg_header.h"

main_screen destroy_main (main_screen my_main)
{
    // sfSound_destroy(my_main.hurt_sound);
    // sfSoundBuffer_destroy(my_main.hurt_sound_buffer);
    // sfSound_destroy(my_main.coin_sound);
    // sfSoundBuffer_destroy(my_main.coin_sound_buffer);
    // sfMusic_stop(my_main.music);
    // sfMusic_destroy(my_main.music);
    sfRenderWindow_close(my_main.window);
    return my_main;
}

main_screen event_level_0 (main_screen my_main, sfEvent event)
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
                    my_putstr("options\n");
                }
                if (C.y > SCREEN_MAX_Y / 2 - 130 && C.y < SCREEN_MAX_Y / 2 - 30) {
                    my_putstr("levels\n");
                    sfSound_play(my_main.coin_sound);
                    my_main.level = 1;
                    return my_main;
                }
                if (C.y > SCREEN_MAX_Y / 2 - 260 && C.y < SCREEN_MAX_Y / 2 - 160) {
                    my_putstr("play\n");
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

main_screen level_0 (main_screen my_main, sfEvent event)
{
    my_main = event_level_0(my_main, event);
    if (my_main.quit_main == 1) {
        return my_main;
    }
    sfRenderWindow_drawSprite(my_main.window, my_main.sprite_menu, NULL);
    // sfRenderWindow_drawText(my_main.window, my_main.text, NULL);
    // sfRenderWindow_drawText(my_main.window, my_main.text_qt, NULL);
    return my_main;
}
