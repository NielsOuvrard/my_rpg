/*
** EPITECH PROJECT, 2021
** game file 1
** File description:
** lib csfml
*/

#include "my.h"
#include "rpg_header.h"

static main_screen *infos;

main_screen *all_infos (void)
{
    return infos;
}

char **editor_create_map (int x, int y)
{
    char **map = malloc(sizeof(char *) * (y + 1));
    for (int i = 0; i < y; i++) {
        map[i] = malloc(sizeof(char) * (x + 1));
        my_memset(map[i], x, all_infos()->value_to_print);
        map[i][x] = '\0';
    }
    map[y] = NULL;
    return map;
}

void initialize_main_vals(void)
{
    sfView_setCenter(infos->view, (sfVector2f) {960, 540});
    sfView_setSize(infos->view, (sfVector2f) {1920, 1080});
    sfRenderWindow_setView(infos->window, infos->view);

    sfText_setFont(infos->editor_text, infos->font);
    sfText_setColor(infos->editor_text, sfWhite);
    sfText_setCharacterSize(infos->editor_text, 60);
    // sfText_setString(infos->editor_text, "str");
    // sfText_setPosition(infos->editor_text, (sfVector2f){50, 0});
}

void creat_main (void)
{
    infos = malloc(sizeof(main_screen));
    sfVideoMode mode = {SCREEN_MAX_X, SCREEN_MAX_Y, 60};
    infos->window = sfRenderWindow_create(mode, "RPG",
    sfResize | sfClose, NULL);
    infos->level = 0;
    infos->quit_main = 0;
    infos->score = 0;
    infos->map = filepath_to_arr("map/map1.txt");
    infos->pos_player.x = 0;
    infos->pos_player.y = 0;
    infos->zoom = 1;
    infos->move = '\0';
    infos->clock = sfClock_create();
    infos->clock_val = 0;
    infos->clock_bool = true;
    //text
    infos->editor_text = sfText_create();
    infos->font = sfFont_createFromFile("font/coolvetica_rg.ttf");
    // editor
    infos->map_editor = NULL;
    infos->value_to_print = 'w';
    infos->size_edit.x = 30;
    infos->size_edit.y = 30;
    infos->is_writing = false;


    infos->view_position.x = 960;
    infos->view_position.y = 540;
    infos->view = sfView_create();
    initialize_main_vals();
    return;
}
