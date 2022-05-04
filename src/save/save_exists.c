/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-myrpg-niels.ouvrard
** File description:
** save_exists
*/

#include "my.h"
#include "rpg_header.h"

int does_save_exists(void)
{
    FILE *fd = fopen("save.txt", "r");
    if (fd == NULL)
        return 0;
    get_info_save();
}

void get_info_save(void)
{
    FILE *fd = fopen("save.txt", "r");
    char *line = NULL;
    int type = 0, run = 1;
    size_t len;
    char *buf = NULL;
    sfVector2f pos;
    while (getline(&line, &len, fd) != -1) {
        if (my_strstr(line, "#player_pos")) {
            type = 1;
            continue;
        }
        if (my_strstr(line, "#view_info")) {
            type = 2;
            run = 1;
            continue;
        }
        if (my_strstr(line, "#map_actual")) {
            type = 3;
            run = 1;
            continue;
        }
        if (my_strstr(line, "#inventory")) {
            type = 4;
            run = 1;
            continue;
        }
        handle_map_actual(&type, line);
        handle_player_pos(line, &type, run);
        pos = handle_view_pos(line, &type, run, pos);
        handle_inventory(line, &type);
        run++;
    }
}

void handle_inventory(char *buffer, int *type)
{
    int nb = 0;
    if (*type != 4)
        return;
    add_to_inventory(&all_infos()->inventory, my_getnbr(buffer));
    return;
}

void handle_player_pos(char *buffer, int *type, int run)
{
    if (*type != 1)
        return;
    if (run == 1) {
        int x = my_getnbr(buffer);
        all_sprites()[HUNTER].pos.x = x;
    } else {
        int y = my_getnbr(buffer);
        all_sprites()[HUNTER].pos.y = y;
        sfSprite_setPosition(all_sprites()[HUNTER].sprite,
        all_sprites()[HUNTER].pos);
        *type = 0;
    }
    return;
}

sfVector2f handle_view_pos(char *buffer, int *type, int run, sfVector2f pos)
{
    if (*type != 2)
        return pos;
    if (run == 1) {
        int x = my_getnbr(buffer);
        pos.x = x;
    } else {
        int y = my_getnbr(buffer);
        pos.y = y;
        sfView_setCenter(all_infos()->view, pos);
        *type = 0;
    }
    return pos;
}

void handle_map_actual(int *type, char *buffer)
{
    if (*type != 3)
        return;
    all_infos()->map_actual = my_getnbr(buffer);
    *type = 0;
    return;
}
