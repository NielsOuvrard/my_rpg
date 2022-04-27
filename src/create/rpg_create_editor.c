/*
** EPITECH PROJECT, 2021
** game file 1
** File description:
** lib csfml
*/

#include "my.h"
#include "rpg_header.h"

static editor_screen *editor;

editor_screen *all_editor(void)
{
    return editor;
}

char **editor_create_map(int x, int y, char c)
{
    char **map = malloc(sizeof(char *) * BUFF_SIZE);
    for (int i = 0; i < BUFF_SIZE; i++)
        map[i] = NULL;
    for (int i = 0; i < y; i++) {
        map[i] = malloc(sizeof(char) * BUFF_SIZE);
        my_memset(map[i], BUFF_SIZE - 1, '\0');
        my_memset(map[i], x, c);
    }
    return map;
}

void initialize_editor_vals(void)
{
    sfText_setFont(editor->editor_text, editor->font);
    sfText_setColor(editor->editor_text, sfWhite);
    sfText_setCharacterSize(editor->editor_text, 60);
}

void create_editor(void)
{
    editor = malloc(sizeof(editor_screen));
    editor->editor_text = sfText_create();
    editor->font = sfFont_createFromFile("font/coolvetica_rg.ttf");
    editor->map_bg = NULL;
    editor->map_mg = NULL;
    editor->map_fg = NULL;
    editor->value_to_print = '7';
    editor->size_edit.x = 30;
    editor->size_edit.y = 30;
    editor->is_writing = false;
    editor->dir_save = "map/MAP_EDIT";
    editor->edit_ground = 'b';
    editor->ptr_map_edit = NULL;
    editor->v_bg = true;
    editor->v_mg = true;
    editor->v_fg = true;
    initialize_editor_vals();
    return;
}
