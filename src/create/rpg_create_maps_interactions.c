/*
** EPITECH PROJECT, 2021
** game file 1
** File description:
** lib csfml
*/

#include "my.h"
#include "rpg_header.h"

struct_interact *interactions_of_map_next (char *str, struct_maps autr,
struct_interact *ptr_inte)
{
    ptr_inte->x = my_getnbr(str);
    while (my_isdidgit(str[0]))
        str++;
    str++;
    ptr_inte->a_y = my_getnbr(str);
    while (my_isdidgit(str[0]))
        str++;
    str++;
    ptr_inte->a_x = my_getnbr(str);
    ptr_inte->next = autr.interact;
    return ptr_inte;
}

struct_interact *interactions_of_map (char *str, struct_maps autr)
{
    struct_interact *ptr_inte = malloc(sizeof(struct_interact));
    ptr_inte->next = NULL;
    ptr_inte->type = my_getnbr(str);
    while (my_isdidgit(str[0]))
        str++;
    str++;
    ptr_inte->data = my_getnbr(str);
    while (my_isdidgit(str[0]))
        str++;
    str++;
    ptr_inte->y = my_getnbr(str);
    while (my_isdidgit(str[0]))
        str++;
    str++;
    return interactions_of_map_next(str, autr, ptr_inte);
}
