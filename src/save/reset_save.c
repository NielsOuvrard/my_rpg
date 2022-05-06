/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-myrpg-niels.ouvrard
** File description:
** reset_save
*/

#include "my.h"
#include "rpg_header.h"

void reset_save(void)
{
    FILE *fd = fopen("save.txt", "w+");
    fclose(fd);
    return;
}
