/*
** EPITECH PROJECT, 2022
** snake_tools_1.c
** File description:
** tools snake
*/

#include "my.h"
#include "rpg_header.h"

int random_int (int min, int max)
{
    int retour = min + (rand() % ((max + 1)));
    return retour;
}
