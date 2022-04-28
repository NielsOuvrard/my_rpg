/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** rpg_npc_list
*/

#include "my.h"
#include "rpg_header.h"

void add_npcs_to_list_next(npcs *new_npc, int value, int x, int y)
{
    new_npc->pos.x = x;
    new_npc->pos.y = y;
    new_npc->value = value;
    new_npc->next = NULL;
    new_npc->clock = sfClock_create();
    new_npc->radius = 5;
    new_npc->move_type = 4;
    new_npc->anim = 'a';
    new_npc->rect.height = 16;
    new_npc->rect.width = 16;
    new_npc->rect.top = 16;
    new_npc->rect.left = 16;
}

void add_npcs_to_list(int map, int value, int x, int y)
{
    npcs *new_npc = malloc(sizeof(npcs));
    add_npcs_to_list_next(new_npc, value, x, y);
    new_npc->og_x = (new_npc->pos.x / SIZE_TILE);
    new_npc->og_y = (new_npc->pos.y / SIZE_TILE);
    if (all_maps()[map].all_npcs == NULL) {
        all_maps()[map].all_npcs = new_npc;
        return;
    }
    npcs *last = all_maps()[map].all_npcs;
    while (last->next != NULL)
        last = last->next;
    last->next = new_npc;
}

void explore_map_find_all_npcs_next(int map, int i, int j)
{
    char *c = &all_maps()[map].fg[i][j];
    if ((*c) >= '0')
        return;
    if (c[0] == '-')
        add_npcs_to_list(map, NPC, j * SIZE_TILE, (i * SIZE_TILE) + 16);
    if (c[0] == ',')
        add_npcs_to_list(map, NPC2, j * SIZE_TILE, (i * SIZE_TILE) + 16);
    if (c[0] == '+')
        add_npcs_to_list(map, NPC3, j * SIZE_TILE, (i * SIZE_TILE) + 16);
    c[0] = 'R';
}

void explore_map_find_all_npcs(int map)
{
    all_maps()[map].all_npcs = NULL;
    for (int i = 0; all_maps()[map].fg[i]; i++)
        for (int j = 0; all_maps()[map].fg[i][j]; j++)
            explore_map_find_all_npcs_next(map, i, j);
}

void disp_all_npcs(void)
{
    npcs *expl = all_maps()[all_infos()->map_actual].all_npcs;
    while (expl) {
        sfSprite_setPosition(all_sprites()[expl->value].sprite, expl->pos);
        sfRenderWindow_drawSprite(all_infos()->window,
        all_sprites()[expl->value].sprite, NULL);
        expl = expl->next;
    }
}
