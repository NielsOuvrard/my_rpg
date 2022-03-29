/*
** EPITECH PROJECT, 2022
** snake_no_map.c
** File description:
** snake level 0
*/

#include "my.h"
#include "rpg_header.h"

void level_map_editor_event(sfEvent event)
{
    while (sfRenderWindow_pollEvent(all_infos()->window, &event)) {
        if (event.type == sfEvtClosed) {
            all_infos()->quit_main = 1;
            return;
        }
        if (sfKeyboard_isKeyPressed(sfKeyP) && all_infos()->map_editor) {
            my_show_word_array(all_infos()->map_editor);
            free_my_arr(all_infos()->map_editor);
            all_infos()->map_editor = NULL;
        }
        la_bonne_touche_editor(event);
        le_bon_click_editor(event);
        if (all_infos()->map_editor)
            modify_var_move(event);
        else
            change_map_size(event);
    }
}
// pb avec dernier char des str du char **

// 0 fichier = default
// si param, modif map existante

void disp_tile_editor(int i, int j, int type)
{
    all_sprites()[type].pos.x = all_infos()->pos_player.x +
    (all_sprites()[type].scale.x * 100) * all_infos()->zoom * j;
    all_sprites()[type].pos.y = all_infos()->pos_player.y +
    (all_sprites()[type].scale.x * 100) * all_infos()->zoom * i;
    sfSprite_setPosition(all_sprites()[type].sprite, all_sprites()[type].pos);
    sfRenderWindow_drawSprite(all_infos()->window,
    all_sprites()[type].sprite, NULL);
}

void disp_map_editor_next(int i, int j)
{
    if (all_infos()->map_editor[i][j] == 'g') {
        disp_tile_editor(i, j, GRASS);
    } else if (all_infos()->map_editor[i][j] == 's') {
        disp_tile_editor(i, j, SAND);
    }
    if (all_infos()->map_editor[i][j] == 'w') {
        disp_tile_editor(i, j, WATHER);
    } else if (all_infos()->map_editor[i][j] == 'd') {
        disp_tile_editor(i, j, DIRT);
    }
}

void disp_map_editor(void)
{
    for (int i = 0; all_infos()->map_editor[i]; i++)
        for (int j = 0; all_infos()->map_editor[i][j]; j++)
            disp_map_editor_next(i, j);
}

void disp_value_to_print_next(int type)
{
    sfSprite_setPosition(all_sprites()[type].sprite, (sfVector2f){0, 0});
    sfRenderWindow_drawSprite(all_infos()->window,
    all_sprites()[type].sprite, NULL);
}

void disp_value_to_print(void)
{
    if (all_infos()->value_to_print == 'g') {
        disp_value_to_print_next(GRASS);
    } else if (all_infos()->value_to_print == 's') {
        disp_value_to_print_next(SAND);
    }
    if (all_infos()->value_to_print == 'w') {
        disp_value_to_print_next(WATHER);
    } else if (all_infos()->value_to_print == 'd') {
        disp_value_to_print_next(DIRT);
    }
}

void level_map_editor_clock(sfEvent event)
{
    if (all_infos()->move && !(all_infos()->clock_val % 2)) {
        move_pos_player();
    }
}

void level_map_editor(sfEvent event)
{
    level_map_editor_event(event);
    if (all_infos()->map_editor)
        disp_map_editor();
    disp_value_to_print();
}
