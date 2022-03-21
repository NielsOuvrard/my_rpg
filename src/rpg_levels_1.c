/*
** EPITECH PROJECT, 2022
** snake_no_map.c
** File description:
** snake level 0
*/

#include "my.h"
#include "rpg_header.h"

void anim_perso (void)
{
    if (all_sprites()[GHOST].anim) {
        all_sprites()[GHOST].rect.left -= 16;
        all_sprites()[GHOST].anim = false;
    } else {
        all_sprites()[GHOST].rect.left += 16;
        all_sprites()[GHOST].anim = true;
    }
    sfSprite_setTextureRect(all_sprites()[GHOST].sprite, all_sprites()[GHOST].rect);
}

void move_perso (sfEvent event)
{
    if (event.key.code == sfKeyUp) {
        if (!all_sprites()[GHOST].anim)
            all_sprites()[GHOST].rect.left = 4 * 16;
        else
            all_sprites()[GHOST].rect.left = 5 * 16;
        sfSprite_setTextureRect(all_sprites()[GHOST].sprite, all_sprites()[GHOST].rect);
        all_infos()->pos_player.y += 10;
    }
    if (event.key.code == sfKeyLeft) {
        if (!all_sprites()[GHOST].anim)
            all_sprites()[GHOST].rect.left = 2 * 16;
        else
            all_sprites()[GHOST].rect.left = 3 * 16;
        sfSprite_setTextureRect(all_sprites()[GHOST].sprite, all_sprites()[GHOST].rect);
        all_infos()->pos_player.x += 10;
    }
    if (event.key.code == sfKeyDown) {
        if (!all_sprites()[GHOST].anim)
            all_sprites()[GHOST].rect.left = 6 * 16;
        else
            all_sprites()[GHOST].rect.left = 7 * 16;
        sfSprite_setTextureRect(all_sprites()[GHOST].sprite, all_sprites()[GHOST].rect);
        all_infos()->pos_player.y -= 10;
    }
    if (event.key.code == sfKeyRight) {
        if (!all_sprites()[GHOST].anim)
            all_sprites()[GHOST].rect.left = 0;
        else
            all_sprites()[GHOST].rect.left = 16;
        sfSprite_setTextureRect(all_sprites()[GHOST].sprite, all_sprites()[GHOST].rect);
        all_infos()->pos_player.x -= 10;
    }
}

void change_scale (sfEvent event)
{
    if (event.key.code == sfKeyA) {
        all_infos()->zoom += 0.01;
        all_sprites()[GROUND].scale.x += 0.01;
        all_sprites()[GROUND].scale.y += 0.01;
        sfSprite_setScale(all_sprites()[GROUND].sprite, all_sprites()[GROUND].scale);
        all_sprites()[4].scale.x += 0.01;
        all_sprites()[4].scale.y += 0.01;
        sfSprite_setScale(all_sprites()[4].sprite, all_sprites()[4].scale);
        all_sprites()[6].scale.x += 0.01;
        all_sprites()[6].scale.y += 0.01;
        sfSprite_setScale(all_sprites()[6].sprite, all_sprites()[6].scale);
        all_sprites()[7].scale.x += 0.01;
        all_sprites()[7].scale.y += 0.01;
        sfSprite_setScale(all_sprites()[7].sprite, all_sprites()[7].scale);
    }
    if (event.key.code == sfKeyE) { //  sfKeyboard_isKeyPressed()
        all_infos()->zoom -= 0.01;
        all_sprites()[GROUND].scale.x -= 0.01;
        all_sprites()[GROUND].scale.y -= 0.01;
        sfSprite_setScale(all_sprites()[GROUND].sprite, all_sprites()[GROUND].scale);
        all_sprites()[4].scale.x -= 0.01;
        all_sprites()[4].scale.y -= 0.01;
        sfSprite_setScale(all_sprites()[4].sprite, all_sprites()[4].scale);
        all_sprites()[6].scale.x -= 0.01;
        all_sprites()[6].scale.y -= 0.01;
        sfSprite_setScale(all_sprites()[6].sprite, all_sprites()[6].scale);
        all_sprites()[7].scale.x -= 0.01;
        all_sprites()[7].scale.y -= 0.01;
        sfSprite_setScale(all_sprites()[7].sprite, all_sprites()[7].scale);
    }
}

void event_level_1 (sfEvent event)
{
    while (sfRenderWindow_pollEvent(all_infos()->window, &event)) {
        if (event.type == sfEvtClosed) {
            all_infos()->quit_main = 1;
            return;
        }
        if (event.type == sfEvtKeyPressed) {
            if (event.key.code == sfKeySpace)
                all_infos()->level = 0;
            change_scale(event);
            move_perso(event);
        }
    }
    return;
}

void disp_map_next (int i, int j)
{
    if (all_infos()->map[i][j] == 'g') {
        all_sprites()[GROUND].pos.x = all_infos()->pos_player.x + all_sprites()[GROUND].scale.x * 100 * all_infos()->zoom * j;
        all_sprites()[GROUND].pos.y = all_infos()->pos_player.y + all_sprites()[GROUND].scale.x * 100 * all_infos()->zoom * i;
        sfSprite_setPosition(all_sprites()[GROUND].sprite, all_sprites()[GROUND].pos);
        sfRenderWindow_drawSprite(all_infos()->window, all_sprites()[GROUND].sprite, NULL);
    } else if (all_infos()->map[i][j] == 's') {
        all_sprites()[4].pos.x = all_infos()->pos_player.x + all_sprites()[GROUND].scale.x * 100 * all_infos()->zoom * j;
        all_sprites()[4].pos.y = all_infos()->pos_player.y + all_sprites()[GROUND].scale.x * 100 * all_infos()->zoom * i;
        sfSprite_setPosition(all_sprites()[4].sprite, all_sprites()[4].pos);
        sfRenderWindow_drawSprite(all_infos()->window, all_sprites()[4].sprite, NULL);
    }
    if (all_infos()->map[i][j] == 'w') {
        all_sprites()[6].pos.x = all_infos()->pos_player.x + all_sprites()[GROUND].scale.x * 100 * all_infos()->zoom * j;
        all_sprites()[6].pos.y = all_infos()->pos_player.y + all_sprites()[GROUND].scale.x * 100 * all_infos()->zoom * i;
        sfSprite_setPosition(all_sprites()[6].sprite, all_sprites()[6].pos);
        sfRenderWindow_drawSprite(all_infos()->window, all_sprites()[6].sprite, NULL);
    } else if (all_infos()->map[i][j] == 'd') {
        all_sprites()[7].pos.x = all_infos()->pos_player.x + all_sprites()[GROUND].scale.x * 100 * all_infos()->zoom * j;
        all_sprites()[7].pos.y = all_infos()->pos_player.y + all_sprites()[GROUND].scale.x * 100 * all_infos()->zoom * i;
        sfSprite_setPosition(all_sprites()[7].sprite, all_sprites()[7].pos);
        sfRenderWindow_drawSprite(all_infos()->window, all_sprites()[7].sprite, NULL);
    }
}

void disp_map (void)
{
    for (int i = 0; all_infos()->map[i]; i++)
        for (int j = 0; all_infos()->map[i][j]; j++)
            disp_map_next(i, j);
}

void level_1 (sfEvent event)
{
    event_level_1(event);
    if (all_infos()->quit_main == 1) {
        return;
    }
    if (all_time()[0].ok) {
        anim_perso();
    }
    disp_map();
    sfRenderWindow_drawSprite(all_infos()->window, all_sprites()[GHOST].sprite, NULL);
    // sfRenderWindow_drawSprite(all_infos()->window, all_infos()->sprite_difficulty, NULL);
    return;
}
