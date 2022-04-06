/*
** EPITECH PROJECT, 2022
** rpg_tools_1.c
** File description:
** tools rpg
*/

#include "my.h"
#include "rpg_header.h"

int random_int (int min, int max)
{
    int retour = min + (rand() % ((max + 1)));
    return retour;
}
