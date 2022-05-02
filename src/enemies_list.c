/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-myrpg-niels.ouvrard
** File description:
** enemies_list
*/

#include "my.h"
#include "rpg_header.h"

// int size_list(enemies *expl)
// {
//     int a = 0;
//     while (expl) {
//         a++;
//         expl = expl->next;
//     }
//     return a;
// }
void add_enemies_to_list_next(enemies *new_enemy, int value, int x, int y)
{
    new_enemy->pos.x = x;
    new_enemy->pos.y = y;
    new_enemy->value = value;
    new_enemy->next = NULL;
    new_enemy->clock = sfClock_create();
    new_enemy->radius = 5;
    new_enemy->move_type = 4;
    new_enemy->anim = 'a';
    new_enemy->rect.height = 16;
    new_enemy->rect.width = 16;
    new_enemy->rect.top = 16;
    new_enemy->rect.left = 16;
}

void add_enemies_to_list(int map, int value, int x, int y)
{
    enemies *new_enemy = malloc(sizeof(enemies));
    add_enemies_to_list_next(new_enemy, value, x, y);
    new_enemy->og_x = (new_enemy->pos.x / SIZE_TILE);
    new_enemy->og_y = (new_enemy->pos.y / SIZE_TILE);
    if (all_maps()[map].all_ennemis == NULL) {
        all_maps()[map].all_ennemis = new_enemy;
        return;
    }
    enemies *last = all_maps()[map].all_ennemis;
    while (last->next != NULL)
        last = last->next;
    last->next = new_enemy;
}

void add_npcs_to_list(int map, int value, int x, int y);

void explore_map_find_all_ennemis_next(int map, int i, int j)
{
    char *c = &all_maps()[map].fg[i][j];
    if ((*c) >= '0')
        return;
    if (c[0] == 47)
        add_enemies_to_list(map, DEMON, j * SIZE_TILE, (i * SIZE_TILE) + 16);
    else if (c[0] == 46)
        add_enemies_to_list(map, NINJA, j * SIZE_TILE, (i * SIZE_TILE) + 16);
    if (map == 0 && (c[0] == 47 || c[0] == 46))
        all_infos()->nb_of_enemies_outside++;
    // if (c[0] == '-')
    //     add_npcs_to_list(map, NPC, j * SIZE_TILE, (i * SIZE_TILE) + 16);
    // if (c[0] == ',')
    //     add_npcs_to_list(map, NPC2, j * SIZE_TILE, (i * SIZE_TILE) + 16);
    // (*c) = 'R';
}

void explore_map_find_all_ennemis(int map)
{
    all_maps()[map].all_ennemis = NULL;
    for (int i = 0; all_maps()[map].fg[i]; i++)
        for (int j = 0; all_maps()[map].fg[i][j]; j++)
            explore_map_find_all_ennemis_next(map, i, j);
}

void display_all_enemies(void)
{
    enemies *expl = all_maps()[all_infos()->map_actual].all_ennemis;
    while (expl) {
        sfSprite_setPosition(all_sprites()[expl->value].sprite, expl->pos);
        sfRenderWindow_drawSprite(all_infos()->window,
        all_sprites()[expl->value].sprite, NULL);
        expl = expl->next;
    }
}
