/*
** EPITECH PROJECT, 2022
** snake_no_map.c
** File description:
** snake level 0
*/

#include "my.h"
#include "rpg_header.h"

bool if_in_time (void)
{
    sfTime time_anim = sfClock_getElapsedTime(all_infos()->clock);
    if (time_anim.microseconds > 10000) {
        all_infos()->clock_val++;
        sfClock_restart(all_infos()->clock);
        return true;
    }
    return false;
}

void while_it_is_open (void)
{
    sfEvent event;
    // sfMusic_play(my_main.music);
    sfRenderWindow_setFramerateLimit(all_infos()->window, 60);
    while (sfRenderWindow_isOpen(all_infos()->window)) {
        all_infos()->size_window = sfRenderWindow_getSize(all_infos()->window);
        sfRenderWindow_clear(all_infos()->window, sfBlack);
        bool anim = if_in_time();
        sfRenderWindow_drawSprite(all_infos()->window, all_sprites()[0].sprite, NULL);
        // anim
        if (anim && all_infos()->level == 1)
            level_1_clock(event);
        if (anim && all_infos()->level == MAP_EDITOR)
            level_map_editor_clock(event);
        // else
        if (all_infos()->level == 0)
            level_0(event);
        if (all_infos()->level == 1)
            level_1(event);
        if (all_infos()->level == MAP_EDITOR)
            level_map_editor(event);
        if (all_infos()->quit_main)
            return;
        sfRenderWindow_display(all_infos()->window);
    }
}

int all_levels_game (void)
{
    // srand(time(NULL));
    full_list_sprites();
    // full_time();
    creat_main();
    // game
    while_it_is_open();
    free_my_arr(all_infos()->map);
    free(all_infos());
    // free here
    return 0;
}
