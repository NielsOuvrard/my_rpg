/*
** EPITECH PROJECT, 2021
** game file 1
** File description:
** lib csfml
*/

#include "my.h"
#include "rpg_header.h"

static sprite_pictures *sprite_dictionary;

void full_perso(int type, int x, int y);

void origin_in_8_8_scale(int sprite);

void full_list_sprites_next(void);

void create_sprite_picture(sprite_pictures *sprite_picture, char *filepath)
{
    sprite_picture->sprite = sfSprite_create();
    sprite_picture->texture = sfTexture_createFromFile(filepath, NULL);
    sfSprite_setTexture(sprite_picture->sprite, sprite_picture->texture, sfTrue);
    sprite_picture->scale.x = 1;
    sprite_picture->scale.y = 1;
}

void fill_sprite_dictionary(void)
{
    char **filepath_dictionary = filepath_to_arr("pictures/pictures.txt");
    int mem_size = my_arraylen(filepath_dictionary) + 1;
    sprite_dictionary = malloc(sizeof(sprite_pictures) * mem_size);
    for (int i = 0; filepath_dictionary[i]; i++) {
        create_sprite_picture(&sprite_dictionary[i], filepath_dictionary[i]);
    }
    full_list_sprites_next();
    free_my_arr(filepath_dictionary);
}

sprite_pictures *all_sprites(void)
{
    return sprite_dictionary;
}
