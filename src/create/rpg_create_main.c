/*
** EPITECH PROJECT, 2021
** game file 1
** File description:
** lib csfml
*/

#include "my.h"
#include "rpg_header.h"

static main_screen *infos;

main_screen *all_infos (void)
{
    return infos;
}

void initialize_main_vals(void)
{
    sfView_setCenter(infos->view, (sfVector2f) {10 * 50, (10 * 35) - 16});
    sfView_setSize(infos->view, (sfVector2f) {1920 / 2, 1080 / 2});
    sfRenderWindow_setView(infos->window, infos->view);
}

void creat_main (void)
{
    infos = malloc(sizeof(main_screen));
    sfVideoMode mode = {SCREEN_MAX_X, SCREEN_MAX_Y, 60};
    infos->window = sfRenderWindow_create(mode, "RPG",
    sfResize | sfClose, NULL);
    infos->level = 0;
    infos->quit_main = 0;
    infos->score = 0;
    infos->map_actual = 1;
    infos->pos_player.x = 0;
    infos->pos_player.y = 0;
    infos->zoom = 1;
    infos->move = '\0';
    infos->clock = sfClock_create();
    infos->clock_val = 0;
    infos->clock_bool = true;

    infos->view_position.x = 960;
    infos->view_position.y = 540;
    infos->view = sfView_create();
    initialize_main_vals();
    return;
}
