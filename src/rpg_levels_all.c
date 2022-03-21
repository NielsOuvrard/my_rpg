/*
** EPITECH PROJECT, 2022
** snake_no_map.c
** File description:
** snake level 0
*/

#include "my.h"
#include "rpg_header.h"

// all_time()[0].ok  vaut true toutes les 1 secondes
// all_time()[1].ok  vaut true toutes les 1/10 secondes
// all_time()[2].ok  vaut true toutes les 1/100 secondes
// ...

void in_time (void)
{
    int seconds = 1000000;
    for (int i = 0; i < 2; i++) {
        sfTime time_anim = sfClock_getElapsedTime(all_time()[i].clock);
        float rect_anim = time_anim.microseconds;
        if (rect_anim > seconds && !all_time()[i].ok) {
            all_time()[i].ok = true;
            sfClock_restart(all_time()[i].clock);
        } else {
            all_time()[i].ok = false;
        }
        seconds /= 10;
    }
}

void while_it_is_open (void)
{
    sfEvent event;
    // sfMusic_play(my_main.music);
    sfRenderWindow_setFramerateLimit(all_infos()->window, 60);
    while (sfRenderWindow_isOpen(all_infos()->window)) {
        // in_time();
        sfRenderWindow_drawSprite(all_infos()->window, all_sprites()[0].sprite, NULL);
        if (all_infos()->level == 0)
            level_0(event);
        // if (all_infos()->level == 1)
        //     level_1(event);
        if (all_infos()->quit_main)
            return;
        sfRenderWindow_display(all_infos()->window);
    }
}

int all_levels_game (void)
{
    // srand(time(NULL));
    full_list_sprites();
    full_time();
    creat_main();
    my_printf("%d\n", all_infos()->level);
    // game
    while_it_is_open();

    // free here
    return 0;
}
