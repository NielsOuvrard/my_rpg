/*
** EPITECH PROJECT, 2021
** game file 1
** File description:
** lib csfml
*/

#include "my.h"
#include "rpg_header.h"

static sprite_pictures *value;

void full_list_sprites_next (void)
{
    value[GROUND].scale.x = 0.50;
    value[GROUND].scale.y = 0.50;
    sfSprite_setScale(value[GROUND].sprite, value[GROUND].scale);
    value[4].scale.x = 0.50;
    value[4].scale.y = 0.50;
    sfSprite_setScale(value[4].sprite, value[4].scale);
    value[6].scale.x = 0.50;
    value[6].scale.y = 0.50;
    sfSprite_setScale(value[6].sprite, value[6].scale);
    value[7].scale.x = 0.50;
    value[7].scale.y = 0.50;
    sfSprite_setScale(value[7].sprite, value[7].scale);

    value[GHOST].scale.x = 2.50;
    value[GHOST].scale.y = 2.50;
    sfSprite_setScale(value[GHOST].sprite, value[GHOST].scale);
    value[GHOST].pos.y = 1080 / 2;
    value[GHOST].pos.x = 1920 / 2;
    value[GHOST].anim = false;
    sfSprite_setPosition(value[GHOST].sprite, value[GHOST].pos);
    value[GHOST].rect.top = (16 * random_int(0, 3));
    value[GHOST].rect.left = 0;
    value[GHOST].rect.width = 15;
    value[GHOST].rect.height = 15;
    sfSprite_setTextureRect(value[GHOST].sprite, value[GHOST].rect);
}

void full_list_sprites (void)
{
    char **arr = filepath_to_arr("pictures/pictures.txt");
    int nbr = my_arraylen(arr), i;
    value = malloc(sizeof(sprite_pictures) * (nbr + 1));
    for (i = 0; arr[i]; i++) {
        value[i].sprite = sfSprite_create();
        value[i].texture = sfTexture_createFromFile(arr[i], NULL);
        sfSprite_setTexture(value[i].sprite, value[i].texture, sfTrue);
        value[i].rect.height = 0;
        value[i].rect.top = 0;
        value[i].rect.left = 0;
        value[i].rect.width = 0;
        value[i].scale.x = 1;
        value[i].scale.y = 1;
        value[i].origin.x = 0;
        value[i].origin.y = 0;
        value[i].pos.x = 0;
        value[i].pos.x = 0;
    }
    full_list_sprites_next();
}

sprite_pictures *all_sprites (void)
{
    return value;
}
