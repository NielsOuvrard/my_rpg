/*
** EPITECH PROJECT, 2022
** snake_tools_1.c
** File description:
** tools snake
*/

#include "my.h"
#include "rpg_header.h"

main_screen quit_game (main_screen my_main)
{
    my_main.quit_main = 1;
    return my_main;
}

int random_int (int min, int max)
{
    int retour = min + (rand() % ((max + 1) * 1000));
    retour /= 1000;
    return retour;
}

int error_args (void)
{
    my_putstr("/my_snake: bad arguments: 0 given but 1 is required\n");
    my_putstr("retry with -h\n");
    return 84;
}

int help (void)
{
    my_putstr("no\n");
    return 0;
}
