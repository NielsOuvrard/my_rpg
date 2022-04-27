/*
** EPITECH PROJECT, 2022
** snake_no_map.c
** File description:
** snake level 0
*/

#include "my.h"
#include "rpg_header.h"

void free_map (int i)
{
    free_my_arr(all_maps()[i].bg);
    free_my_arr(all_maps()[i].mg);
    free_my_arr(all_maps()[i].fg);
}

void free_particules (void)
{
    struct_particule *p = all_infos()->particules;
    while (p) {
        struct_particule *tmp = p;
        p = p->next;
        free(tmp);
    }
}
