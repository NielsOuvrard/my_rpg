/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-myrpg-niels.ouvrard
** File description:
** write_to_file
*/

#include "my.h"
#include "rpg_header.h"

void write_infos_to_file(void)
{
    FILE *fd = fopen("save.txt", "w+");
    save_position_to_file(fd);
    save_view_to_file(fd);
    save_map_actual(fd);
    save_inventory_to_file(fd);
    save_quests(fd);
    save_quests_id(fd);
    save_opened_chests(fd);
}

void save_map_actual(FILE *fd)
{
    fwrite("#map_actual\n", 1, my_strlen("#map_actual\n"), fd);
    char *map_actual = my_itoa(all_infos()->map_actual);
    fwrite(map_actual, 1, my_strlen(map_actual), fd);
    fwrite("\n", 1, 1, fd);
}

void save_position_to_file(FILE *fd)
{
    int tmp_x = (int)all_sprites()[HUNTER].pos.x, tmp_y = (int)all_sprites()[HUNTER].pos.y;
    char *x = my_itoa(tmp_x);
    char *y = my_itoa(tmp_y);
    fwrite("#player_pos\n", 1, my_strlen("#player_pos\n"), fd);
    fwrite(x, 1, my_strlen(x), fd);
    fwrite("\n", 1, 1, fd);
    fwrite(y, 1, my_strlen(y), fd);
    fwrite("\n", 1, 1, fd);
}

void save_view_to_file(FILE *fd)
{
    fwrite("#view_info\n", 1, my_strlen("#view_info\n"), fd);
    sfVector2f pos = sfView_getCenter(all_infos()->view);
    char *x = my_itoa(pos.x);
    char *y = my_itoa(pos.y);
    fwrite(x, 1, my_strlen(x), fd);
    fwrite("\n", 1, 1, fd);
    fwrite(y, 1, my_strlen(y), fd);
    fwrite("\n", 1, 1, fd);
}

void save_inventory_to_file(FILE *fd)
{
    fwrite("#inventory\n", 1, my_strlen("#inventory\n"), fd);
    struct_inventory *inv = all_infos()->inventory;
    char *obj;
    int run = 0;
    for (;inv; inv = inv->next) {
        if (inv->object != BANANA && inv->object != APPLE)
            continue;
        run ++;
        obj = my_itoa(inv->object);
        fwrite(obj, 1, my_strlen(obj), fd);
        if (inv->next != NULL)
            fwrite("\n", 1, 1, fd);
    }
    if (run != 0)
        fwrite("\n", 1, 1, fd);
}