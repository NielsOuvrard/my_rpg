/*
** EPITECH PROJECT, 2021
** game file 1
** File description:
** lib csfml
*/

#include "my.h"
#include "rpg_header.h"

static main_screen *infos;

main_screen *all_infos(void)
{
    return infos;
}

// sfView_setCenter(infos->view, (sfVector2f) {1920 / 4, 1080 / 4});
void initialize_main_vals(void)
{
    infos->move_u = false;
    infos->move_d = false;
    infos->move_l = false;
    infos->move_r = false;
    infos->clock = sfClock_create();
    infos->clock_val = 0;
    infos->particules = NULL;
    infos->view_position.x = 960;
    infos->view_position.y = 540;
    infos->view = sfView_create();
    infos->hud_view = sfView_create();
    infos->quest_id = 0;
    infos->nb_of_enemies_outside = 0;
    sfView_setCenter(infos->hud_view, (sfVector2f) {1920 / 2, 1080 / 2});
    sfView_setSize(infos->hud_view, (sfVector2f) {1920, 1080});
    sfRenderWindow_setView(infos->window, infos->hud_view);
    infos->last_move = 'd';
    sfView_setCenter(infos->view, (sfVector2f) {10 * 50, (10 * 35) - 16});
    sfView_setSize(infos->view, (sfVector2f) {1920 / 2, 1080 / 2});
    sfRenderWindow_setView(infos->window, infos->view);
}

struct_inventory *add_to_inventory (struct_inventory *list)
{
    struct_inventory *val = malloc(sizeof(struct_inventory));
    val->object = '0';
    val->next = list;
    return val;
}

void create_main(void)
{
    infos = malloc(sizeof(main_screen));
    sfVideoMode mode = {SCREEN_MAX_X, SCREEN_MAX_Y, 60};
    infos->window = sfRenderWindow_create(mode, "RPG",
    sfResize | sfClose, NULL);
    infos->level = 0;
    infos->quit_main = 0;
    infos->map_actual = 0;
    infos->pos_player.x = 0;
    infos->pos_player.y = 0;
    infos->nb_of_zoom = 1;
    infos->zoom = 1;
    infos->move = '\0';
    infos->life = 10;
    infos->stamina = 10;
    struct_inventory *val = NULL;
    for (int i = 0; i < 20; i++)
        val = add_to_inventory(val);
    infos->inventory = val;
    all_infos()->stamina_clock = sfClock_create();
    initialize_main_vals();
    return;
}
