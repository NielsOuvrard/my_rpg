/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-myrpg-niels.ouvrard
** File description:
** write_to_file2
*/

#include "my.h"
#include "rpg_header.h"

void save_healthpoints(FILE *fd)
{
    fwrite("#health\n", 1, my_strlen("#health\n"), fd);
    fwrite(my_itoa(all_infos()->life), 1, my_strlen(my_itoa(all_infos()->life)), fd);
    return;
}

void save_healthsize(FILE *fd)
{
    fwrite("#health_size\n", 1, my_strlen("#health_size\n"), fd);
    fwrite(my_itoa(all_infos()->life_size), 1,
    my_strlen(my_itoa(all_infos()->life_size)), fd);
}
