/*
** EPITECH PROJECT, 2022
** snake_no_map.c
** File description:
** snake level 0
*/

#include "my.h"
#include "rpg_header.h"

bool clock_cycle_update(void)
{
    sfTime time_anim = sfClock_getElapsedTime(all_infos()->clock);
    if (time_anim.microseconds > 10000) {
        all_infos()->clock_val++;
        sfClock_restart(all_infos()->clock);
        return true;
    }
    return false;
}

void on_clock_update()
{
    if (!clock_cycle_update()) {
        return;
    }
    projectile_game_tick();
    increase_stamina();
    if (all_infos()->level == GAME) {
        level_game_animations();
    } else if (all_infos()->level == MAP_EDITOR) {
        level_map_editor_clock();
    }
}

// sfMusic_play(my_main.music);
void game_loop(void)
{
    sfEvent event;
    while (sfRenderWindow_isOpen(all_infos()->window)) {
        if (all_infos()->level == GAME)
            move_all_ennemies();
        all_infos()->size_window = sfRenderWindow_getSize(all_infos()->window);
        sfRenderWindow_clear(all_infos()->window, sfBlack);
        on_clock_update();
        if (all_infos()->level == 0)
            level_0(event);
        if (all_infos()->level == GAME)
            level_game(event);
        if (all_infos()->level == MAP_EDITOR)
            level_map_editor(event);
        projectile_render_tick();
        if (all_infos()->level == INVENTORY)
            level_inventory(event);
        if (all_infos()->level == DIALOGUE)
            level_quest();
        if (all_infos()->level == MISSIONS)
            level_missions();
        if (all_infos()->level == BONUS)
            level_bonus();
        if (all_infos()->quit_main)
            return;
        sfRenderWindow_display(all_infos()->window);
    }
}

int start_game_loop(void)
{
    game_loop();
    free_particules();
    free(all_infos());
    free_map(0);
    free_map(1);
    free(all_maps());
}

int start_game(int ac, char **av)
{
    new_projectile_manager();
    fill_sprite_dictionary();
    create_main();
    create_editor();
    create_keys();
    create_texts();
    fill_map_dictionary();
    if (ac > 1 && !my_strcmp(av[1], "-edit") && av[2])
        edit_existing_file(av[2]);
    if (ac > 1 && !my_strcmp(av[1], "-q"))
        qwerty_keyes();
    sfRenderWindow_setFramerateLimit(all_infos()->window, 120);
    start_game_loop();
    return 0;
}
