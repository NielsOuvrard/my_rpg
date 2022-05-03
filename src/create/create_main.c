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
    infos->inventory_move = 0;
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
    does_save_exists();
    sfRenderWindow_setView(infos->window, infos->view);
}

void add_to_inventory (struct_inventory **list, int value)
{
    struct_inventory *new_node = malloc(sizeof(struct_inventory));
    new_node->object = value;
    new_node->next = NULL;
    if (*list == NULL) {
        *list = new_node;
        return;
    }
    struct_inventory *last = *list;
    while (last->next)
        last = last->next;
    last->next = new_node;
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
    infos->quest_done[0] = '\0';
    struct_inventory *val = NULL;
    add_to_inventory(&val, 3);
    add_to_inventory(&val, 15);
    add_to_inventory(&val, 3);
    add_to_inventory(&val, 15);
    add_to_inventory(&val, 3);
    add_to_inventory(&val, 15);
    add_to_inventory(&val, 3);
    add_to_inventory(&val, 15);
    add_to_inventory(&val, 15);
    add_to_inventory(&val, 3);
    add_to_inventory(&val, 15);
    add_to_inventory(&val, 3);
    add_to_inventory(&val, 15);
    infos->inventory = val;
    all_infos()->stamina_clock = sfClock_create();
    all_infos()->text_clock = sfClock_create();
    all_infos()->text_char = 0;
    initialize_main_vals();
    return;
}
