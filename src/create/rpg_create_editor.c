/*
** EPITECH PROJECT, 2021
** game file 1
** File description:
** lib csfml
*/

#include "my.h"
#include "rpg_header.h"

static editor_screen *edito;

editor_screen *all_editor (void)
{
    return edito;
}

char **editor_create_map (int x, int y)
{
    char **map = malloc(sizeof(char *) * (y + 1));
    for (int i = 0; i < y; i++) {
        map[i] = malloc(sizeof(char) * (x + 1));
        my_memset(map[i], x, edito->value_to_print);
        map[i][x] = '\0';
    }
    map[y] = NULL;
    return map;
}

void initialize_editor_vals(void)
{
    sfText_setFont(edito->editor_text, edito->font);
    sfText_setColor(edito->editor_text, sfWhite);
    sfText_setCharacterSize(edito->editor_text, 60);
    // sfText_setString(edito->editor_text, "str");
    // sfText_setPosition(edito->editor_text, (sfVector2f){50, 0});
}

void creat_editor (void)
{
    edito = malloc(sizeof(editor_screen));
    //text
    edito->editor_text = sfText_create();
    edito->font = sfFont_createFromFile("font/coolvetica_rg.ttf");
    // editor
    edito->map_editor = NULL;
    edito->value_to_print = 'w';
    edito->size_edit.x = 30;
    edito->size_edit.y = 30;
    edito->is_writing = false;

    edito->edit_ground = 'b';
    edito->v_bg = true;
    edito->v_mg = false;
    edito->v_fg = false;

    initialize_editor_vals();
    return;
}
