/*
** EPITECH PROJECT, 2022
** snake_no_map.c
** File description:
** snake level 0
*/

#include "my.h"
#include "rpg_header.h"

bool if_in_time(void)
{
    sfTime time_anim = sfClock_getElapsedTime(all_infos()->clock);
    if (time_anim.microseconds > 10000) {
        all_infos()->clock_val++;
        sfClock_restart(all_infos()->clock);
        return true;
    }
    return false;
}

void handle_animations(sfEvent event)
{
    bool anim = if_in_time();
    if (!if_in_time()) {
        return;
    }
    if (all_infos()->level == GAME) {
        level_1_animations(event);
    } else if (all_infos()->level == MAP_EDITOR) {
        level_map_editor_clock(event);
    }
}

// sfMusic_play(my_main.music);
void while_it_is_open(void)
{
    sfEvent event;
    while (sfRenderWindow_isOpen(all_infos()->window)) {
        if (all_infos()->level == GAME)
            move_all_ennemys();
        all_infos()->size_window = sfRenderWindow_getSize(all_infos()->window);
        sfRenderWindow_clear(all_infos()->window, sfBlack);
        increase_stamina();
        handle_animations(event);
        if (all_infos()->level == 0)
            level_0(event);
        if (all_infos()->level == GAME)
            level_1(event);
        if (all_infos()->level == MAP_EDITOR)
            level_map_editor(event);
        if (all_infos()->level == INVENTORY)
            level_inventory(event);
        if (all_infos()->level == DIALOGUE)
            level_quest();
        if (all_infos()->quit_main)
            return;
        sfRenderWindow_display(all_infos()->window);
    }
}

int start_game_loop(void)
{
    while_it_is_open();
    free_particules();
    free(all_infos());
    free_map(0);
    free_map(1);
    free(all_maps());
}

int start_game(int ac, char **av)
{
    fill_sprite_dictionary();
    create_main();
    create_editor();
    create_keys();
    fill_map_dictionary();
    if (ac > 1 && !my_strcmp(av[1], "-edit") && av[2])
        edit_existing_file(av[2]);
    if (ac > 1 && !my_strcmp(av[1], "-q"))
        qwerty_keyes();
    sfRenderWindow_setFramerateLimit(all_infos()->window, 120);
    start_game_loop();
    return 0;
}
