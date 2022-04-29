/*
** EPITECH PROJECT, 2021
** game file 1
** File description:
** lib csfml
*/

#include "my.h"
#include "rpg_header.h"

static struct_keys *keyes;

struct_keys *all_keys(void)
{
    return keyes;
}

void create_keys(void)
{
    keyes = malloc(sizeof(struct_keys));
    keyes->k_down = sfKeyS;
    keyes->k_sprint = sfKeyLShift;
    keyes->k_up = sfKeyZ;
    keyes->k_left = sfKeyQ;
    keyes->k_right = sfKeyD;
    keyes->k_map = sfKeyTab;
    keyes->k_open_bag = sfKeyE;
    keyes->k_interact = sfKeyF;
    keyes->k_open_missions = sfKeyI;
    keyes->shoot = sfKeySpace;
    keyes->zoom_in = sfKeyUp;
    keyes->zoom_out = sfKeyDown;
    return;
}

void qwerty_keyes (void)
{
    keyes->k_up = sfKeyW;
    keyes->k_left = sfKeyA;
}
