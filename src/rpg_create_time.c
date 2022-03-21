/*
** EPITECH PROJECT, 2021
** game file 1
** File description:
** lib csfml
*/

#include "my.h"
#include "rpg_header.h"

static times_clock *time_static_val;

void full_time (void)
{
    time_static_val = malloc(sizeof(times_clock) * 4);
    for (int i = 0; i < 4; i++) {
        time_static_val[i].clock = sfClock_create();
        time_static_val[i].ok = false;
    }
}

times_clock *all_time (void)
{
    return time_static_val;
}
