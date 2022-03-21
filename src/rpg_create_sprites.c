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
    value[GROUND].scale.x = 50;
    value[GROUND].scale.y = 50;
    // value[GROUND].
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
