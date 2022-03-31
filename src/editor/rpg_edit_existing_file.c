/*
** EPITECH PROJECT, 2022
** edit_existing_file
** File description:
** edit_existing_file
*/

#include "my.h"
#include "rpg_header.h"

void edit_existing_file (char *filepath_dir)
{
    all_infos()->level = MAP_EDITOR;
    char *filepath = malloc(sizeof(char) * BUFF_SIZE);
    my_memset(filepath, 511, '\0');
    my_strcpy(filepath, filepath_dir);
    my_strcat(filepath, "/bg");
    int size = my_strlen(filepath);
    all_editor()->map_bg = filepath_to_arr(filepath);
    filepath[size - 3] = '\0';
    my_strcat(filepath, "/mg");
    all_editor()->map_mg = filepath_to_arr(filepath);
    filepath[size - 3] = '\0';
    my_strcat(filepath, "/fg");
    all_editor()->map_fg = filepath_to_arr(filepath);
    free(filepath);
    if (!all_editor()->map_bg || !all_editor()->map_mg || !all_editor()->map_fg)
        exit(84);
    all_editor()->dir_save = filepath_dir;
    sfView_setCenter(all_infos()->view, (sfVector2f) {960, 540});
    sfView_setSize(all_infos()->view, (sfVector2f) {1920, 1080});
    sfRenderWindow_setView(all_infos()->window, all_infos()->view);
}

// resize après chargée
