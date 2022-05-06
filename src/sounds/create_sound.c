/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-myrpg-niels.ouvrard
** File description:
** create_sound
*/

#include "my.h"
#include "rpg_header.h"

sfSound *create_sound(char *path)
{
    sfSound *my_sound = sfSound_create();
    sfSound_setBuffer(my_sound, sfSoundBuffer_createFromFile(path));
    return my_sound;
}
