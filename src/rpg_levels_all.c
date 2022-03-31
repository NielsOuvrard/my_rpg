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

void animation (sfEvent event)
{
    bool anim = if_in_time();
    if (anim && all_infos()->level == 1)
        level_1_clock(event);
    if (anim && all_infos()->level == MAP_EDITOR)
        level_map_editor_clock(event);
}

void while_it_is_open (void)
{
    sfEvent event;
    // sfMusic_play(my_main.music);
    sfRenderWindow_setFramerateLimit(all_infos()->window, 120);
    while (sfRenderWindow_isOpen(all_infos()->window)) {
        all_infos()->size_window = sfRenderWindow_getSize(all_infos()->window);
        sfRenderWindow_clear(all_infos()->window, sfBlack);
        // sfRenderWindow_drawSprite(all_infos()->window, all_sprites()[0].sprite, NULL);
        animation(event);
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

void free_map (int i)
{
    free_my_arr(all_maps()[i].bg);
    free_my_arr(all_maps()[i].mg);
    free_my_arr(all_maps()[i].fg);
}

int all_levels_game (int ac, char **av)
{
    full_list_sprites();
    creat_main();
    creat_editor();
    full_list_maps();
    if (ac > 1 && !my_strcmp(av[1], "-edit") && av[2])
        edit_existing_file(av[2]);
    // game
    while_it_is_open();
    // free_my_arr(all_infos()->map);
    free(all_infos());
    free_map(0);
    free_map(1);
    free(all_maps());
    // free here
    return 0;
}
