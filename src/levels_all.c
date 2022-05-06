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
void game_loop(tags *game)
{
    sfEvent event;
    while (sfRenderWindow_isOpen(all_infos()->window)) {
        is_onchest();
        if (all_infos()->level == GAME)
            move_all_ennemies();
        all_infos()->size_window = sfRenderWindow_getSize(all_infos()->window);
        sfRenderWindow_clear(all_infos()->window, sfBlack);
        on_clock_update();
        if (all_infos()->level == 0)
            level_menu(game, event);
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
        if (all_infos()->level == CHEST)
            chest_level();
        if (all_infos()->level == OPTIONS)
            level_option(game);
        if (all_infos()->quit_main)
            return;
        sfRenderWindow_display(all_infos()->window);
    }
}

void malloc_all(tags *game)
{
    game->f_rects = malloc(sizeof(f_rect));
    game->sprites = malloc(sizeof(t_sprites));
    game->text = malloc(sizeof(t_text));
    initialize_sprite_menu(game);
    initialize_bounds_menu(game);
    inicialize_variables_option(game);
    inicialize_sprite_option(game);
    initialize_options_game(game);
}

int start_game_loop(void)
{
    tags *game = malloc(sizeof(tags));
    malloc_all(game);
    game_loop(game);
    free_particules();
    free(all_infos());
    free_map(0);
    free_map(1);
    free(game);
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
    does_save_exists();
    if (ac > 1 && !my_strcmp(av[1], "-edit") && av[2])
        edit_existing_file(av[2]);
    if (ac > 1 && !my_strcmp(av[1], "-q"))
        qwerty_keyes();
    sfRenderWindow_setFramerateLimit(all_infos()->window, 120);
    start_game_loop();
    return 0;
}
