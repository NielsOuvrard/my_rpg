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

int is_onlynb(char *nb)
{
    int i = 0;
    if (nb == NULL)
        return 0;
    while (nb[i] != '\0' || nb[i] != '\n') {
        if (nb[i] < '0' || nb[i] > '9')
            return 0;
        i++;
    }
    return 1;
}
