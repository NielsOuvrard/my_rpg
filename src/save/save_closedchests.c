/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-myrpg-niels.ouvrard
** File description:
** save_closedchests
*/

#include "my.h"
#include "rpg_header.h"

void save_opened_chests(FILE *fd)
{
    char **arr = filepath_to_arr("map/list_maps.txt");
    int nb_of_maps = my_arraylen(arr);
    fwrite("\n#closed_chests\n", 1, my_strlen("\n#closed_chests\n"), fd);
    for (int i = 0; i != nb_of_maps; i++) {
        write_opened_chests(fd, i);
    }
}

void write_opened_chests(FILE *fd, int map_nb)
{
    int y = 0, x = 0;
    while (all_maps()[map_nb].mg[y]) {
        while (all_maps()[map_nb].mg[y][x]) {
            check_openedchests(fd, map_nb, x, y);
            x++;
        }
        x = 0;
        y++;
    }
}

void check_openedchests(FILE *fd, int map_nb, int x, int y)
{
    char *text = malloc(sizeof(char) * 10);
    text = my_strcpy(text, my_itoa(map_nb));
    text = my_strcat(text, " ");
    text = my_strcat(text, my_itoa(y));
    text = my_strcat(text, " ");
    text = my_strcat(text, my_itoa(x));
    if (all_maps()[map_nb].mg[y][x] == 'Q') {
        fwrite(text, 1, my_strlen(text), fd);
        fwrite("\n", 1, 1, fd);
    }
}
