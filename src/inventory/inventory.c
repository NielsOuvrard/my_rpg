/*
** EPITECH PROJECT, 2022
** snake_no_map.c
** File description:
** snake level 0
*/

#include "my.h"
#include "rpg_header.h"

int nmb_inv(void)
{
    struct_inventory *val = all_infos()->inventory;
    int i = 0;
    while (val) {
        val = val->next;
        i++;
    }
    return i;
}

// sfSprite_setPosition(all_sprites()[EMPTY_BOX].sprite, (sfVector2f){1920 / 4, 1080 / 3});
// sfRenderWindow_drawSprite(all_infos()->window, all_sprites()[EMPTY_BOX].sprite, NULL);
void disp_inventory (void)
{
    struct_inventory *val = all_infos()->inventory;
    all_sprites()[EMPTY_BOX].scale.x = 3.125;
    all_sprites()[EMPTY_BOX].scale.y = 3.125;
    sfSprite_setScale(all_sprites()[EMPTY_BOX].sprite,
    all_sprites()[EMPTY_BOX].scale);
    int size = nmb_inv(), nmb_y = 0, i = 0;
    while (size >= 10) {
        nmb_y++;
        size -= 10;
    }
    while (val) {
        int x = i++, y = 0;
        while (x >= 10)
            my_printf("", y++, x -= 10);
        sfSprite_setPosition(all_sprites()[EMPTY_BOX].sprite,
        (sfVector2f) {(x * SIZE_TILE) + 50, (y * SIZE_TILE) + 250});
        sfRenderWindow_drawSprite(all_infos()->window,
        all_sprites()[EMPTY_BOX].sprite, NULL);
        val = val->next;
    }
}

// if (event.type == sfEvtKeyPressed)
//     event_level_1_pressed(event);
// if (event.type == sfEvtKeyReleased)
//     event_level_1_relased(event);
// modify_var_move(event);
void event_level_inventory(sfEvent event)
{
    while (sfRenderWindow_pollEvent(all_infos()->window, &event)) {
        if (event.type == sfEvtKeyPressed &&
        event.key.code == all_keys()->k_open_bag)
            all_infos()->level = GAME;
        if (event.type == sfEvtClosed) {
            all_infos()->quit_main = 1;
            return;
        }
    }
    return;
}

// my_printf("top : %d\tleft : %d\n", all_sprites()[HUNTER].rect.top,
// all_sprites()[HUNTER].rect.left);
// if (all_sprites()[BANANA].anim)
//     sfRenderWindow_drawSprite(all_infos()->window,
//     all_sprites()[BANANA].sprite, NULL);
void level_inventory(sfEvent event)
{
    event_level_inventory(event);
    if (all_infos()->quit_main == 1)
        return;
    disp_map(all_maps()[all_infos()->map_actual].bg);
    print_all_particules();
    disp_mg();
    disp_map(all_maps()[all_infos()->map_actual].fg);
    disp_all_npcs();
    disp_interaction_button();
    sfRenderWindow_setView(all_infos()->window, all_infos()->hud_view);
    display_hud();
    disp_inventory();
    sfRenderWindow_setView(all_infos()->window, all_infos()->view);
    return;
}
