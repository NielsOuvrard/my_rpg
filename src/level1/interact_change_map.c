/*
** EPITECH PROJECT, 2022
** rpg_interact_change_map.c
** File description:
** rpg_interact_change_map.c
*/

#include "my.h"
#include "rpg_header.h"

void move_to_map (int map, int x, int y)
{
    struct_particule *all_p = all_infos()->particules;
    all_infos()->particules = NULL;
    while (all_p) {
        struct_particule *tmp = all_p;
        all_p = all_p->next;
        free(tmp);
    }
    all_sprites()[HUNTER].pos.y = SIZE_TILE * y;
    all_sprites()[HUNTER].pos.x = (SIZE_TILE * x) + 25;
    sfSprite_setPosition(all_sprites()[HUNTER].sprite,
    all_sprites()[HUNTER].pos);
    all_infos()->map_actual = map;
    sfView_setCenter(all_infos()->view,
    (sfVector2f) {(SIZE_TILE * x) + 25, SIZE_TILE * y});
    sfRenderWindow_setView(all_infos()->window, all_infos()->view);
}

int player_is_on_case(int x, int y)
{
    if (all_sprites()[HUNTER].pos.x >= (50 * x) &&
    all_sprites()[HUNTER].pos.x <= 50 * (x + 1) &&
    all_sprites()[HUNTER].pos.y >= 50 * y &&
    all_sprites()[HUNTER].pos.y <= 50 * (y + 1))
        return 1;
    return 0;
}

void check_all_intecract_map_actual (void)
{
    struct_interact *list = all_maps()[all_infos()->map_actual].interact;
    while (list) {
        if (player_is_on_case(list->x, list->y))
            move_to_map(list->data, list->a_x, list->a_y);
        list = list->next;
    }
}
