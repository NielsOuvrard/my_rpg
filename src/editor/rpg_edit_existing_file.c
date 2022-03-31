/*
** EPITECH PROJECT, 2022
** edit_existing_file
** File description:
** edit_existing_file
*/

#include "my.h"
#include "rpg_header.h"

void full_my_maps (char **map, char **map2)
{
    for (int i = 0; map2[i]; i++) {
        my_strcpy(map[i], map2[i]);
    }
}

void edit_existing_file (char *filepath_dir)
{
    all_infos()->level = MAP_EDITOR;
    char *filepath = malloc(sizeof(char) * BUFF_SIZE);
    my_memset(filepath, 511, '\0');
    my_strcpy(filepath, filepath_dir);
    my_strcat(filepath, "/bg");
    int size = my_strlen(filepath);
    char **bg = filepath_to_arr(filepath);
    filepath[size - 3] = '\0';
    my_strcat(filepath, "/mg");
    char **mg = filepath_to_arr(filepath);
    filepath[size - 3] = '\0';
    my_strcat(filepath, "/fg");
    char **fg = filepath_to_arr(filepath);
    free(filepath);
    if (!bg || !mg || !fg)
        exit(84);
    int size_y_map = my_arraylen(bg);
    all_editor()->map_bg = editor_create_map(0, size_y_map, '\0');
    all_editor()->map_mg = editor_create_map(0, size_y_map, '\0');
    all_editor()->map_fg = editor_create_map(0, size_y_map, '\0');
    full_my_maps(all_editor()->map_bg, bg);
    full_my_maps(all_editor()->map_mg, mg);
    full_my_maps(all_editor()->map_fg, fg);
    free_my_arr(bg);
    free_my_arr(mg);
    free_my_arr(fg);
    all_editor()->dir_save = filepath_dir;
    sfView_setCenter(all_infos()->view, (sfVector2f) {960, 540});
    sfView_setSize(all_infos()->view, (sfVector2f) {1920, 1080});
    sfRenderWindow_setView(all_infos()->window, all_infos()->view);
}
