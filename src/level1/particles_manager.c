/*
** EPITECH PROJECT, 2022
** rpg_particules.c
** File description:
** rpg_particules.c
*/

#include "my.h"
#include "rpg_header.h"

void add_particules(sfVector2f pos, int size, sfColor color)
{
    struct_particule *p = all_infos()->particules;
    if (!p) {
        all_infos()->particules = malloc(sizeof(struct_particule));
        all_infos()->particules->pos = pos;
        all_infos()->particules->size = size;
        all_infos()->particules->color = color;
        all_infos()->particules->next = NULL;
        return;
    }
    while (p->next)
        p = p->next;
    struct_particule *new = malloc(sizeof(struct_particule));
    new->pos = pos;
    new->size = size;
    new->color = color;
    new->next = NULL;
    p->next = new;
}

void anim_all_particules_next (void)
{
    struct_particule *del_tmp = all_infos()->particules;
    while (del_tmp && del_tmp->next) {
        if (del_tmp->next->size < 1) {
            struct_particule *tmp = del_tmp->next;
            del_tmp->next = del_tmp->next->next;
            free(tmp);
        }
        del_tmp = del_tmp->next;
    }
}

void anim_all_particules (void)
{
    struct_particule *p = all_infos()->particules;
    struct_particule *del = all_infos()->particules;
    while (p) {
        p->size -= 1;
        p->pos.x += 5 - random_int(0, 10);
        p->pos.y += 2 - random_int(0, 10);
        p = p->next;
    }
    while (del && del->size < 1) {
        struct_particule *tmp = del;
        del = del->next;
        free(tmp);
    }
    all_infos()->particules = del;
    if (!del)
        return;
    anim_all_particules_next();
}

void find_tile_particle (char c, int i, int j)
{
    if (c == '0' || c == ']') {
        add_particules((sfVector2f){(j * (16 * SCALE_TILE_SHEET)) + 16,
        (i * (16 * SCALE_TILE_SHEET)) + 16}, 15,
        sfColor_fromRGBA(220, 0, 0, 120));
    }
    if (c == ']') {
        add_particules((sfVector2f){(j * (16 * SCALE_TILE_SHEET)) + 16,
        (i * (16 * SCALE_TILE_SHEET)) + 16}, 20,
        sfColor_fromRGBA(0, 0, 0, 80));
    }
}

void print_all_particules (void)
{
    struct_particule *p = all_infos()->particules;
    while (p) {
        sfRectangleShape *rectan = sfRectangleShape_create();
        sfRectangleShape_setFillColor(rectan, p->color);
        sfRectangleShape_setPosition(rectan, p->pos);
        sfRectangleShape_setSize(rectan, (sfVector2f){p->size, p->size});
        sfRenderWindow_drawRectangleShape(all_infos()->window, rectan, NULL);
        sfRectangleShape_destroy(rectan);
        p = p->next;
    }
}
