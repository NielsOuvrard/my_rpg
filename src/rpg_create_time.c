/*
** EPITECH PROJECT, 2021
** game file 1
** File description:
** lib csfml
*/

#include "my.h"
#include "rpg_header.h"

static times_clock *time;

void full_time (void)
{
    times_clock *time = malloc(sizeof(times_clock) * 4);
    for (int i = 0; i < 4; i++) {
        time->clock = sfClock_create();
        time->ok = false;
    }
}

times_clock *all_time (void)
{
    return time;
}
