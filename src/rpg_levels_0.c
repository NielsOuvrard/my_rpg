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
    }
    return my_main;
}

main_screen level_0 (main_screen my_main, sfEvent event)
{
    my_main = event_level_0(my_main, event);
    if (my_main.quit_main == 1) {
        return my_main;
    }
    sfRenderWindow_drawSprite(my_main.window, all_sprites()[2].sprite, NULL);
    return my_main;
}
