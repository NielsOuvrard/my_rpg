/*
** EPITECH PROJECT, 2022
** snake_no_map.c
** File description:
** snake level 0
*/

#include "my.h"
#include "rpg_header.h"

char *get_filepath_with_filename (char *src, char *directories, char *file)
{
    my_memset(src, BUFF_SIZE - 1, '\0');
    my_strcpy(src, all_editor()->dir_save);
    my_strcat(src, file);
    return src;
}

void write_maps_mg_fg (char *str)
{
    int fd = open(get_filepath_with_filename(str,
    all_editor()->dir_save, "/mg"), O_CREAT | O_RDWR);
    if (!fd)
        return;
    for (int i = 0; all_editor()->map_mg[i]; i++) {
        for (int j = 0; all_editor()->map_mg[i][j]; j++)
            write(fd, &all_editor()->map_mg[i][j], 1);
        write(fd, "\n", 1);
    }
    close(fd);
    fd = open(get_filepath_with_filename(str,
    all_editor()->dir_save, "/fg"), O_CREAT | O_RDWR);
    if (!fd)
        return;
    for (int i = 0; all_editor()->map_fg[i]; i++) {
        for (int j = 0; all_editor()->map_fg[i][j]; j++)
            write(fd, &all_editor()->map_fg[i][j], 1);
        write(fd, "\n", 1);
    }
    close(fd);
}

void write_maps (void)
{
    char *str = malloc(sizeof(char) * BUFF_SIZE);
    int fd = open(get_filepath_with_filename(str,
    all_editor()->dir_save, "/bg"), O_CREAT | O_RDWR);
    if (!fd)
        return;
    for (int i = 0; all_editor()->map_bg[i]; i++) {
        for (int j = 0; all_editor()->map_bg[i][j]; j++)
            write(fd, &all_editor()->map_bg[i][j], 1);
        write(fd, "\n", 1);
    }
    close(fd);
    write_maps_mg_fg(str);
    free(str);
    my_printf("ecrit avec succes !\n");
}
