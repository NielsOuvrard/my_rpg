/*
** EPITECH PROJECT, 2021
** game file 1
** File description:
** lib csfml
*/

#include "my.h"
#include "rpg_header.h"

static struct_maps *my_maps;

void full_list_maps(void)
{
    char **arr = filepath_to_arr("map/list_maps.txt");
    int nbr = my_arraylen(arr), i;
    my_maps = malloc(sizeof(struct_maps) * (nbr + 1));
    char *filepath = malloc(sizeof(char) * 512);
    for (i = 0; arr[i]; i++) {
        my_memset(filepath, 511, '\0');
        my_strcpy(filepath, "map/");
        my_strcat(filepath, arr[i]);
        my_strcat(filepath, "bg");
        int size = my_strlen(filepath);
        my_maps[i].bg = filepath_to_arr(filepath);
        filepath[size - 2] = '\0';
        my_strcat(filepath, "mg");
        my_maps[i].mg = filepath_to_arr(filepath);
        filepath[size - 2] = '\0';
        my_strcat(filepath, "fg");
        my_maps[i].fg = filepath_to_arr(filepath);
        explor_map_find_all_ennemis(i);
    }
    free_my_arr(arr);
}

struct_maps *all_maps(void)
{
    return my_maps;
}
