/*
** EPITECH PROJECT, 2021
** main
** File description:
** main du hunter
*/

#include "my.h"
#include "rpg_header.h"

int main (int ac, char **av)
{
    if (ac == 2 && !my_strcmp(av[1], "-h"))
        return help();
    return all_levels_game(av[1]);
}
