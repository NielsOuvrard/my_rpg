/*
** EPITECH PROJECT, 2022
** snake_no_map.c
** File description:
** snake level 0
*/

#include "my.h"
#include "rpg_header.h"

// main_screen destroy_main (main_screen my_main)
// {
    // sfSound_destroy(my_main.hurt_sound);
    // sfSoundBuffer_destroy(my_main.hurt_sound_buffer);
    // sfSound_destroy(my_main.coin_sound);
    // sfSoundBuffer_destroy(my_main.coin_sound_buffer);
    // sfMusic_stop(my_main.music);
    // sfMusic_destroy(my_main.music);
//     sfRenderWindow_close(my_main.window);
//     return my_main;
// }

void event_level_0 (sfEvent event)
{
    while (sfRenderWindow_pollEvent(all_infos()->window, &event)) {
        if (event.type == sfEvtClosed) {
            all_infos()->quit_main = 1;
            return;
        }
        if (event.type == sfEvtKeyPressed) {
            if (event.key.code == sfKeySpace) {
                all_infos()->level = 1;
                my_printf("%d\n", all_infos()->clock_val);
            }
            if (event.key.code == sfKeyE) {
                all_infos()->level = MAP_EDITOR;
            }
        }
    }
    return;
}

void level_0 (sfEvent event)
{
    event_level_0(event);
    if (all_infos()->quit_main == 1) {
        return;
    }
    // sfRenderWindow_drawSprite(all_infos()->window, all_sprites()[2].sprite, NULL);
    return;
}
